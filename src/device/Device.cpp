#include "Device.hpp"

Device::Device(QObject *parent) : QObject(parent)
{
//    QObject::connect(&socket_ , QBluetoothSocket::readyRead
}

void Device::sendData(const QByteArray &data)
{
    socket_.write(data);
}

void Device::tryConnect(const QBluetoothAddress &address)
{
    socket_.connectToService(address,
                             QBluetoothUuid{QString{"00001101-0000-1000-8000-00805F9B34FB"}} ,
                             QIODevice::ReadWrite);
}
