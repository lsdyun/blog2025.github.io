/*
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
*/



#include <QApplication>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
//#include "myitem.h"

int main(int argc,char* argv[ ])
{
    QApplication app(argc,argv);
    // 新建场景
    QGraphicsScene scene;
    // 创建矩形图形项
    QGraphicsRectItem *item = new QGraphicsRectItem(0, 0, 100, 100);
    //MyItem *item = new MyItem;

    // 将图形项添加到场景中
    scene.addItem(item);
    // 输出(50, 50)点处的图形项
    qDebug() << scene.itemAt(50, 50, QTransform());

    return app.exec();
}

