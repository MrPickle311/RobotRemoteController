#pragma once

#include <QObject>
#include <QBluetoothDeviceDiscoveryAgent>



class DeviceConnector : public QObject
{
    Q_OBJECT
public:
    explicit DeviceConnector(QObject *parent = nullptr);

signals:

};

