import QtQuick.Controls 2.15
import QtQuick 2.12
import QtGraphicalEffects 1.0

ApplicationPage {
    id: applicationPage

    ApplicationTimedRoundButton{
        id: upButton

        width: 100
        height: 100
        anchors.top: parent.top
        anchors.topMargin: applicationPage.height * 0.3

        anchors.horizontalCenter: parent.horizontalCenter


        iconPath : "qrc:/icons/up-arrow.svg"
        iconColor: pageColor
    }

    ApplicationTimedRoundButton{
        id: downButton

        width: 100
        height: 100
        anchors.bottom: parent.bottom
        anchors.bottomMargin: applicationPage.height * 0.3

        anchors.horizontalCenter: parent.horizontalCenter

        iconPath : "qrc:/icons/down_arrow.svg"
        iconColor: pageColor
    }

    ApplicationTimedRoundButton{
        id: leftButton

        width: 100
        height: 100
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: applicationPage.width * 0.1


        iconPath : "qrc:/icons/rotate_left.svg"
        iconColor: pageColor
    }

    ApplicationTimedRoundButton{
        id: rightButton

        width: 100
        height: 100
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: applicationPage.width * 0.1


        iconPath : "qrc:/icons/rotate_right.svg"
        iconColor: pageColor
    }
}
