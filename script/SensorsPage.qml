import QtQuick.Controls 2.15
import QtQuick 2.12

ApplicationPage {
    id: applicationPage

        SensorColumn {
            id: leftColumn

            SensorBox{
                id: temperatureSensor

                sensorName: "Temperature"
                sensorPostfix: "K"
                sensorIconPath: "qrc:/icons/sensor/thermometer.svg"

                Component.onCompleted: updateValue(5)
            }

            SensorBox{
                id: pressureSensor

                sensorName: "Pressure"
                sensorPostfix: "hPa"
                sensorIconPath: "qrc:/icons/sensor/pressure.svg"

                Component.onCompleted: updateValue(5)
            }
        }

        SensorColumn {
            id: rightColumn

        }

}
