import QtQuick 2.6
import QtQuick.Window 2.2
import Share.core 1.0

Window {
    visible: true
    x: 0
    y: 0
    width: Screen.width
    height: Screen.height
    title: qsTr("Gifer")

    GifWindow
    {
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
//        onReleased: {
//            PointManager.setRightBottomPoint( mouseX, mouseY )
//            console.log( "onReleased: (" + mouseX + ", " + mouseY + ")" );
//        }
        onPositionChanged: {
            PointManager.setRightBottomPoint( mouseX, mouseY )
            console.log( "onReleased: (" + mouseX + ", " + mouseY + ")" );
        }
    }
}
