import QtQuick 2.15
import QtQuick.Controls 2.15

Button {
    id : btn

    property var actionToPerform: null

    Timer{
        id : tim

        onTriggered: actionToPerform()
        repeat: true
        interval: 20
    }

    onPressed: tim.start()
    onReleased: tim.stop()

}
