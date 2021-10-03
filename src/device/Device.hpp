#pragma once

#include <QObject>
#include <QBluetoothSocket>
#include  <memory>

class ConnectionState;

class Device : public QObject
{
    Q_OBJECT
private:
    constexpr static auto deviceUUID = "00001101-0000-1000-8000-00805F9B34FB";

//    std::shared_ptr<ConnectionState> connection_state_;
    void handleError(QBluetoothSocket::SocketError error);
    bool is_connected_;
    QBluetoothSocket socket_;
public:
    explicit Device(QObject *parent = nullptr);
public slots:
    void sendData(const QByteArray& data);
    void tryConnect(const QBluetoothAddress& address);
signals:
    void receiveData(QByteArray data);
    void connected();
    void disconnected();
    void error(QBluetoothSocket::SocketError error);
    void stateChanged(QBluetoothSocket::SocketState state);
};

