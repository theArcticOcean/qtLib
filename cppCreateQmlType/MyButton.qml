import QtQuick 2.7
import Share.core 1.0

ButtonBase
{
    property alias backgound: iImage

    Image
    {
        id: iImage
        source: "qrc:/source/normal.png"
        anchors.fill: parent
    }

    MouseArea
    {
        anchors.fill: parent
        onPressed: {
            buttonName = "Pressed button";
            iImage.source = "qrc:/source/pressed.png";
        }
        onReleased: {
            buttonName = "Released buttoon";
            iImage.source = "qrc:/source/normal.png";
        }
    }
}
