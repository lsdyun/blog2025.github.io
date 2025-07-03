#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 关键步骤1：将按钮设置为可检查（checkable）
    ui->pushButton->setCheckable(true);

    // 关键步骤2：确保按钮名称匹配（可选检查）
    qDebug() << "按钮对象名称:" << ui->pushButton->objectName();

    // 可选：设置按钮文本以显示状态
    ui->pushButton->setText("点击我");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_toggled(bool checked)
{
    // 关键步骤3：使用qDebug输出调试信息
    qDebug() << "按钮是否按下：" << checked;

    // 可选：在按钮上显示状态
    if(checked) {
        ui->pushButton->setText("已按下");
    } else {
        ui->pushButton->setText("已释放");
    }

    // 可选：添加其他视觉反馈

    if(checked) {
        ui->pushButton->setStyleSheet("background-color: green;");
    } else {
        ui->pushButton->setStyleSheet("");
    }

}
