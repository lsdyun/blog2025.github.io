#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QMovie>

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
    void paintEvent(QPaintEvent *event);
    //void showEvent(QShowEvent *event);  // 添加显示事件处理

private:
    int angle;  // 添加角度成员变量
    QTimer *timer; // 添加定时器成员变量
private:
    QLabel *screenshotLabel;  // 添加标签成员变量
    QPixmap screenshot;       // 添加截图缓存
private:
    QLabel *gifLabel;  // 用于显示GIF的标签
    QMovie *gifMovie;  // 用于播放GIF的动画对象

};
#endif // WIDGET_H
