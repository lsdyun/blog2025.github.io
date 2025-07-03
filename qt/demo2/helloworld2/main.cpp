#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    //engine.load(QUrl::fromLocalFile("../../main.qml"));
    engine.load(QUrl("qrc:/main.qml"));

    return app.exec();
}
