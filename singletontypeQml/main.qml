import QtQuick 2.6
import QtQuick.Window 2.2
import Qt.example.brightNess 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle{
        anchors.fill: parent
        border.color: "red"
        color: "transparent"

        MouseArea{
            anchors.fill: parent
            onClicked: BrightNess.addBrightLevel();
        }
    }
}
