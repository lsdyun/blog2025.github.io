import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    /*
    Row {
        spacing: 2; padding: 5

        Rectangle { color: "white"; border.width: 1;
                                  width: 50; height: 50 }
        Rectangle { color: "green"; width: 20; height: 50 }
        Rectangle { color: "lightgrey"; width: 50; height: 20 }
    }
    */
    /*
    Grid {
        columns: 3; spacing: 2; padding: 5
        Rectangle { color: "white"; border.width: 1;
                    width: 50; height: 50 }
        Rectangle { color: "green"; width: 20; height: 50 }
        Rectangle { color: "lightgrey"; width: 50; height: 20 }
        Rectangle { color: "cyan"; width: 50; height: 50 }
        Rectangle { color: "magenta"; width: 10; height: 10 }
    }
    */
    /*
    Rectangle {
        color: "lightblue"; width: 300; height: 200
        Flow {
            anchors.fill: parent;
            anchors.margins: 4; spacing: 10

            Text { text: "Text"; font.pixelSize: 40 }
            Text { text: "items"; font.pixelSize: 40 }
            Text { text: "flowing"; font.pixelSize: 40 }
            Text { text: "inside"; font.pixelSize: 40 }
            Text { text: "a"; font.pixelSize: 40 }
            Text { text: "Flow"; font.pixelSize: 40 }
            Text { text: "item"; font.pixelSize: 40 }
        }
    }
    */
    /*
    Column {  // 垂直布局容器
        spacing: 2  // 子项间距
        Rectangle { color: "red"; width: 50; height: 50 }
        Rectangle {
            id: greenRect    // 标识符用于引用
            color: "green"
            width: 20; height: 50
        }
        Rectangle { color: "blue"; width: 50; height: 20 }

        move: Transition {  // 移动动画效果
            NumberAnimation { properties: "x,y"; duration: 1000 }   // 1秒动画
    }
        focus: true  // 获取键盘焦点
        Keys.onSpacePressed: greenRect.visible = !greenRect.visible  // 空格切换可见性
    }
    */

    /*
    Grid {
        padding: 5

        Repeater {
            model: 16
            Rectangle {
                id: rect; width: 40; height: 40; border.width: 1
                color: Positioner.isFirstItem ?
                                 "yellow" : "lightsteelblue"

                Text { text: rect.Positioner.index;
                       anchors.centerIn: parent }
            }
        }
    }
    */

    /*
    Rectangle {
        width: 400; height: 240; color: "black"
        Grid {
            x: 5; y: 5; rows: 5; columns: 5; spacing: 10
            Repeater {
                model: 12
                Rectangle {
                    width: 70; height: 70; color: "lightgreen"
                    Text {
                        text: index; font.pointSize: 30
                        anchors.centerIn: parent
                    }
                }
            }
        }
    }
    */






}
