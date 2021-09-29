#pragma once

#include <QObject>
#include "../device/DeviceAccessor.hpp"

class OutputBluetoothController :
        public QObject ,
        public DeviceAccessor
{
    Q_OBJECT
public:
    explicit OutputBluetoothController(DevicePtrCRef device , QObject *parent = nullptr);
public slots:
    void sendData(const QByteArray& data);
signals:

};

