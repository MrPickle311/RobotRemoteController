import QtQuick.Window 2.2

import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import Qt.program.singletons 1.0
import QtQuick.Controls.Material 2.12
ApplicationWindow {

    Material.theme: Material.Dark

    id: win
    width: 1080
    height: 2340
    visible: true
    title: qsTr("Hello World")
    Button{
        id : btn

        function showConnected(){
            text = "Connected"
        }

        function showDisconnected(){
            text = "Not connected"
        }

        function showNotFound(){
            text = "Not found"
        }
        background: Rectangle{
            color: "blue"
            visible: true
        }

        anchors.horizontalCenter: parent
        y: 0
        width: 300
        height: 300
        text: "Not connected"

        onClicked: ConnectionPageController.tryConnect()

    }

    SenderButton {
        id: button
        width: 134
        height: 64
        text: qsTr("Up")

       anchors.top: btn.bottom
       Component.onCompleted: {
            actionToPerform =  function(){
                ControlPageController.driveStraight()
            }
       }
    }

    SenderButton {
        id: button1
        width: 198
        height: 104
        text: qsTr("Down")

        anchors.top: button.bottom

       Component.onCompleted: {
            actionToPerform =  function(){
                ControlPageController.driveBackwards()
            }
       }
    }

    SenderButton {
        id: button2
        width: 190
        height: 67
        text: qsTr("Left")

        anchors.top: button1.bottom

       Component.onCompleted: {
            actionToPerform =  function(){
                ControlPageController.turnLeft()
            }
       }
    }

    SenderButton {
        id: button3
        text: qsTr("Right")

        anchors.top: button2.bottom

       Component.onCompleted: {
            actionToPerform =  function(){
                ControlPageController.turnRight()
            }
       }
    }

    Component.onCompleted: {
        ConnectionPageController.connected.connect(btn.showConnected)
        ConnectionPageController.disconnected.connect(btn.showDisconnected)
        ConnectionPageController.deviceNotFound.connect(btn.showNotFound)
    }

/*
    Component.onCompleted: {
        //win.width = Screen.desktopAvailableWidth
        //win.height = Screen.desktopAvailableHeight

        BluetoothIO.deviceFound.connect(addDevice)
    }

    property var devices: ["ok"]

    ListModel{
        id: listModel
    }

    function addDevice(device){
        listModel.append({name: device})
    }



    Column {
        id: column
        width: 400
        anchors.left: parent.left
        anchors.right: column1.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.topMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        spacing: 53

        Button {
            id: offButton
            text: qsTr("LED OFF")
            onClicked:  BluetoothIO.ledOff()
        }

        Button {
            id: onButton
            text: qsTr("LED ON")
            onClicked:  BluetoothIO.ledOn()
        }

        Button {
            id: connectButton
            text: qsTr("Connect")
            onClicked: BluetoothIO.connect(devicesListComboBox.currentIndex)
        }
    }

    Column {
        id: column1
        x: 479
        width: 200
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.topMargin: 0
        anchors.rightMargin: 0
        spacing: 47

        Button{
            id: searchButton
            text: "Search devices"
            onClicked: {
                listModel.clear()
                BluetoothIO.search()
            }

        }

        ComboBox {
            id: devicesListComboBox
            model: listModel
        }

        Button {
            id: disconnectButton
            text: qsTr("Disconnect")
        }
    }

*/
//    SwipeView {
//        id: view

//        currentIndex: 1
//        anchors.fill: parent

//        ConnectionPage {
//            id: firstPage
//        }
//        Item {
//            id: secondPage
//        }
//        Item {
//            id: thirdPage
//        }
//    }

//    PageIndicator {
//        id: indicator

//        count: view.count
//        currentIndex: view.currentIndex

//        anchors.bottom: view.bottom
//        anchors.horizontalCenter: parent.horizontalCenter
//    }
}
