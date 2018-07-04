import QtQuick 2.6
import QtQuick.Window 2.2
// import "source"          // It's ok if we import dir, then we need not qmlRegisterType
import Source.Core 1.0      // We can also import module that we define in qmlRegisterType

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    property int count: 0

    MyRectangle {
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        mouseArea.onClicked: {
            console.log("We click it");
            ++count;
            rectTextArea.text = "We click it " + count + " times.";
        }
    }
}
