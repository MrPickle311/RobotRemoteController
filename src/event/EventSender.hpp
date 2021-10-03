#pragma once

#include <QObject>

class EventSender : public QObject
{
    Q_OBJECT
public:
    explicit EventSender(QObject *parent = nullptr);

signals:

};

