#pragma once

#include <QObject>

class DeviceConnector : public QObject
{
    Q_OBJECT
public:
    explicit DeviceConnector(QObject *parent = nullptr);

signals:

};

