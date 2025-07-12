#include "widget.h"
#include "ui_widget.h"
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QChartView>
#include <QBarSeries>
#include <QCategoryAxis> // 包含分类轴头文件

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建图表视图
    QChartView *view = new QChartView(this);
    view->resize(600, 400);

    // 创建图表
    QChart *chart = new QChart();
    view->setChart(chart);

    // 创建柱状数据集
    QBarSet *set = new QBarSet("Performance");
    *set << 3 << 7 << 12 << 9 << 4; // 5个数据点

    // 创建柱状序列并添加数据集
    QBarSeries *series = new QBarSeries();
    series->append(set);
    chart->addSeries(series);

    // 创建分类X轴（月份）
    QStringList months = {"Jan", "Feb", "Mar", "Apr", "May"};
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(months);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // 创建分类Y轴（核心代码）
    QCategoryAxis *axisY = new QCategoryAxis();
    axisY->append("Low", 5);     // 0-5为Low
    axisY->append("Medium", 10); // 5-10为Medium
    axisY->append("High", 15);   // 10-15为High
    axisY->setRange(0, 15);      // 设置Y轴范围
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
}

Widget::~Widget()
{
    delete ui;
}
