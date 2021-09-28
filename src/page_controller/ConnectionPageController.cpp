#include "ConnectionPageController.hpp"

ConnectionPageController::ConnectionPageController(const std::shared_ptr<DeviceConnector> &connector ,
                                                   QObject *parent) :
    QObject(parent),
    connector_{connector}
{
    QObject::connect(connector.get() , &DeviceConnector::connected 	, this , &ConnectionPageController::connected );
    QObject::connect(connector.get() , &DeviceConnector::disconnected , this , &ConnectionPageController::disconnected );
}

void ConnectionPageController::tryConnect()
{
    connector_->tryConnect();
}
