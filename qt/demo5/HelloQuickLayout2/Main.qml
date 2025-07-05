import QtQuick
import QtQuick.Layouts

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    /*
    Item {
        width: 250; height: 300

        Rectangle{
            id: rect1; x:10; y:20
            width: 100; height: 100; color: "lightgrey"
            Text { text: "rect1"; anchors.centerIn: parent }
        }
        Rectangle{
            id: rect2
            width: 100; height: 100; color: "black"
            anchors.left: rect1.right
            Text { text: "rect2"; color: "white"; anchors.centerIn: parent }
        }
    }
    */
    /*
    RowLayout {
        id: layout; anchors.fill: parent; spacing: 6
        Rectangle {
            color: 'lightgrey'
            Layout.fillWidth: true; Layout.minimumWidth: 50
            Layout.preferredWidth: 100; Layout.maximumWidth: 300
            Layout.minimumHeight: 150
            Text {
                anchors.centerIn: parent
                text: parent.width + 'x' + parent.height
            }
        }

        Rectangle {
            color: 'black'
            Layout.fillWidth: true; Layout.minimumWidth: 100
            Layout.preferredWidth: 200; Layout.preferredHeight: 100
            Text {
                anchors.centerIn: parent; color: "white"
                text: parent.width + 'x' + parent.height
            }
        }
    }
    */
    StackLayout {
        id: layout; anchors.fill: parent; currentIndex: 1

        Rectangle {
            color: 'teal'; implicitWidth: 200; implicitHeight: 200
        }
        Rectangle {
            color: 'plum'; implicitWidth: 300; implicitHeight: 200
        }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (layout.currentIndex === 1)
                layout.currentIndex = 0;
            else
                layout.currentIndex = 1
        }
    }


}
