import QtQuick.Window 2.2

import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import Qt.program.singletons 1.0

ApplicationWindow {
    id: win
    visible: true
    title: qsTr("Hello World")
    color: "white"

    Component.onCompleted: {
        win.width = Screen.desktopAvailableWidth
        win.height = Screen.desktopAvailableHeight

        BluetoothIO.deviceFound.connect(addDevice)
    }

    property var devices: ["ok"]

    ListModel{
        id: listModel
    }

    function addDevice(device){
        listModel.append({name: device})
    }

    SwipeView {
        id: swipeView

        currentIndex: 1
        anchors.fill: parent

        ConnectionPage {
            id: connectionPage
        }
        ControlPage {
            id: controlPage
        }
        SensorsPage {
            id: thirdPage
        }
    }

    ApplicationPageIndicator {
        id: indicator

        view: swipeView
    }
}
