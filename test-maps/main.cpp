#include <QGuiApplication>
#include <QtQml/QQmlApplicationEngine>

int main(int argc, char **argv) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("../main.qml")));

    return app.exec();
}
