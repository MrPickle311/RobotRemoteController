import QtQuick.Controls 2.15
import QtQuick 2.12
import QtGraphicalEffects 1.0

ApplicationPage {

    property string not_connected : "Try connect"
    property string connected : "Connected"

    function showConnected(icon){
        button.rescale(0.7)
        icon.source = "qrc:/icons/connected.svg"
    }

    ApplicationRoundButton{
        id: button
        width: 200
        height: 200
        anchors.centerIn: parent

        onClicked: showConnected(icon)

        iconPath : "qrc:/icons/connect.svg"
        iconColor: pageColor
    }
}
