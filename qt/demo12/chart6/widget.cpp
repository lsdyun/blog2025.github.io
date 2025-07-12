#include "widget.h"
#include "ui_widget.h"
#include <QWidget>
#include <QtCharts>
#include <QStandardItemModel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建模型并添加测试数据
    model = new QStandardItemModel(5, 2, this); // 5行2列
    model->setHeaderData(0, Qt::Horizontal, "X");
    model->setHeaderData(1, Qt::Horizontal, "Y");

    // 填充测试数据 (x, y)
    model->setItem(0, 0, new QStandardItem("1.0"));
    model->setItem(0, 1, new QStandardItem("2.0"));
    model->setItem(1, 0, new QStandardItem("2.0"));
    model->setItem(1, 1, new QStandardItem("4.0"));
    model->setItem(2, 0, new QStandardItem("3.0"));
    model->setItem(2, 1, new QStandardItem("6.0"));

    // 创建图表视图
    QChartView *chartView = new QChartView(this);
    chartView->resize(400, 300);

    // 创建图表和系列
    QChart *chart = new QChart();
    chartView->setChart(chart);
    QLineSeries *series = new QLineSeries();
    chart->addSeries(series);

    // 核心映射器代码
    QVXYModelMapper *mapper = new QVXYModelMapper(this);
    mapper->setSeries(series);
    mapper->setModel(model);
    mapper->setXColumn(0); // X值来自第0列
    mapper->setYColumn(1); // Y值来自第1列

    // 自动创建坐标轴
    chart->createDefaultAxes();
};
Widget::~Widget()
{
    delete ui;
}
