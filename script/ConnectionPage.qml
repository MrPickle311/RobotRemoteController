import QtQuick.Controls 2.15
import QtQuick 2.12
import QtGraphicalEffects 1.0

import Qt.program.singletons 1.0

ApplicationPage {
    id: applicationPage

    readonly property string connecting : "Connecting"
    readonly property string not_found : "Device not found"
    readonly property string connected : "Connected"
    readonly property string not_connected : "Not connected"

    readonly property string connectedIcon: "qrc:/icons/connected.svg"
    readonly property string connectIcon: "qrc:/icons/connect.svg"

    function showConnected(button){
        button.rescale(0.7)
        button.changeIcon(connectedIcon)
    }

    Text{
        id: connectionStatusText

        readonly property real dropScale: 0.8

        anchors.horizontalCenter: parent.horizontalCenter
        y : dropScale * applicationPage.height

        text: not_connected
        color: "white"

        function setText(newText){
            text = newText
        }
    }

    Timer{
        id: timer

        interval: 600
        repeat: false
        onTriggered: {
            connectionStatusText.setText(connected)
            showConnected(connectionButton)
        }
    }

    ApplicationRoundButton{
        id: connectionButton
        width: 200
        height: 200
        anchors.centerIn: parent

        onClicked: {
            timer.start()
            connectionStatusText.setText(connecting)
            ConnectionPageController.tryConnect()
        }

        iconPath : connectIcon
        iconColor: pageColor
    }
}
