import QtQuick.Controls 2.15
import QtQuick 2.12

Page {
    background: Rectangle{
        color: "#2c313c"
    }
    visible: true
    property string not_connected : "Try connect"
    property string connected : "Connected"

    RoundButton{
        width: 200
        height: 200
        anchors.centerIn: parent
        //text:  not_connected
        //radius: 600
    }
}
