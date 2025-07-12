#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QtCharts>
#include <QRandomGenerator> // 包含随机数生成器头文件

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

private slots:
    void handleTimeout();

private:
    QChartView *chartView;
    QLineSeries *series;
    QValueAxis *axisX;
    int id = 0;
    QTimer *timer;
};
#endif // WIDGET_H
