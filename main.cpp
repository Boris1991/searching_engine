#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "ConverterJSON.h"

int main(int argc, char **argv) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    
    QGuiApplication app(argc, argv);
    
    app.setOrganizationName("YourOrganizationName");
    app.setOrganizationDomain("yourorganizationdomain.com");
    app.setApplicationName("ApplicationName");
    
    qmlRegisterType<ConverterJSON>("Сonverter", 1, 0, "ConverterJSON");
       
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    engine.load(url);
    
    if (engine.rootObjects().isEmpty())
        return -1;

    
    return app.exec();
}
