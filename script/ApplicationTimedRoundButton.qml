import QtQuick.Controls 2.15
import QtQuick 2.12

ApplicationRoundButton{
    id : btn

    property int internal: 20

    function setAction(action){
        actionToPerform = function(){
            action()
        }
    }

    property var actionToPerform: null

    Timer{
        id: timer

        repeat: true

        interval: btn.internal

        onTriggered: actionToPerform()
    }

    onPressed: timer.start()
    onReleased: timer.stop()

}
