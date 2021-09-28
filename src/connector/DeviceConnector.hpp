#pragma once

#include <QObject>
#include <QBluetoothDeviceDiscoveryAgent>



class DeviceConnector : public QObject
{
    Q_OBJECT
private:
    QBluetoothDeviceDiscoveryAgent agent_;
    QBluetoothDeviceInfo 		   device_info_;
private:
    bool tryAcquireConnection();
    bool tryFindDevice();
private slots:
    void checkhandleDiscoveredDevice(const QBluetoothDeviceInfo& info);
public:
    explicit DeviceConnector(QObject *parent = nullptr);
public slots:
    bool tryConnect();
};

