
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}






/*
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QRadioButton>
#include <QSpinBox>
#include <QTextEdit>
#include <QPushButton>
#include <QGroupBox>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // 创建主窗口
    QWidget window;
    window.setWindowTitle("综合布局示例");
    window.resize(600, 400);

    // 主布局 - 垂直布局
    QVBoxLayout *mainLayout = new QVBoxLayout;

    // 1. 表单布局部分 (个人信息)
    QGroupBox *formGroup = new QGroupBox("个人信息");
    QFormLayout *formLayout = new QFormLayout;

    QLineEdit *nameEdit = new QLineEdit;
    QSpinBox *ageSpin = new QSpinBox;
    ageSpin->setRange(1, 120);

    // 性别单选按钮
    QHBoxLayout *genderLayout = new QHBoxLayout;
    QRadioButton *maleRadio = new QRadioButton("男");
    QRadioButton *femaleRadio = new QRadioButton("女");
    genderLayout->addWidget(maleRadio);
    genderLayout->addWidget(femaleRadio);
    maleRadio->setChecked(true);

    // 邮箱组合控件
    QHBoxLayout *emailLayout = new QHBoxLayout;
    QLineEdit *emailEdit = new QLineEdit;
    QComboBox *emailCombo = new QComboBox;
    emailCombo->addItems({"@qq.com", "@163.com", "@gmail.com", "@outlook.com"});
    emailLayout->addWidget(emailEdit);
    emailLayout->addWidget(emailCombo);

    // 添加表单行
    formLayout->addRow("姓名:", nameEdit);
    formLayout->addRow("性别:", genderLayout);
    formLayout->addRow("年龄:", ageSpin);
    formLayout->addRow("邮箱:", emailLayout);
    formGroup->setLayout(formLayout);

    // 2. 网格布局部分 (内容编辑)
    QGroupBox *gridGroup = new QGroupBox("内容编辑");
    QGridLayout *gridLayout = new QGridLayout;

    QComboBox *fontCombo = new QComboBox;
    fontCombo->addItems({"Arial", "Times New Roman", "Verdana"});
    QPushButton *fontButton = new QPushButton("设置字体");
    QTextEdit *textEdit = new QTextEdit;

    gridLayout->addWidget(fontCombo, 0, 0);
    gridLayout->addWidget(fontButton, 0, 1);
    gridLayout->addWidget(textEdit, 1, 0, 1, 2); // 占据1行2列
    gridGroup->setLayout(gridLayout);

    // 3. 按钮布局 (水平布局)
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QPushButton *submitButton = new QPushButton("提交");
    QPushButton *cancelButton = new QPushButton("取消");

    buttonLayout->addStretch(); // 添加弹性空间
    buttonLayout->addWidget(submitButton);
    buttonLayout->addWidget(cancelButton);

    // 组合所有布局
    mainLayout->addWidget(formGroup);
    mainLayout->addWidget(gridGroup);
    mainLayout->addLayout(buttonLayout);

    // 设置主布局
    window.setLayout(mainLayout);
    window.show();

    return app.exec();
}

*/

/*
#include <QApplication>
#include <QWidget>
#include <QStackedLayout>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // 创建主窗口
    QWidget window;
    window.setWindowTitle("QStackedLayout 示例");
    window.resize(400, 300);

    // 创建主垂直布局（用于放置切换按钮和堆叠布局）
    QVBoxLayout *mainLayout = new QVBoxLayout;

    // 创建按钮布局（水平布局）
    QHBoxLayout *buttonLayout = new QHBoxLayout;

    // 创建切换按钮
    QPushButton *page1Button = new QPushButton("显示页面 1");
    QPushButton *page2Button = new QPushButton("显示页面 2");
    QPushButton *page3Button = new QPushButton("显示页面 3");

    buttonLayout->addWidget(page1Button);
    buttonLayout->addWidget(page2Button);
    buttonLayout->addWidget(page3Button);

    // 创建堆叠布局
    QStackedLayout *stackedLayout = new QStackedLayout;

    // 创建三个不同颜色的页面
    QWidget *page1 = new QWidget;
    page1->setStyleSheet("background-color: #FFCCCC;");
    QLabel *label1 = new QLabel("<h1>页面 1</h1><p>这是堆叠布局的第一个页面</p>");
    label1->setAlignment(Qt::AlignCenter);
    QVBoxLayout *page1Layout = new QVBoxLayout(page1);
    page1Layout->addWidget(label1);

    QWidget *page2 = new QWidget;
    page2->setStyleSheet("background-color: #CCFFCC;");
    QLabel *label2 = new QLabel("<h1>页面 2</h1><p>这是堆叠布局的第二个页面</p>");
    label2->setAlignment(Qt::AlignCenter);
    QVBoxLayout *page2Layout = new QVBoxLayout(page2);
    page2Layout->addWidget(label2);

    QWidget *page3 = new QWidget;
    page3->setStyleSheet("background-color: #CCCCFF;");
    QLabel *label3 = new QLabel("<h1>页面 3</h1><p>这是堆叠布局的第三个页面</p>");
    label3->setAlignment(Qt::AlignCenter);
    QVBoxLayout *page3Layout = new QVBoxLayout(page3);
    page3Layout->addWidget(label3);

    // 将页面添加到堆叠布局
    stackedLayout->addWidget(page1);
    stackedLayout->addWidget(page2);
    stackedLayout->addWidget(page3);

    // 连接按钮信号到切换槽函数
    QObject::connect(page1Button, &QPushButton::clicked, [stackedLayout]() {
        stackedLayout->setCurrentIndex(0);  // 切换到页面1
    });

    QObject::connect(page2Button, &QPushButton::clicked, [stackedLayout]() {
        stackedLayout->setCurrentIndex(1);  // 切换到页面2
    });

    QObject::connect(page3Button, &QPushButton::clicked, [stackedLayout]() {
        stackedLayout->setCurrentIndex(2);  // 切换到页面3
    });

    // 将按钮布局和堆叠布局添加到主布局
    mainLayout->addLayout(buttonLayout);
    mainLayout->addLayout(stackedLayout);

    // 设置主布局
    window.setLayout(mainLayout);
    window.show();

    return app.exec();
}

*/






/*
#include <QApplication>
#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // 创建主窗口
    QWidget window;
    window.setWindowTitle("QFormLayout 示例");
    window.resize(400, 200);

    // 创建表单布局
    QFormLayout *layout = new QFormLayout;

    // 创建表单控件
    QLineEdit *nameEdit = new QLineEdit;
    nameEdit->setPlaceholderText("输入姓名");

    QSpinBox *ageSpin = new QSpinBox;
    ageSpin->setRange(1, 120);
    ageSpin->setValue(25);

    QComboBox *genderCombo = new QComboBox;
    genderCombo->addItems({"男", "女", "其他"});

    QPushButton *submitButton = new QPushButton("提交");

    // 添加表单项（标签 + 控件）
    layout->addRow("姓名:", nameEdit);
    layout->addRow("年龄:", ageSpin);
    layout->addRow("性别:", genderCombo);

    // 添加按钮（跨两列）
    layout->addRow(submitButton);

    // 设置布局参数
    layout->setSpacing(15);  // 行间距
    layout->setContentsMargins(30, 20, 30, 20);

    // 设置标签对齐方式
    layout->setLabelAlignment(Qt::AlignRight);

    // 将布局设置到窗口
    window.setLayout(layout);
    window.show();

    return app.exec();
}
*/

/*
#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QComboBox>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // 创建主窗口
    QWidget window;
    window.setWindowTitle("QGridLayout 示例");
    window.resize(600, 300);

    // 创建网格布局
    QGridLayout *layout = new QGridLayout;

    // 创建控件
    QComboBox *comboBox = new QComboBox;
    comboBox->addItems({"Arial", "Times New Roman", "Verdana"});

    QPushButton *button = new QPushButton("确认");
    QTextEdit *textEdit = new QTextEdit;
    textEdit->setPlaceholderText("在此输入文本...");

    // 添加控件到网格布局
    layout->addWidget(comboBox, 0, 0, 1, 2);  // 第0行0列，占据1行2列
    layout->addWidget(button,   0, 2, 1, 1);  // 第0行2列，占据1行1列
    layout->addWidget(textEdit, 1, 0, 1, 3);  // 第1行0列，占据1行3列

    // 可选：设置间距和边距
    layout->setSpacing(10);
    layout->setContentsMargins(20, 20, 20, 20);

    // 将布局设置到窗口
    window.setLayout(layout);
    window.show();

    return app.exec();
}
*/


/*
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextEdit>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // 创建主窗口
    QWidget window;
    window.setWindowTitle("QHBoxLayout 示例");
    window.resize(600, 200);

    // 创建水平布局
    QHBoxLayout *layout = new QHBoxLayout;

    // 创建两个控件
    QPushButton *button = new QPushButton("点击我");
    QTextEdit *textEdit = new QTextEdit;
    textEdit->setPlaceholderText("输入文本...");

    // 将控件添加到布局
    layout->addWidget(button);
    layout->addWidget(textEdit);

    // 设置布局参数
    layout->setSpacing(50);         // 控件间距
    layout->setContentsMargins(30, 20, 30, 20);  // 边距(左,上,右,下)

    // 将布局设置到窗口
    window.setLayout(layout);
    window.show();

    return app.exec();
}
*/

