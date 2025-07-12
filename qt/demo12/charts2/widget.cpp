#include "widget.h"
#include "ui_widget.h"
#include <QChartView>
#include <QEasingCurve>
#include <QValueAxis>
#include <QLineSeries>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建图表视图并设置为窗口中心
    QChartView *chartView = new QChartView(this);
    chartView->setMinimumSize(400, 300);

    // 创建图表和序列
    QChart *chart = new QChart();
    QLineSeries *series = new QLineSeries();
    series->append(0, 0);
    series->append(20, 10);
    chart->addSeries(series);
    chartView->setChart(chart);

    // 配置X轴（核心代码）
    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0, 21);
    axisX->setTickCount(6);
    axisX->setMinorTickCount(1);
    axisX->setLabelFormat("%.2f");
    axisX->setLabelsAngle(30);
    axisX->setLabelsColor(Qt::darkYellow);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // 自动创建Y轴
    chart->createDefaultAxes();
};

Widget::~Widget()
{
    delete ui;
}
