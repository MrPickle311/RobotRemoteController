#include "ControlPageController.hpp"

ControlPageController::ControlPageController(const std::shared_ptr<DeviceConnector> &connector,
                                             QObject* parent):
    QObject{parent},
    connector_{connector}
{

}

void ControlPageController::tryConnect()
{
    connector_->tryConnect();
}
