#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPixmap>

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    QPixmap m_pixmap;       // 存储图片
    QPoint m_dragPosition;  // 图片位置
    bool m_isDragging;      // 是否正在拖动
};

#endif // WIDGET_H
