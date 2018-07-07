import QtQuick 2.6
import QtQuick.Window 2.2
import Share.core 1.0
import QtQuick.Controls 1.4

Window {
    visible: true
    x: 0
    y: 0
    width: Screen.width
    height: Screen.height
    title: qsTr("Gifer")
    color: "transparent"

    GifWindow
    {
        id: iGifWindow
        x: PointManager.leftTopX
        y: PointManager.leftTopY
        width: PointManager.width
        height: PointManager.height
    }

    MouseArea
    {
        anchors.fill: parent
        onPressed: {
            PointManager.setLeftTopPoint( mouseX, mouseY );
            PointManager.setRightBottomPoint( mouseX, mouseY );
            console.log( "onPressed: (" + mouseX + ", " + mouseY + ")" );
        }
        onPositionChanged: {
            PointManager.setRightBottomPoint( mouseX, mouseY )
            console.log( "onReleased: (" + mouseX + ", " + mouseY + ")" );
        }
    }

    Row
    {
        anchors.top: iGifWindow.bottom
        anchors.horizontalCenter: iGifWindow.horizontalCenter
        spacing: 5

        Button
        {
            id: iRecordButton
            text: "record"
            visible: iGifWindow.height > 0 && iGifWindow.width > 0
            onClicked: {
                if( "record" === text )
                {
                    text = "recording"
                }
                else
                {
                    text = "record"
                }
            }
        }

        Button
        {
            id: iFinishButton
            text: "finish"
            visible: iGifWindow.height > 0 && iGifWindow.width > 0
            anchors.top: iGifWindow.bottom
            onClicked: {
                if( "recording" === iRecordButton.text )
                {
                    iRecordButton.text = "record"
                }
            }
        }
    }
}
