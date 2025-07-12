#include "widget.h"
#include "ui_widget.h"
#include <QtCharts>

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
    QBarSet *set0 = new QBarSet("Jane");
    QBarSet *set1 = new QBarSet("John");
    QBarSet *set2 = new QBarSet("Axel");

    // 添加数据
    *set0 << 1 << 2 << 3 << 4 << 5 << 6;
    *set1 << 5 << 0 << 0 << 4 << 0 << 7;
    *set2 << 3 << 5 << 8 << 13 << 8 << 5;

    // 创建柱状序列并添加数据集
    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    chart->addSeries(series);

    // 创建分类轴（X轴）
    QStringList categories = {"Jan", "Feb", "Mar", "Apr", "May", "Jun"};
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // 自动创建Y轴
    chart->createDefaultAxes();

}

Widget::~Widget()
{
    delete ui;
}
