#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>  // 仅包含必要的定时器头文件
#include <QColor>  // 添加颜色支持
#include <QRandomGenerator>  // 添加随机数生成器

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

private slots:
    void updateTime();  // 时间更新槽函数

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
