#include "widget.h"
#include "ui_widget.h"
#include <QLineEdit>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建并初始化lineEdit
    lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(50, 50, 200, 30);  // 设置位置和大小

    // 安装事件过滤器
    lineEdit->installEventFilter(this);

    // 设置窗口属性
    setWindowTitle("鼠标事件示例");
    resize(400, 300);

}

Widget::~Widget()
{
    delete ui;
    delete lineEdit;  // 释放lineEdit内存
}


void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << tr("Widget键盘按下事件");
}

bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == lineEdit){
        if(event->type() == QEvent::KeyPress)
            qDebug() << tr("Widget的事件过滤器");
    }
    return QWidget::eventFilter(obj, event);
}


//鼠标事件
void Widget::mousePressEvent(QMouseEvent *event)  // 鼠标按下事件
{
    if(event->button() == Qt::LeftButton){        // 如果是鼠标左键按下
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor);  // 使鼠标指针暂时改变形状
        offset = event->globalPosition() - pos(); // 获取指针位置和窗口位置的差值
    }
    else if(event->button() == Qt::RightButton){  // 如果是鼠标右键按下
        QCursor cursor(QPixmap("../mymouseevent/image/logo.png"));
        QApplication::setOverrideCursor(cursor);  // 使用自定义的图片作为鼠标指针
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)   // 鼠标移动事件
{
    if(event->buttons() & Qt::LeftButton){        // 这里必须使用buttons()
        QPointF temp;
        temp = event->globalPosition() - offset;
        // 使用鼠标指针当前的位置减去差值，就得到了窗口应该移动的位置
        move(temp.x(), temp.y());
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)   // 鼠标释放事件
{
    Q_UNUSED(event);
    QApplication::restoreOverrideCursor();           // 恢复鼠标指针形状
}

void Widget::mouseDoubleClickEvent(QMouseEvent *event)   // 鼠标双击事件
{
    if(event->button() == Qt::LeftButton){                // 如果是鼠标左键按下
        if(windowState() != Qt::WindowFullScreen)         // 如果现在不是全屏
            setWindowState(Qt::WindowFullScreen);         // 将窗口设置为全屏
        else setWindowState(Qt::WindowNoState);           // 否则恢复以前的大小
    }
}

void Widget::wheelEvent(QWheelEvent *event)      // 滚轮事件
{
    if(event->angleDelta().y() > 0){             // 当滚轮远离使用者时
        ui->textEdit->zoomIn();                  // 进行放大
    }else{                                       // 当滚轮向使用者方向旋转时
        ui->textEdit->zoomOut();                 // 进行缩小
    }
}

