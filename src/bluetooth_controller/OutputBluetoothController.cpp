#include "OutputBluetoothController.hpp"

OutputBluetoothController::OutputBluetoothController(DevicePtrCRef device , QObject *parent) :
    QObject(parent) ,
    DeviceAccessor{device}
{

}

void OutputBluetoothController::sendData(const QByteArray &data)
{
    device_->sendData(data);
}
