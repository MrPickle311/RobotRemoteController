#pragma once

#include <QObject>

class EventListener : public QObject
{
    Q_OBJECT
public:
    explicit EventListener(QObject *parent = nullptr);

signals:

};

