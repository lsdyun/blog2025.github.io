#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QFont>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 创建主窗口
    QWidget window;
    window.setWindowTitle("插入图片示例");
    window.resize(500, 450);

    // 创建标签
    QLabel *label = new QLabel(&window);
    label->setPixmap(QPixmap(":images/test.png"));

    // 显示窗口
    window.show();

    return app.exec();
}
