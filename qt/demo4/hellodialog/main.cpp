#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QColorDialog>
#include <QErrorMessage>
#include <QInputDialog>
#include <QFontDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QProgressDialog>
#include <QWizard>
#include <QThread>
#include <QTimer> // 使用定时器替代线程睡眠

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("Qt标准对话框示例");
    window.resize(400, 400);

    QVBoxLayout *layout = new QVBoxLayout(&window);

    // 1. 颜色对话框
    QPushButton *colorBtn = new QPushButton("QColorDialog");
    layout->addWidget(colorBtn);
    QObject::connect(colorBtn, &QPushButton::clicked, [&]() {
        QColor color = QColorDialog::getColor(Qt::white, &window, "选择颜色");
        if (color.isValid()) colorBtn->setStyleSheet("background-color: " + color.name());
    });

    // 2. 错误信息对话框
    QPushButton *errorBtn = new QPushButton("QErrorMessage");
    layout->addWidget(errorBtn);
    QObject::connect(errorBtn, &QPushButton::clicked, [&]() {
        QErrorMessage::qtHandler()->showMessage("这是一个错误信息示例");
    });

    // 3. 输入对话框
    QPushButton *inputBtn = new QPushButton("QInputDialog");
    layout->addWidget(inputBtn);
    QObject::connect(inputBtn, &QPushButton::clicked, [&]() {
        bool ok;
        QString text = QInputDialog::getText(&window, "输入对话框", "请输入内容:", QLineEdit::Normal, "", &ok);
        if (ok) inputBtn->setText("输入内容: " + text);
    });

    // 4. 字体对话框
    QPushButton *fontBtn = new QPushButton("QFontDialog");
    layout->addWidget(fontBtn);
    QObject::connect(fontBtn, &QPushButton::clicked, [&]() {
        bool ok;
        QFont font = QFontDialog::getFont(&ok, QFont("Arial", 12), &window);
        if (ok) fontBtn->setFont(font);
    });

    // 5. 文件对话框
    QPushButton *fileBtn = new QPushButton("QFileDialog");
    layout->addWidget(fileBtn);
    QObject::connect(fileBtn, &QPushButton::clicked, [&]() {
        QString file = QFileDialog::getOpenFileName(&window, "选择文件", "", "文本文件 (*.txt);;所有文件 (*)");
        if (!file.isEmpty()) fileBtn->setText("选择文件: " + QFileInfo(file).fileName());
    });

    // 6. 消息对话框
    QPushButton *msgBtn = new QPushButton("QMessageBox");
    layout->addWidget(msgBtn);
    QObject::connect(msgBtn, &QPushButton::clicked, [&]() {
        QMessageBox::information(&window, "消息对话框", "这是一个信息提示框");
    });

    // 7. 修复后的进度对话框（使用定时器）
    QPushButton *progressBtn = new QPushButton("QProgressDialog");
    layout->addWidget(progressBtn);
    QObject::connect(progressBtn, &QPushButton::clicked, [&]() {
        QProgressDialog *progress = new QProgressDialog("处理中...", "取消", 0, 100, &window);
        progress->setWindowTitle("进度对话框");
        //progress->setWindowModality(Qt::WindowModal);
        // 关键设置：使对话框非模态
        progress->setModal(false); // 设置为非模态
        progress->setWindowModality(Qt::NonModal); // 非模态窗口
        progress->setMinimumDuration(0); // 立即显示
        progress->setValue(0);

        // 使用成员变量替代局部变量
        QTimer *timer = new QTimer(progress);
        int *progressValue = new int(0); // 在堆上分配进度值

        QObject::connect(timer, &QTimer::timeout, [=]() mutable {
            *progressValue += 2;
            progress->setValue(*progressValue);

            if (*progressValue >= 100 || progress->wasCanceled()) {
                timer->stop();
                delete progressValue; // 释放内存
                progress->deleteLater(); // 安全删除
            }
        });

        timer->start(50); // 每50毫秒更新一次
    });
    // 8. 向导对话框
    QPushButton *wizardBtn = new QPushButton("QWizard");
    layout->addWidget(wizardBtn);
    QObject::connect(wizardBtn, &QPushButton::clicked, [&]() {
        QWizard wizard(&window);
        wizard.setWindowTitle("向导对话框");

        // 添加页面
        QWizardPage *page1 = new QWizardPage;
        page1->setTitle("第一步");
        page1->setSubTitle("这是向导的第一步");

        QWizardPage *page2 = new QWizardPage;
        page2->setTitle("第二步");
        page2->setSubTitle("这是向导的第二步");

        wizard.addPage(page1);
        wizard.addPage(page2);

        wizard.exec();
    });

    window.show();
    return app.exec();
}
