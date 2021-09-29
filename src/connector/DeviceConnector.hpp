#pragma once

#include <QObject>
#include <QBluetoothDeviceDiscoveryAgent>
#include "../device/DeviceAccessor.hpp"

class ConnectionErrorHandler
{
public :
    void handleError(QBluetoothSocket::SocketError error);
};

class ConnectionState
{

};

class DeviceConnector :
        public QObject ,
        public DeviceAccessor
{
    Q_OBJECT
private:
    constexpr static auto device_id = "HC-06";
private:
    bool	device_found_;
    QBluetoothDeviceDiscoveryAgent agent_;
    QBluetoothDeviceInfo 		   device_info_;
private:
    void tryAcquireConnection();
    void tryFindDevice();
    void finishSearching();
private slots:
    void checkDiscoveredDevice(const QBluetoothDeviceInfo& info);
public:
    explicit DeviceConnector(DevicePtrCRef device, QObject *parent = nullptr);
public slots:
    void tryConnect();
signals:
    void connected();
    void deviceNotFound();
    void disconnected();
};

