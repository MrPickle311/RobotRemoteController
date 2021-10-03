#pragma once

#include <QObject>

#include "../connector/DeviceConnector.hpp"
class ConnectionPageController : public QObject
{
    Q_OBJECT
private:
    std::shared_ptr<DeviceConnector> connector_;
public:
    explicit ConnectionPageController(const std::shared_ptr<DeviceConnector>& connector ,
                                      QObject *parent = nullptr);
public slots:
    void tryConnect();
signals:
    void connected();
    void deviceNotFound();
    void disconnected();
};

