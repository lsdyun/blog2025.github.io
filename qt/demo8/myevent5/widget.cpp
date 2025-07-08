#include "widget.h"
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 创建圆形图片
    m_pixmap = QPixmap(100, 100);
    m_pixmap.fill(Qt::transparent);

    QPainter painter(&m_pixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(Qt::blue);
    painter.drawEllipse(10, 10, 80, 80);
    painter.setPen(Qt::white);
    painter.drawText(m_pixmap.rect(), Qt::AlignCenter, "拖我");

    // 初始位置在窗口中心
    m_dragPosition = QPoint(width()/2 - 50, height()/2 - 50);
    m_isDragging = false;

    // 窗口设置
    setWindowTitle("简单图片拖动示例");
    setMinimumSize(400, 300);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    // 计算点击位置相对于图片的位置
    QPoint clickPos = event->pos();

    // 检查是否点击在图片区域内
    if (clickPos.x() >= m_dragPosition.x() &&
        clickPos.x() <= m_dragPosition.x() + m_pixmap.width() &&
        clickPos.y() >= m_dragPosition.y() &&
        clickPos.y() <= m_dragPosition.y() + m_pixmap.height()) {

        m_isDragging = true;
        update(); // 重绘窗口
        qDebug() << "开始拖动图片";
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isDragging) {
        // 更新图片位置（中心点跟随鼠标）
        m_dragPosition = event->pos() - QPoint(m_pixmap.width()/2, m_pixmap.height()/2);
        update(); // 重绘窗口
    }
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    // 绘制背景
    painter.fillRect(rect(), Qt::lightGray);

    // 绘制图片
    painter.drawPixmap(m_dragPosition, m_pixmap);

    // 绘制说明文字
    painter.setPen(Qt::black);
    painter.drawText(10, 20, "点击并拖动蓝色圆形");

    // 绘制拖动状态边框
    if (m_isDragging) {
        painter.setPen(QPen(Qt::red, 2, Qt::DashLine));
        painter.drawRect(m_dragPosition.x(), m_dragPosition.y(),
                         m_pixmap.width(), m_pixmap.height());
    }
}
