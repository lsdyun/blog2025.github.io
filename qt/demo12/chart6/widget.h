#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QChartView>
#include <QStandardItemModel> // 使用标准项模型
#include <QVXYModelMapper>

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

private:
    QStandardItemModel *model; // 使用标准项模型
};
#endif // WIDGET_H
