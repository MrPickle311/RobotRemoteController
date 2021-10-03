#pragma once

#include <QObject>
#include "../bluetooth_controller/OutputBluetoothController.hpp"

class ControlPageController : public QObject
{
    Q_OBJECT;
private:
    std::shared_ptr<OutputBluetoothController> controller_;
public:
    explicit ControlPageController(const std::shared_ptr<OutputBluetoothController>&  controller ,  QObject* parent = nullptr);

public slots:
    void	driveStraight();
    void 	driveBackwards();
    void  	turnLeft();
    void	turnRight();
};

