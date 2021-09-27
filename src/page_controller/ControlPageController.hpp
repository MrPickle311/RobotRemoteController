#pragma once

#include <QObject>

class ControlPageController : public QObject
{
    Q_OBJECT;
public:
    explicit ControlPageController(QObject* parent = nullptr);
public slots:

signals:
    void connected();
    void tryConnect();

};

