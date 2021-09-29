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

void DeviceConnector::finishSearching()
{
   agent_.stop();
   tryAcquireConnection();
}

void DeviceConnector::checkDiscoveredDevice(const QBluetoothDeviceInfo &info)
{
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
   #warning "Reimplement the following functions to ConnectionState , and emit only signal which sends device's state"
    QObject::connect(device_.get() , &Device::connected 	, this , &DeviceConnector::connected );
    QObject::connect(device_.get(), &Device::disconnected , this , &DeviceConnector::disconnected );

    QObject::connect(&agent_, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered ,
            this   , &DeviceConnector::checkDiscoveredDevice);
}

void DeviceConnector::tryConnect()
{
    tryFindDevice();
}
