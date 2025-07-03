#include <QApplication>
#include <QWidget>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *widget = new QWidget();       // 新建QWidget类对象，默认parent参数是nullptr，所以它是个窗口
    widget->setWindowTitle(QObject::tr("我是widget"));      // 设置窗口标题

    QLabel *label = new QLabel();        // 新建QLabel对象，默认parent参数是nullptr，所以它是个窗口
    label->setWindowTitle(QObject::tr("我是label"));
    label->setText(QObject::tr("label:我是个窗口"));        // 设置要显示的信息
    label->resize(180, 20);        // 改变部件大小，以便能显示出完整的内容

    QLabel *label2 = new QLabel(widget);         // label2指定了父窗口为widget，所以不是窗口
    label2->setText(QObject::tr("label2:我不是独立窗口，只是widget的子部件"));
    label2->resize(250, 20);

    label->show();    // 在屏幕上显示出来
    widget->show();

    return app.exec();
}
