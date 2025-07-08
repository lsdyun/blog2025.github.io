#include "widget.h"
#include "ui_widget.h"
#include <QTimer>      // 定时器
#include <QTime>       // 时间
#include <QPalette>  // 添加调色板支持
#include <QDebug>    // 添加调试输出


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建并启动定时器
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::updateTime);
    timer->start(1000);  // 每秒触发一次

    // 初始更新时间
    updateTime();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateTime()
{
    // 获取当前时间
    QTime currentTime = QTime::currentTime();

    // 格式化时间（小时:分钟）
    QString timeText = currentTime.toString("hh:mm");

    // 每秒切换冒号显示状态（实现闪烁效果）
    if (currentTime.second() % 2 == 0) {
        timeText[2] = ' ';  // 将冒号位置替换为空格
    }

    // 在LCD上显示时间
    ui->lcdNumber->display(timeText);

    // 生成随机颜色
    int red = QRandomGenerator::global()->bounded(256);
    int green = QRandomGenerator::global()->bounded(256);
    int blue = QRandomGenerator::global()->bounded(256);

    // 调试输出随机颜色值
    qDebug() << "随机颜色值:" << red << green << blue;

    // 创建随机颜色
    QColor randomColor(red, green, blue);

    // 获取LCD的调色板
    QPalette palette = ui->lcdNumber->palette();

    // 设置文字颜色为随机颜色
    palette.setColor(QPalette::WindowText, randomColor);

    // 应用新调色板
    ui->lcdNumber->setPalette(palette);
}
