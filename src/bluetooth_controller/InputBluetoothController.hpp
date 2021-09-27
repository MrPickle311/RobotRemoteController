#pragma once

#include <QObject>

class InputBluetoothController : public QObject
{
    Q_OBJECT
public:
    explicit InputBluetoothController(QObject *parent = nullptr);

signals:

};

