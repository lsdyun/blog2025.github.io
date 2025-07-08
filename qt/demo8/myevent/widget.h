#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QCursor>
#include <QApplication>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    QLineEdit *lineEdit;  // 声明lineEdit变量

public:
    bool eventFilter(QObject *obj, QEvent *event) override;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;   // 添加鼠标移动事件声明
    void mouseReleaseEvent(QMouseEvent *event) override; // 添加鼠标释放事件声明
    void mouseDoubleClickEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

private:
    QPointF offset; // 存储鼠标位置与窗口位置的差值

};
#endif // WIDGET_H
