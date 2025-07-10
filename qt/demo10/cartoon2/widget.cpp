#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsRectItem>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建场景
    scene = new QGraphicsScene(this);

    // 在场景中添加一些内容（示例）
    QGraphicsRectItem *rect = scene->addRect(QRectF(-50, -50, 100, 100));
    rect->setBrush(Qt::blue);

    // 创建视图并设置场景
    view = new QGraphicsView(scene, this);

    // 设置前景色（半透明黄色）
    view->setForegroundBrush(QColor(255, 255, 0, 100));

    // 设置背景图片（确保路径正确）
    // 注意：实际项目中应使用资源路径（如":/images/new.png"）或绝对路径
    view->setBackgroundBrush(QPixmap(":/images/new.png"));

    // 设置视图大小和位置
    view->resize(400, 300);
    view->move(10, 10);

    // 调整窗口大小以适应视图
    this->resize(420, 330);
}

Widget::~Widget()
{
    delete ui;
}
