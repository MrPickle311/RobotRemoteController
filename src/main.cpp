#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <BluetoothIO.hpp>
#include <QQmlEngine>
#include "page_controller/ConnectionPageController.hpp"
#include "device/Device.hpp"
#include "connector/DeviceConnector.hpp"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    std::shared_ptr<Device> dev_{std::make_shared<Device>()};
    std::shared_ptr<DeviceConnector> connector{std::make_shared<DeviceConnector>(dev_)};

    ConnectionPageController page_ctrl{connector};

    qmlRegisterSingletonInstance("Qt.program.singletons", 1 , 0 , "ControlPageController", &page_ctrl );

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
