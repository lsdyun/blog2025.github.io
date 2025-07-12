#include "widget.h"
#include "ui_widget.h"
#include <QLineSeries>
#include <QChartView>
#include <QEasingCurve>
#include <QValueAxis>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //第一条线
    QLineSeries* series = new QLineSeries();
    series->append(0, 0);
    series->append(2, 4);
    QChartView *view = new QChartView(this);
    view->chart()->addSeries(series);
    view->resize(400, 300);

    //第二条线
    QLineSeries* series1 = new QLineSeries();
    series1->append(0, 0);
    series1->append(1, 4);
    series1->append(3, 5);
    view->chart()->addSeries(series1);
    // 设置默认坐标轴
    view->chart()->createDefaultAxes();
    view->setRenderHint(QPainter::Antialiasing);

    view->chart()->setTitle(tr("My Charts"));
    view->chart()->setTitleBrush(Qt::darkYellow);
    view->chart()->setTitleFont(QFont("Arial", 20));
    series->setName("2020");
    series1->setName("2021");

    //美化
    //比例和刷子
    view->chart()->legend()->setMarkerShape(
        QLegend::MarkerShapeStar);
    view->chart()->legend()->setBackgroundVisible(true);
    view->chart()->legend()->setColor(QColor(255, 255, 255, 150));
    view->chart()->legend()->setLabelColor(Qt::darkYellow);
    view->chart()->legend()->setAlignment(Qt::AlignBottom);

    view->chart()->setBackgroundBrush(Qt::lightGray);
    view->chart()->setPlotAreaBackgroundBrush(Qt::white);
    view->chart()->setPlotAreaBackgroundVisible(true);
    view->chart()->setBackgroundRoundness(15);
    view->chart()->setDropShadowEnabled(true);

    //主题
    view->chart()->setTheme(QChart::ChartThemeBlueIcy);

    //动画
    view->chart()->setAnimationOptions(QChart::AllAnimations);
    view->chart()->setAnimationDuration(2000);
    view->chart()->setAnimationEasingCurve(QEasingCurve(QEasingCurve::InQuad));



}

Widget::~Widget()
{
    delete ui;
}
