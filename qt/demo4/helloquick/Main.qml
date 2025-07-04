import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 300
    height: 200
    visible: true
    title: "嵌套矩形透明度"
    color: "white"

    // 外层红色矩形 (50%透明度)
    Rectangle {
        width: 100
        height: 100
        anchors.centerIn: parent
        opacity: 0.5   // 设置透明度为50%
        color: "red"   // 红色

        // 内层蓝色矩形 (完全不透明)
        Rectangle {
            x: 50      // 向右偏移50像素
            y: 50      // 向下偏移25像素
            width: 100
            height: 100
            color: "blue" // 蓝色
            //visible: false
            //enabled:false
        }
    }
}
