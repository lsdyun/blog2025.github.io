import QtQuick 2.15

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

    Image {
        id: logo
        width :100
        height: 100
        source: "qrc:/images/test.png"
        anchors.horizontalCenter: text1.horizontalCenter
        anchors.top: text1.bottom
        anchors.topMargin: 10
    }

    MyText{
        anchors.top: logo.bottom
        anchors.horizontalCenter: logo.horizontalCenter
    }
}
