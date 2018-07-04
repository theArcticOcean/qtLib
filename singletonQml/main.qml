import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.1
import Singleton.Spacing 1.0

Window {
    id: iWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Label
    {
        id: iLabel
        width: iWindow.width / 2
        height: iWindow.height / 2
        text: ""
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        //horizontalCenter: parent.horizontalCenter

        Rectangle
        {
            anchors.fill: parent
            border.color: "red"
            color: "transparent"
        }
    }

    MouseArea
    {
        anchors.fill: parent
        onClicked: {
            iLabel.text = singletonData.getValue();
        }
    }
}
