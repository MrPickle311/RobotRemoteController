#include "Device.hpp"

void Device::handleError(QBluetoothSocket::SocketError error)
{
   qDebug() << "Error : "  << error;
}

Device::Device(QObject *parent) :
    QObject(parent),
    socket_{QBluetoothServiceInfo::RfcommProtocol}
{
    QObject::connect(&socket_ , &QBluetoothSocket::connected 	, this , &Device::connected );
    QObject::connect(&socket_ , &QBluetoothSocket::disconnected , this , &Device::disconnected );
    QObject::connect(&socket_ , QOverload<QBluetoothSocket::SocketError>::of(&QBluetoothSocket::error),
                     this , &Device::error );

    QObject::connect(&socket_ , QOverload<QBluetoothSocket::SocketError>::of(&QBluetoothSocket::error),
                     this , &Device::handleError );
    QObject::connect(&socket_ , &QBluetoothSocket::stateChanged , this , &Device::stateChanged );
}

void Device::sendData(const QByteArray &data)
{
    socket_.write(data);
}

void Device::tryConnect(const QBluetoothAddress &address)
{
    socket_.connectToService(address,
                             QBluetoothUuid{QString{deviceUUID}} ,
                             QIODevice::ReadWrite);
}
