#include "mywidget.h"
#include "mydialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    /*
    QApplication a(argc, argv);
    MyWidget w;
    w.show();
    return a.exec();
    */

    QApplication a(argc, argv);
    MyDialog dialog;
    if(dialog.exec() == QDialog::Accepted){
        MyWidget w;
        w.show();
        return a.exec();
    }
    else return 0;

}
