import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    /*
    Rectangle {
        width: 100; height: 100; color: "green"

        MouseArea {
            anchors.fill: parent
            onClicked: { parent.color = 'red' }
        }
    }
    */
    /*
    Rectangle {
        width: 100; height: 100; color: "green"

        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            onClicked: (mouse)=> {
                if (mouse.button === Qt.RightButton)
                    parent.color = 'blue';
                else
                    parent.color = 'red';
            }
            onDoubleClicked: (mouse)=> {
                if ((mouse.button === Qt.LeftButton)
                        && (mouse.modifiers & Qt.ShiftModifier))
                    parent.color = "green"
            }
        }
    }
    */

    /*
    Rectangle {
        width: 360; height: 360
        Text { id:myText; anchors.centerIn: parent; text: "Qt" }
        MouseArea {
            anchors.fill: parent
            onWheel: (wheel)=> {
                if (wheel.modifiers & Qt.ControlModifier) {
                    if (wheel.angleDelta.y > 0)
                        myText.font.pointSize += 1
                    else
                        myText.font.pointSize -= 1
                }
            }
        }
    }

    */

    /*
    Rectangle {
        id: container; width: 600; height: 200

        Rectangle {
            id: rect; width: 50; height: 50
            color: "red"; opacity: (600.0 - rect.x) / 600

            MouseArea {
                anchors.fill: parent
                drag.target: rect; drag.axis: Drag.XAxis
                drag.minimumX: 0
                drag.maximumX: container.width - rect.width
            }
        }
    }
    */

    /*
    Item {
        width: 400; height: 150

        DropArea {
            x: 175; y: 75; width: 50; height: 50
            Rectangle {
                id: area; anchors.fill: parent
                border.color: "black"
            }
            onEntered: {
                area.color = drag.source.color
            }
        }

        MyRect{color: "blue"; x:110 }
        MyRect{color: "red"; x:140 }
        MyRect{color: "yellow"; x:170 }
        MyRect{color: "black"; x:200 }
        MyRect{color: "steelblue"; x:230 }
        MyRect{color: "green"; x:260 }
    }

*/
    /*
    Item {
        focus: true
        Keys.onPressed: (event)=> {
            if (event.key === Qt.Key_Left) {
                console.log("move left");
                event.accepted = true;
            }
        }
        Keys.onReturnPressed: console.log("Pressed return");
    }
*/

    /*
    Item {
        Timer {
            interval: 1000; running: true; repeat: true
            onTriggered: time.text = Date().toString()
        }
        Text { id: time }
    }
    */

    Item {
        width: 400; height: 100

        Text {
            id: time
            anchors.centerIn: parent
            font.pixelSize: 24
        }

        Timer {
            interval: 1000; running: true; repeat: true
            onTriggered: {
                time.text = Date().toString()
                time.color = Qt.rgba(Math.random(), Math.random(), Math.random(), 1)
            }
        }
    }



}
