import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 200
    height: 200
    title: qsTr("cppCreateQmlType")

    // We can also use ButtonBase in qml directly. But for seeing the button, I define MyButton.
    MyButton
    {
        id: iButton
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }

    Text
    {
        id: iText
        text: iButton.buttonName        // bind text and ButtonBase's property buttonName
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
