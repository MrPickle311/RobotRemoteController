import QtQuick.Controls 2.15
import QtQuick 2.12
import QtGraphicalEffects 1.0

Rectangle {
    id: baseRectangle
    color: "transparent"

    width: 100
    height: 100

    property string sensorName: ""
    property string sensorPostfix: ""
    property string sensorValue: "0 " + sensorPostfix
    property string sensorIconPath: ""
    property bool colorOverlayEnabled: true

    function updateValue(new_val){
        sensorValue = new_val + " " + sensorPostfix
    }

    Rectangle {
        id: iconRectangle
        color: "transparent"
        anchors.fill: parent

        Image {
            id: buttonIcon
            source: sensorIconPath

            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            height: 90
            width: 90

            fillMode: Image.PreserveAspectFit
        }

        ColorOverlay{

            Component.onCompleted: {
                if(colorOverlayEnabled){
                    source = buttonIcon
                    anchors.fill =  buttonIcon
                }
            }

            anchors.fill:  null
            source: null
            color: "white"
            antialiasing: true
        }
    }

    Text {
        id: sensorNameText
        y: 21
        width: 20
        height: 15
        color: "#ffffff"
        text: sensorName

        font.pixelSize: 16

        anchors.left: iconRectangle.left
        anchors.bottom: iconRectangle.top
        anchors.bottomMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text {
        id: sensorValueText
        color: "#ffffff"
        text: "Value " + sensorValue

        font.pixelSize: 16

        anchors.top: iconRectangle.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
    }


}
