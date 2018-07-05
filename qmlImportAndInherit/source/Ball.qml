import QtQuick 2.7

Rectangle
{
    width: 100
    height: 300

    Image
    {
        id: iImage
        // anchors.top:parent.top   // anchors.top has higher ownership of iImage's position.
                                    // Once we set it, y can't be changed.
        y: 0
        source: "ball.png"
        sourceSize.width: 50
        sourceSize.height: 50
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Timer
    {
        interval: 100
        running: true
        repeat: true
        onTriggered: {
            iImage.y = iImage.y + 10;
            //console.log( "this is onTriggered: " + iImage.y );
            if( iImage.y + iImage.sourceSize.height >= parent.height ) iImage.y = 0;
        }
    }
}
