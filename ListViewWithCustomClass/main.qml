import QtQuick 2.6
import QtQuick.Window 2.2
import Union.Lotto.MyClass 1.0
 
Window{
    visible: true
    width: 100
    height: 200

    Rectangle {
        id: iRec1
        anchors.top: parent.top
        color: "red";
        width: parent.width;
        height: 50
    }

    Rectangle {
        id: iRec2
        anchors.top: iRec1.bottom;
        color: "green";
        width: parent.width;
        height: 50
    }

    Rectangle {
        id: iRec3
        anchors.top: iRec2.bottom;
        color: "blue";
        width: parent.width;
        height: 50
    }

    ListView{
        id: iListView

        anchors.top: iRec3.bottom
        width: parent.width
        height: 50
        visible: true

//        model: {
//            var result = myClass.fetchNumbers();
//            var set = [];
//            for(var i=0;i<result.length;i++)
//            {
//                console.log(result[i]);
//                set.push(result[i]);
//            }
//            return set;
//        }
//        delegate: Text{
//            text: {
//                modelData;
//            }
//        }

        model: {
//            var result = myClass.dataClass;
//            console.log( "result: " + result + ", length is " + result.count );  //qml: ====>QVariant(QList<MyData*>)
//            var set = [];
//            for( var i=0; i<result.count; i++ )
//            {
//                var it = result.row(i);
//                console.log( it );
//                set.push( result.row(i) );
//            }
//            return set;
            var dataClassObj = myClass.dataClass;
            var result = dataClassObj.allData();
            console.log(result);
            return result;
        }

        delegate: Text{
            text: {
                modelData.number + " " + modelData.number;
            }
        }
    }

    MyClass{
        id: myClass
    }

    function getfilterData(id)
    {

    }
}
