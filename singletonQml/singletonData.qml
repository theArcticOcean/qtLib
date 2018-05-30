pragma Singleton
import QtQuick 2.0

QtObject{
    property int value: 0

    function getValue()
    {
        value = value + 1;
        return value;
    }
}
