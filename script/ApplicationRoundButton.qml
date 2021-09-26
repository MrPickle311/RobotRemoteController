import QtQuick.Controls 2.15
import QtQuick 2.12

RoundButton{
    id: button

    property string iconPath: ""
    property color iconColor: "black"

    icon.source : iconPath
    icon.height: height
    icon.width: width
    icon.color: pageColor

    function rescale(scale){
        icon.width = 0.7 * icon.width
        icon.height = 0.7 * icon.height
    }

    function changeIcon(new_url){
        button.icon.source = new_url
    }
}
