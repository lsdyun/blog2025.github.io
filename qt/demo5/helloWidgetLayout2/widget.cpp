#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 初始状态设置
    ui->textEdit->setVisible(false);
    ui->pushButton->setText(tr("显示扩展区域"));

    // 手动连接信号槽（如果自动连接失效）
    connect(ui->pushButton, &QPushButton::toggled,
            this, &Widget::on_pushButton_toggled);

}

Widget::~Widget()
{
    delete ui;
}

// 修改槽函数
void Widget::on_pushButton_toggled(bool checked)
{
    ui->textEdit->setVisible(checked);

    if(checked) {
        // 根据UI中控件的实际高度设置
        ui->pushButton->setText(tr("隐藏扩展区域"));
    } else {
        ui->pushButton->setText(tr("显示扩展区域"));
    }
}

