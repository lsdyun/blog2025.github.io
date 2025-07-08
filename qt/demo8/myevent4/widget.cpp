#include "widget.h"
#include "ui_widget.h"
#include <QMimeData>       // MIME数据处理
#include <QDragEnterEvent> // 拖动进入事件
#include <QDropEvent>      // 放下事件
#include <QFile>           // 文件操作
#include <QTextStream>     // 文本流
#include <QUrl>            // URL处理
#include <QDebug>          // 调试输出

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 启用拖放功能
    setAcceptDrops(true);

    // 设置窗口属性
    setWindowTitle("文件拖放示例");
    resize(600, 400);
}

Widget::~Widget()
{
    delete ui;
}

// 拖动进入事件处理
void Widget::dragEnterEvent(QDragEnterEvent *event)
{
    // 检查拖动的数据是否包含文件路径
    if (event->mimeData()->hasUrls()) {
        event->acceptProposedAction();  // 接受拖动操作
    } else {
        event->ignore();  // 忽略不支持的类型
    }
}

// 放下事件处理
void Widget::dropEvent(QDropEvent *event)
{
    // 获取MIME数据
    const QMimeData *mimeData = event->mimeData();

    // 检查是否包含URL（文件路径）
    if(mimeData->hasUrls()) {
        // 获取URL列表
        QList<QUrl> urlList = mimeData->urls();

        // 获取第一个文件的本地路径
        QString fileName = urlList.first().toLocalFile();

        // 检查文件名是否有效
        if(!fileName.isEmpty()) {
            QFile file(fileName);  // 创建文件对象

            // 尝试以只读方式打开文件
            if(file.open(QIODevice::ReadOnly)) {
                QTextStream in(&file);  // 创建文本流
                ui->textEdit->setText(in.readAll());  // 读取全部内容并显示
                file.close();  // 关闭文件

                // 输出成功信息
                qDebug() << "成功打开文件:" << fileName;
            } else {
                // 输出错误信息
                qDebug() << "无法打开文件:" << fileName;
            }
        }
    }

    // 接受拖放操作
    event->acceptProposedAction();
}
