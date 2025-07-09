import QtQuick
import QtQuick.Controls


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Button {
        id: control
        text: qsTr("按钮")  // 按钮显示的文本

        // 内容文本
        contentItem: Text {
            text: control.text  // 直接使用按钮的文本
            font: control.font  // 使用按钮的字体设置
            color: "white"      // 固定文本颜色为白色
            horizontalAlignment: Text.AlignHCenter // 水平居中
            verticalAlignment: Text.AlignVCenter   // 垂直居中
        }

        // 按钮背景
        background: Rectangle {
            implicitWidth: 100  // 默认宽度
            implicitHeight: 40  // 默认高度

            // 根据按钮状态改变背景颜色
            color: {
                if (!control.enabled) return "gray"  // 禁用状态
                if (control.pressed) return "darkgreen"  // 按下状态
                if (control.hovered) return "green"  // 悬停状态
                return "lightgreen"  // 默认状态
            }
        }
    }


}





