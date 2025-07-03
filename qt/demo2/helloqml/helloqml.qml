import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Text {
        id: text1
        text: qsTr("HEllo World! 你好QT！")
        anchors.centerIn: parent
    }
}
