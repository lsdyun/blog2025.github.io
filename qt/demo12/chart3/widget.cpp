#include "widget.h"
#include "ui_widget.h"
#include <QChartView>
#include <QSplineSeries>
#include <QValueAxis>
#include <QLogValueAxis>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建图表视图
    QChartView *view = new QChartView(this);
    view->resize(500, 400);

    // 创建图表和曲线序列
    QChart *chart = new QChart();
    QSplineSeries *series = new QSplineSeries(); // 使用曲线序列

    // 添加曲线数据点（指数增长）
    series->append(0, 8);
    series->append(5, 32);
    series->append(10, 128);
    series->append(15, 200);
    series->append(20, 256);

    chart->addSeries(series);
    view->setChart(chart);

    // X轴
    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0, 21);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // 对数Y轴（核心）
    QLogValueAxis *axisY = new QLogValueAxis;
    axisY->setBase(2);
    axisY->setRange(8, 260);
    axisY->setMinorTickCount(1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // 设置曲线样式
    series->setPen(QPen(Qt::blue, 2)); // 蓝色曲线，线宽2
}

Widget::~Widget()
{
    delete ui;
}
