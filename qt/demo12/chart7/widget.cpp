#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建图表视图
    chartView = new QChartView(this);
    chartView->resize(600, 400);

    // 创建图表和系列
    QChart *chart = new QChart();
    chartView->setChart(chart);
    series = new QLineSeries();
    chart->addSeries(series);

    // 创建坐标轴
    axisX = new QValueAxis;
    axisX->setRange(0, 10); // 初始X轴范围
    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0, 20); // Y轴范围

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    // 初始化定时器
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::handleTimeout);
    timer->start(1000); // 每秒触发一次
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleTimeout() {
    // 生成模拟数据
    int m_x = id;
    int m_y = QRandomGenerator::global()->bounded(20); // 生成0-19的随机数

    // 添加数据点
    series->append(m_x, m_y);

    // 滚动逻辑：当接近X轴右边界时滚动图表
    if (m_x > axisX->max() - 3) {
        qreal width = chartView->chart()->plotArea().width();
        qreal dx = width / (axisX->tickCount() - 1);
        chartView->chart()->scroll(dx, 0);
    }

    id++; // 移动到下一个数据点

    // 可选：设置停止条件（例如100个点后停止）
    if (id > 100) timer->stop();
}
