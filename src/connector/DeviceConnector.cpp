#include "DeviceConnector.hpp"

void DeviceConnector::tryAcquireConnection()
{
    device_->tryConnect(device_info_.address());
}

void DeviceConnector::tryFindDevice()
{
    device_found_ = false;
    agent_.start();
}

void DeviceConnector::checkAtFinish()
{
    if(device_found_)
    {
        qDebug() << "Found";
        tryAcquireConnection();
    }
    else emit this->deviceNotFound();
}

void DeviceConnector::finishSearching()
{
   agent_.stop();
   tryAcquireConnection();
}

void DeviceConnector::checkDiscoveredDevice(const QBluetoothDeviceInfo &info)
{
    qDebug() << info.name();
    if(info.name() == device_id)
    {
        this->device_found_ = true;
        this->device_info_ = info;
        finishSearching();
    }
}

DeviceConnector::DeviceConnector(DevicePtrCRef device, QObject *parent) :
    QObject(parent) ,
    DeviceAccessor{device} ,
    device_found_{false}
{
    QObject::connect(device_.get() , &Device::connected 	, this , &DeviceConnector::connected );
    QObject::connect(device_.get(), &Device::disconnected , this , &DeviceConnector::disconnected );


    QObject::connect(&agent_, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered ,
            this   , &DeviceConnector::checkDiscoveredDevice);
    QObject::connect(&agent_, &QBluetoothDeviceDiscoveryAgent::finished ,
            this   , &DeviceConnector::checkAtFinish);
}

void DeviceConnector::tryConnect()
{
    tryFindDevice();
}
