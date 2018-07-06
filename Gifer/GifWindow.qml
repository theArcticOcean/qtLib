import QtQuick 2.0

Rectangle {
    implicitWidth: 5
    implicitHeight: 5
    border.color: "red"
    color: "transparent"

    property alias mouseArea: iMouseArea

    MouseArea
    {
        id: iMouseArea
        anchors.fill: parent
    }
}
