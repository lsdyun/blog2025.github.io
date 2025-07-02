#if defined(__MINGW32__)
extern "C" {
    __declspec(dllimport) int __argc;
    __declspec(dllimport) char** __argv;
}
#endif


#include <QApplication>
#include <QDialog>
#include <QLabel>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDialog w;
    w.resize(400, 300);		//设置对话框宽度为400，高为300
    QLabel label(&w);
    label.move(120, 120);//设置label在对话框中的位置，默认左上角的(0,0)
    label.setText(QObject::tr("Hello World! 你好Qt！"));
    //添加的QObject::tr()函数可以实现多语言支持，建议程序中所有要显示到界面上的字符串都使用tr()函数括起来
    w.show();
    return a.exec();
}