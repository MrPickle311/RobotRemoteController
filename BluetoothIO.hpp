#pragma once

#include <QObject>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QStringList>
#include <QBluetoothDeviceInfo>
#include <QBluetoothSocket>

class BluetoothIO : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QStringList devices_model_ READ getDevicesModel WRITE setDevicesModel NOTIFY devicesModelChanged);
private:
    QBluetoothDeviceDiscoveryAgent agent_;
    QList<QBluetoothDeviceInfo>    devices_;
    QStringList                    devices_model_;
    QStringList m_devices_model_;

    QBluetoothSocket socket_;

public:
    explicit BluetoothIO(QObject *parent = nullptr);
private slots:
    void addDeviceToList(const QBluetoothDeviceInfo &info);
    void finishedService();
    void errorService(QBluetoothDeviceDiscoveryAgent::Error error);

public slots:
    void search();
    const QStringList& getDevicesModel() const;
    void setDevicesModel(const QStringList& newDevices_model_);

    void connect(int pos);

    void ledOn();
    void ledOff();

    void receiveData();
signals:
    void searchComplete();
    void devicesModelChanged();

    void deviceFound(QString dev);


};
