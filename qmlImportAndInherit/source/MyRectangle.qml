import QtQuick 2.0

Rectangle {
    implicitWidth: 200
    implicitHeight: 100
    border.color: "red"
    color: "transparent"

    property alias mouseArea: iMouseArea
    property alias rectTextArea: iText

    MouseArea
    {
        id: iMouseArea
        anchors.fill: parent
    }

    Text
    {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        id: iText
        text: ""
    }
}
