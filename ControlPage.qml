import QtQuick.Controls 2.15
import QtQuick 2.12
import QtGraphicalEffects 1.0

ApplicationPage {
    id: applicationPage

    ApplicationRoundButton{
        id: upButton

        width: 100
        height: 100
        anchors.top: parent.top
        anchors.topMargin: applicationPage.width * 0.1

        anchors.horizontalCenter: parent.horizontalCenter


        iconPath : "qrc:/icons/up-arrow.svg"
        iconColor: pageColor
    }

    ApplicationRoundButton{
        id: downButton

        width: 100
        height: 100
        anchors.bottom: parent.bottom
        anchors.bottomMargin: applicationPage.height * 0.1

        anchors.horizontalCenter: parent.horizontalCenter

        iconPath : "qrc:/icons/down_arrow.svg"
        iconColor: pageColor
    }

    ApplicationRoundButton{
        id: leftButton

        width: 100
        height: 100
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: applicationPage.width * 0.1


        iconPath : "qrc:/icons/rotate_left.svg"
        iconColor: pageColor
    }

    ApplicationRoundButton{
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
