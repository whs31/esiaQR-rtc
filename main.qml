import QtQuick 2.12
import QtQuick.Controls 2.5

import cpp.dialogue 1.0

ApplicationWindow {
    visible: true
    width: 300
    height: 500
    title: qsTr("Сканер QR")

    property var qrlinkNumbers: "0000000";

    Dialogue
    {
        id: dialogue
    }

    function qrlinkOpacityFade()
    {
        qrlinkText.text = qrlinkNumbers;
        if(qrlinkNumbers!=="err")
        {
            animRect.start();
        }
        else {
            qrlinkText.text="Ошибка считывания";
            qrlinkText.color = "red";

            animRect.start();
        }

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
                qrlinkNumbers = dialogue.scanQR();
                //console.log(qrlinkNumbers);
                qrlinkOpacityFade();
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

        Text {
            id: qrlinkText
            x: 127
            y: 311
            color: "#229932"
            text: qsTr("Text")
            font.bold: true
            textFormat: Text.RichText
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 24
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 12

            opacity: 0
        }
    }
    SequentialAnimation{
        id:animRect
        NumberAnimation { target: qrlinkText; property: "opacity"; from: 0.00; to:1.00; duration: 700 }
        NumberAnimation { target: qrlinkText; property: "opacity"; from: 1.00; to:0.00; duration: 700 }
        //onStopped: console.log(qrlinkText.visible)
    }
}

/*##^##
Designer {
    D{i:1;anchors_height:200;anchors_width:200;anchors_x:50;anchors_y:26}D{i:3;anchors_height:200;anchors_width:200;anchors_x:50;anchors_y:26;invisible:true}
D{i:4;invisible:true}D{i:5;anchors_height:200;anchors_width:200;anchors_x:50;anchors_y:26;invisible:true}
D{i:6;invisible:true}D{i:8;anchors_y:311}
}
##^##*/
