#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QTransform>
#include <QWindow>

#include <QPainter>
#include <QScreen>
#include <QGuiApplication>
#include <QShowEvent>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , angle(0)// 初始化角度
    , screenshotLabel(nullptr)
{
    ui->setupUi(this);
    // 在构造函数中初始化定时器
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&Widget::update));
    timer->start(1000);  // 每秒触发重绘

    // 创建并配置标签
    screenshotLabel = new QLabel(this);
    screenshotLabel->resize(400, 200);
    screenshotLabel->move(0, 100);
    screenshotLabel->setAlignment(Qt::AlignCenter);

    // 创建并配置标签
    gifLabel = new QLabel(this);
    gifLabel->resize(400, 400);
    gifLabel->move(50, 50);  // 设置位置
    gifLabel->setAlignment(Qt::AlignCenter);  // 居中对齐

    // 创建并配置动画
    gifMovie = new QMovie(":/images/fireworks.gif");

    // 检查GIF是否加载成功
    if (!gifMovie->isValid()) {
        gifLabel->setText("Failed to load GIF!");
    } else {
        gifLabel->setMovie(gifMovie);
        gifMovie->start();
    }
}

Widget::~Widget()
{
    delete ui;
    // 释放资源
    delete gifMovie;
}

/*
void Widget::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);

    // 在窗口显示后截图一次
    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen) {
        screenshot = screen->grabWindow(0);  // 截取整个屏幕

        // 缩放截图以适应标签大小
        QPixmap scaled = screenshot.scaled(screenshotLabel->size(),
                                           Qt::KeepAspectRatio,
                                           Qt::SmoothTransformation);
        screenshotLabel->setPixmap(scaled);
    }
}
*/

void Widget::paintEvent(QPaintEvent *)
{
    /*图形*/
    /*
    QPainter painter(this);
    painter.drawLine(QPoint(0,0),QPoint(100,100));

    QPen pen(Qt::green, 5, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);
    QRectF rectangle(70.0, 40.0, 80.0, 60.0);
    int startAngle = 30 * 16;
    int spanAngle = 160 * 16;
    painter.drawArc(rectangle, startAngle, spanAngle);
    */


    /*刷子*/
    /*
    //重新设置画笔
    pen.setWidth(1);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);
    painter.drawRect(160, 20, 50, 40);
    //创建画刷
    QBrush brush(QColor(0, 0 ,255),Qt::Dense4Pattern);
    painter.setBrush(brush);
    painter.drawEllipse(220, 20, 50, 50);
    //设置纹理
    brush.setTexture(QPixmap(":/images/new.png"));
    //重新使用画刷
    painter.setBrush(brush);
    static const QPointF points[4]= {
        QPointF(270.0, 80.0),
        QPointF(290.0, 10.0),
        QPointF(350.0, 30.0),
    };
    // 使用四个点绘制多边形
    painter.drawPolygon(points, 4);
    */


    /*渐变*/
    // 线性渐变
    /*
    QLinearGradient linearGradient(QPointF(40, 190), QPointF(70, 190));
    // 插入颜色
    linearGradient.setColorAt(0, Qt::yellow);
    linearGradient.setColorAt(0.5, Qt::red);
    linearGradient.setColorAt(1, Qt::green);
    // 指定渐变区域以外的区域的扩散方式
    linearGradient.setSpread(QGradient::RepeatSpread);
    // 使用渐变作为画刷
    painter.setBrush(linearGradient);
    painter.drawRect(10, 170, 90, 40);

    // 画笔使用线性渐变来绘制直线和文字
    painter.setPen(QPen(linearGradient,2));
    painter.drawLine(0, 280, 100, 280);
    painter.drawText(150, 280, tr("helloQt!"));
    */


    /*坐标*/
    /*
    angle += 10;
    if(angle == 360)
        angle = 0;
    int side = qMin(width(), height());
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QTransform transform;
    transform.translate(width()/2, height()/2);
    transform.scale(side/300.0, side/300.0);
    transform.rotate(angle);
    painter.setWorldTransform(transform);
    painter.drawEllipse(-120, -120, 240, 240);
    painter.drawLine(0, 0, 100, 0);
*/

    /*
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/images/new.png");
    painter.drawPixmap(0, 0, pix.width(), pix.height(), pix);
    painter.setBrush(QColor(0, 255, 255, 100));
    painter.drawRect(0, 0, pix.width(), pix.height());
    painter.drawPixmap(200, 0, pix.width(), pix.height(), pix);
    painter.setBrush(QColor(0, 0, 255, 100));
    painter.drawRect(200, 0, pix.width(), pix.height());

*/

    /*
    // 只绘制背景或其他静态内容
    QPainter painter(this);
    painter.fillRect(rect(), Qt::white);

    // 显示截图标签（已在showEvent中设置）
    screenshotLabel->show();
    */

}
