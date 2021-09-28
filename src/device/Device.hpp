#pragma once

#include <QObject>
#include <QBluetoothSocket>
#include  <memory>

class ConnectionState;

class Device : public QObject
{
    Q_OBJECT
private:
    std::shared_ptr<ConnectionState> connection_state_;
    bool is_connected_;
    QBluetoothSocket socket_;
public:
    explicit Device(QObject *parent = nullptr);
public slots:
    void sendData(const QByteArray& data);
    void tryConnect(const QBluetoothAddress& address);
signals:
    void receiveData(QByteArray data);
};

