#include "mylineedit.h"
#include <QKeyEvent>
#include <QDebug>
#include "QLineEdit"

MyLineEdit::MyLineEdit(QWidget *parent)
    : QLineEdit{parent}
{}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "MyLineEdit键盘按下事件";  // 移除非必要的 tr()

    // 调用基类处理
    QLineEdit::keyPressEvent(event);

    // 标记事件为未处理
    event->ignore();

}

bool MyLineEdit::event(QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
        qDebug() << tr("MyLineEdit的event()函数");
    return QLineEdit::event(event);
}
