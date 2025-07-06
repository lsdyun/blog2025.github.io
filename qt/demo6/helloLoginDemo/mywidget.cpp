#include "mywidget.h"
#include "ui_mywidget.h"
#include "mydialog.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_clicked()
{
    close();
    MyDialog dialog;
    if(dialog.exec() == QDialog::Accepted){
        show();
    }
}

