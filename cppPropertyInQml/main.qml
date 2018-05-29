import QtQuick 2.6
import QtQuick.Window 2.2
import Wei.Spacing 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        id: iStringRect

        width: parent.width
        height: parent.height
        color: "green"

        MouseArea
        {
            anchors.fill: parent
            onClicked: {
                console.log( DataSource.getTime() );
            }
            Text{
                anchors.fill: parent
            }
        }
    }
}
