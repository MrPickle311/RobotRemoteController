#include "ControlPageController.hpp"

ControlPageController::ControlPageController(const std::shared_ptr<OutputBluetoothController> &controller,
                                             QObject* parent):
    QObject{parent} ,
    controller_{controller}
{

}

void ControlPageController::driveStraight()
{
    controller_->sendData("df");
}

void ControlPageController::driveBackwards()
{
    controller_->sendData("db");
}

void ControlPageController::turnLeft()
{
    controller_->sendData("dl");
}

void ControlPageController::turnRight()
{
    controller_->sendData("dr");
}

