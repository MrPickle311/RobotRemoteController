import QtQuick.Controls 2.15
import QtQuick 2.12
import "sensor" as Sensor

ApplicationPage {
    id: applicationPage

        Sensor.SensorColumn {
            id: leftColumn

            anchors.left: parent.left

            Sensor.TemperatureSensor{
                id: temperatureSensor
                Component.onCompleted: updateValue(5)
            }

            Sensor.PressureSensor{
                id: pressureSensor
                Component.onCompleted: updateValue(5)
            }

            Sensor.HumiditySensor{
                id: humiditySensor
                Component.onCompleted: updateValue(5)
            }

            Sensor.MagneticFieldSensor{

            }
        }

        Sensor.SensorColumn {
            id: rightColumn

            anchors.right: parent.right

            Sensor.COSensor{

            }

            Sensor.CO2Sensor{

            }

            Sensor.SunSensor{

            }

            Sensor.UVSensor{

            }

        }

}
