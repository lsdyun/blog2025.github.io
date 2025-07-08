#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>       // 包含键盘事件头文件
#include <QDebug>          // 包含调试输出头文件
#include <QTimerEvent>
#include <QTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 启动三个定时器
    id1 = startTimer(1000);   // 1秒定时器
    id2 = startTimer(2000);   // 2秒定时器
    id3 = startTimer(5000);   // 5秒定时器

    qDebug() << "定时器已启动:"
             << "Timer1 ID:" << id1
             << "Timer2 ID:" << id2
             << "Timer3 ID:" << id3;

}

Widget::~Widget()
{
    delete ui;
    // 停止所有定时器
    killTimer(id1);
    killTimer(id2);
    killTimer(id3);
    qDebug() << "所有定时器已停止";
}

void Widget::keyPressEvent(QKeyEvent *event)        // 键盘按下事件
{
    if(event->modifiers() == Qt::ControlModifier){  // 是否按下Ctrl键
        if(event->key() == Qt::Key_M)               // 是否按下M键
            setWindowState(Qt::WindowMaximized);    // 窗口最大化
    }
    else QWidget::keyPressEvent(event);
}



void Widget::timerEvent(QTimerEvent *event)
{
    // 获取当前时间
    QTime currentTime = QTime::currentTime();
    QString timeStr = currentTime.toString("hh:mm:ss.zzz");

    if (event->timerId() == id1) {
        qDebug() << timeStr << "| Timer1 触发";
    }
    else if (event->timerId() == id2) {
        qDebug() << timeStr << "| Timer2 触发";
    }
    else if (event->timerId() == id3) {
        qDebug() << timeStr << "| Timer3 触发";
    }
    else {
        qDebug() << timeStr << "| 未知定时器 ID:" << event->timerId();
    }
}

