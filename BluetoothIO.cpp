#include "BluetoothIO.hpp"
#include <QDebug>
#include <QBluetoothUuid>

BluetoothIO::BluetoothIO(QObject *parent) :
    QObject(parent),
    socket_{QBluetoothServiceInfo::RfcommProtocol}
{
    QObject::connect(&agent_, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered ,
            this   , &BluetoothIO::addDeviceToList);
    QObject::connect(&agent_, &QBluetoothDeviceDiscoveryAgent::finished ,
            this   , &BluetoothIO::finishedService);
    //connect(&agent_, &QBluetoothDeviceDiscoveryAgent::error ,
     //       this   , &BluetoothIO::errorService);


}

void BluetoothIO::addDeviceToList(const QBluetoothDeviceInfo &info)
{
    qDebug() << "Device discovered!  " << info.name();

    devices_.append(info);

    devices_model_.append(info.name());
    emit devicesModelChanged();

    emit deviceFound(info.name());
}

void BluetoothIO::finishedService()
{
    qDebug() << "       FINISHED!!! ";
}

void BluetoothIO::errorService(QBluetoothDeviceDiscoveryAgent::Error error)
{
    qDebug() << "Error has occurred ";
}

void BluetoothIO::search()
{
    devices_.clear();
    devices_model_.clear();
    qDebug() << "Searching...";
    agent_.start();
}

const QStringList& BluetoothIO::getDevicesModel() const
{
    return m_devices_model_;
}

void BluetoothIO::setDevicesModel(const QStringList& newDevices_model_)
{
    if (m_devices_model_ == newDevices_model_)
        return;
    m_devices_model_ = newDevices_model_;
    emit devicesModelChanged();
}

void BluetoothIO::connect(int pos)
{
    socket_.connectToService(devices_[pos].address(),
                             QBluetoothUuid{QString{"00001101-0000-1000-8000-00805F9B34FB"}} ,
                             QIODevice::ReadWrite);
}

void BluetoothIO::ledOn()
{
    qDebug() << "LED ON";
    QByteArray dat{"1"};
    socket_.write(dat);
}

void BluetoothIO::ledOff()
{
    qDebug() << "LED OFF";
    QByteArray dat{"0"};
    socket_.write(dat);
}

void BluetoothIO::receiveData()
{
    qDebug() << socket_.readAll();
}
