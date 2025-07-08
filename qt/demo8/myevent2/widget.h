#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>  // 包含键盘事件头文件
#include <QTimerEvent>  // 包含定时器事件头文件

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

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::Widget *ui;

protected:
    void timerEvent(QTimerEvent *event) override;  // 定时器事件处理函数
private:
    int id1;  // 定时器1 ID
    int id2;  // 定时器2 ID
    int id3;  // 定时器3 ID

};
#endif // WIDGET_H
