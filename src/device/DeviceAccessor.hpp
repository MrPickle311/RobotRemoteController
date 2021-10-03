#pragma once

#include <QObject>
#include "Device.hpp"

using DevicePtrCRef =  const std::shared_ptr<Device>&;

class DeviceAccessor
{
protected:
    std::shared_ptr<Device> device_;
public:
    explicit DeviceAccessor(DevicePtrCRef device);
};

