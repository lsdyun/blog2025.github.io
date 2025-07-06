import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    /*
    Rectangle {
        id: rect; width: 400; height: 300

        MouseArea {
            anchors.fill: parent
            onClicked: {
                rect.color = Qt.rgba(Math.random(),
                               Math.random(), Math.random())
            }
        }
    }
    */

    Rectangle {
        width: 400; height: 300

        SquareButton {
            anchors.centerIn: parent
            onDeactivated: console.log("Deactivated!")
            onActivated: (xPosition, yPosition)
                         => console.log("Activated at "
                                   + xPosition + "," + yPosition)
        }
    }


}
