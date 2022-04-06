import QtQuick 2.12
import QtQuick.Controls 2.5

import cpp.dialogue 1.0

ApplicationWindow {
    visible: true
    width: 300
    height: 500
    title: qsTr("Сканер QR")

    Dialogue
    {
        id: dialogue
    }

    Frame {
        id: frameBeforeScan
        anchors.fill: parent

        RoundButton {
            id: buttonEnableCamera
            x: 130
            y: 193
            width: 130
            height: 130
            text: "Сканировать"
            clip: false
            enabled: true
            wheelEnabled: false
            hoverEnabled: true
            focusPolicy: Qt.StrongFocus
            autoRepeat: false
            flat: false
            highlighted: false
            autoExclusive: false
            checkable: false
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                dialogue.scanQR();
            }

        }
    }

    Frame {
        id: frameDuringScan
        x: -8
        y: 0
        enabled: false
        anchors.fill: parent
    }

    Frame {
        id: frameAfterScan
        x: 6
        y: -7
        enabled: false
        anchors.fill: parent
    }

    Frame {
        id: frameSettings
        x: -9
        y: 2
        enabled: false
        anchors.fill: parent
    }

    Frame {
        id: frameAbout
        x: -6
        y: -4
        enabled: false
        anchors.fill: parent
    }

}

/*##^##
Designer {
    D{i:1;anchors_height:200;anchors_width:200;anchors_x:50;anchors_y:26}D{i:3;anchors_height:200;anchors_width:200;anchors_x:50;anchors_y:26;invisible:true}
D{i:4;invisible:true}D{i:5;anchors_height:200;anchors_width:200;anchors_x:50;anchors_y:26;invisible:true}
D{i:6;invisible:true}
}
##^##*/
