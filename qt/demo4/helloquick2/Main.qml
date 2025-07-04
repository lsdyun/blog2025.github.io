import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
//import Qt.labs.calendar 1.0

Window {
    width: 500
    height: 700
    visible: true
    title: "演示"

    // 日历组件 - 核心代码只有这一个组件
    /*
    Calendar {
        anchors.centerIn: parent
        width: 300
        height: 250

        // 设置中文显示
        locale: Qt.locale("zh_CN")

        // 基本日期单元格样式
        delegate: Rectangle {
            width: parent.width / 7
            height: parent.height / 6

            // 背景色（选中日期为绿色）
            color: model.date.getTime() === selectedDate.getTime() ? "lightgreen" : "white"

            // 日期文本
            Text {
                anchors.centerIn: parent
                text: model.day
                color: "black"
            }

            // 点击选择日期
            MouseArea {
                anchors.fill: parent
                onClicked: selectedDate = model.date
            }
        }
    }
    */


    // 5. Tumbler 控件 (旋转选择器)
    /*
    GroupBox {
        title: "5. Tumbler (旋转选择器)"
        Layout.fillWidth: true

        ColumnLayout {
            anchors.fill: parent
            spacing: 15

            Tumbler {
                id: tumbler
                Layout.alignment: Qt.AlignHCenter
                model: 10
                visibleItemCount: 3

                // 自定义样式
                delegate: Text {
                    text: index + 1
                    font.pixelSize: 20
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    opacity: 0.4 + Math.max(0, 1 - Math.abs(Tumbler.displacement)) * 0.6
                }

                // 背景样式
                background: Rectangle {
                    color: "#E0E0E0"
                    radius: 5
                }
            }

            Text {
                Layout.alignment: Qt.AlignHCenter
                text: `当前选择: ${tumbler.currentIndex + 1}`
                font.bold: true
            }
        }
    }
    */

    // 4. TextField 控件 (文本输入框)
    /*
    GroupBox {
        title: "4. TextField (文本输入框)"
        Layout.fillWidth: true

        ColumnLayout {
            anchors.fill: parent
            spacing: 15

            TextField {
                id: textField
                Layout.fillWidth: true
                placeholderText: "请输入文本..."
                selectByMouse: true // 允许鼠标选择文本

                // 输入验证（只允许数字）
                validator: IntValidator {
                    bottom: 0
                    top: 100
                }

                // 自定义背景
                background: Rectangle {
                    border.color: textField.focus ? "#4CAF50" : "#9E9E9E"
                    border.width: 2
                    radius: 5
                }
            }

            RowLayout {
                Layout.fillWidth: true

                Button {
                    text: "复制"
                    onClicked: textField.selectAll()
                }

                Button {
                    text: "粘贴"
                    onClicked: textField.paste()
                }

                Button {
                    text: "清空"
                    onClicked: textField.clear()
                }
            }

            Text {
                Layout.alignment: Qt.AlignHCenter
                text: `输入内容: ${textField.text}`
                font.bold: true
            }
        }
    }
    */

    // 3. Slider 控件 (滑块)
    /*
    GroupBox {
        title: "3. Slider (滑块)"
        Layout.fillWidth: true

        ColumnLayout {
            anchors.fill: parent
            spacing: 15

            Slider {
                id: slider
                Layout.fillWidth: true
                value: 50
                from: 0
                to: 100
                stepSize: 1

                // 自定义滑块样式
                handle: Rectangle {
                    x: slider.visualPosition * (slider.width - width)
                    y: (slider.height - height) / 2
                    width: 20
                    height: 20
                    radius: 10
                    color: slider.pressed ? "#4CAF50" : "#FFFFFF"
                    border.color: "#9E9E9E"
                    border.width: 1
                }
            }

            Text {
                Layout.alignment: Qt.AlignHCenter
                text: `当前值: ${slider.value.toFixed(0)}`
                font.bold: true
            }
        }
    }
    */


    // RangeSlider 控件 (范围滑块)
    /*
    GroupBox {
        title: "RangeSlider (范围滑块)"
        Layout.fillWidth: true

        ColumnLayout {
            anchors.fill: parent
            spacing: 15

            RangeSlider {
                id: rangeSlider
                Layout.fillWidth: true
                from: 0
                to: 100
                stepSize: 1

                first.value: 25
                second.value: 75

                // 自定义轨道样式
                background: Rectangle {
                    height: 6
                    radius: 3
                    color: "#E0E0E0"

                    Rectangle {
                        x: rangeSlider.first.visualPosition * parent.width
                        width: rangeSlider.second.visualPosition * parent.width - x
                        height: parent.height
                        color: "#4CAF50"
                        radius: 3
                    }
                }
            }

            RowLayout {
                Layout.fillWidth: true

                Text {
                    text: `最小值: ${rangeSlider.first.value.toFixed(0)}`
                    Layout.alignment: Qt.AlignLeft
                }

                Text {
                    text: `最大值: ${rangeSlider.second.value.toFixed(0)}`
                    Layout.alignment: Qt.AlignRight
                }
            }

            Text {
                Layout.alignment: Qt.AlignHCenter
                text: `范围: ${rangeSlider.first.value.toFixed(0)} - ${rangeSlider.second.value.toFixed(0)}`
                font.bold: true
            }
        }
    }
    */


    /*
    Column {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 30

        // 1. 页面指示器 (PageIndicator)
        Text {
            text: "1. 页面指示器 (PageIndicator)";
            font.bold: true
        }

        SwipeView {
            id: swipeView
            width: parent.width
            height: 150

            Rectangle { color: "#e3f2fd"; Text { anchors.centerIn: parent; text: "页面1" } }
            Rectangle { color: "#e8f5e9"; Text { anchors.centerIn: parent; text: "页面2" } }
            Rectangle { color: "#fff3e0"; Text { anchors.centerIn: parent; text: "页面3" } }
        }

        PageIndicator {
            anchors.horizontalCenter: parent.horizontalCenter
            count: swipeView.count
            currentIndex: swipeView.currentIndex
        }

        // 2. 滚动条 (ScrollBar)
        Text {
            text: "2. 滚动条 (ScrollBar)";
            font.bold: true
        }

        ScrollView {
            width: parent.width
            height: 150
            // 正确设置滚动条策略
            ScrollBar.vertical.policy: ScrollBar.AlwaysOn

            TextArea {
                text: "这是一个带有滚动条(ScrollBar)的文本区域\n\n" +
                      "向下滚动查看更多内容...\n\n".repeat(10)
                readOnly: true
                wrapMode: Text.Wrap
            }
        }

        // 3. 滚动指示器 (ScrollIndicator) - 修正版
        Text {
            text: "3. 滚动指示器 (ScrollIndicator)";
            font.bold: true
        }

        // 使用 Flickable 而不是 ScrollView 来正确使用 ScrollIndicator
        Flickable {
            width: parent.width
            height: 150
            contentWidth: width
            contentHeight: textContent.height
            clip: true

            // 滚动指示器
            ScrollIndicator.vertical: ScrollIndicator {}

            // 可滚动内容
            Text {
                id: textContent
                width: parent.width
                text: "这是一个带有滚动指示器(ScrollIndicator)的文本区域\n\n" +
                      "向下滚动查看更多内容...\n\n".repeat(10)
                wrapMode: Text.Wrap
            }
        }
    }
    */


    /*
    SpinBox {
        id: spinBox
        from: 0; to: items.length - 1
        value: 1 // "Medium"
        property var items: ["Small", "Medium", "Large"]

        validator: RegularExpressionValidator {
            regularExpression: new RegExp("(Small|Medium|Large)", "i")
        }

        textFromValue: function(value) {
            return items[value];
        }

        valueFromText: function(text) {
            for (var i = 0; i < items.length; ++i) {
                if (items[i].toLowerCase().indexOf(text.toLowerCase())
                                                                  === 0)
                    return i
            }
            return spinBox.value
        }
    }
    */

    /*
    ScrollView {
        id: view
        anchors.fill: parent
        TextArea {
            placeholderText: qsTr("可以在这里输入内容")
            wrapMode: Text.WordWrap
        }
    }
    */

    // 使用行布局
    /*
    RowLayout {
        anchors.fill: parent
        spacing: 10
        anchors.margins: 10

        // 1. 普通按钮
        Button {
            text: qsTr("普通按钮")
            onClicked: {
                console.log("普通按钮被点击");
                close();
            }
        }

        // 2. 扁平按钮
        Button {
            text: qsTr("扁平按钮")
            flat: true
            onClicked: console.log("扁平按钮被点击")
        }

        // 3. 高亮按钮
        Button {
            text: qsTr("高亮按钮")
            highlighted: true
            onClicked: console.log("高亮按钮被点击")
        }

        // 4. 圆角按钮
        RoundButton {
            text: qsTr("圆角按钮")
            radius: 10
            onClicked: console.log("圆角按钮被点击")
        }

        // 5. 圆形按钮
        RoundButton {
            text: qsTr("圆形")
            implicitWidth: 60
            implicitHeight: 60
            radius: width / 2
            onClicked: console.log("圆形按钮被点击")
        }
    }
    */

    /*
    ColumnLayout {
        ButtonGroup {
            id: childGroup      // 按钮组ID
            // 关键属性1：是否互斥（这里设置为false表示可以多选）
            exclusive: false;
            // 关键属性2：绑定父复选框的状态
            // 当子复选框状态变化时，这个属性会自动更新
            checkState: parentBox.checkState
        }
        // 父复选框
        CheckBox {
            id: parentBox;      // 父复选框ID
            text: qsTr("Parent");   // 显示文本
            // 关键属性：绑定到子按钮组的状态
            // 当父复选框被点击时，这个绑定会更新所有子复选框
            checkState: childGroup.checkState
            // 设置字体加粗
            font.bold: true
        }
        // 子复选框1
        CheckBox {
            checked: true       // 默认选中
            text: qsTr("Child 1")    // 显示文本
            // 关键属性1：左侧缩进（缩进量等于复选框宽度，创建层次感）
            leftPadding: indicator.width;
            // 关键属性2：指定所属按钮组
            ButtonGroup.group: childGroup
        }
        // 子复选框2
        CheckBox {
            text: qsTr("Child 2");
            leftPadding: indicator.width
            ButtonGroup.group: childGroup
        }
    }
    */

    /*
    RowLayout {
        DelayButton {
            text: qsTr("延迟按钮"); delay: 1000
            onActivated: text = qsTr("已启动")
        }

        Switch {
            text: qsTr("Wi-Fi")
            onToggled: console.log(checked)
        }
    }
    */

    /*
    ColumnLayout {
        anchors.centerIn: parent
        spacing: 15

        // 创建按钮组
        ButtonGroup {
            id: radioGroup
            // 选中项改变时触发
            onClicked: console.log("当前选择:", button.text)
        }

        // 创建单选按钮
        RadioButton {
            text: "选项1"
            ButtonGroup.group: radioGroup
        }
        RadioButton {
            text: "选项2"
            ButtonGroup.group: radioGroup
            checked: true // 默认选中
        }
        RadioButton {
            text: "选项3"
            ButtonGroup.group: radioGroup
        }

        // 显示当前选择
        Label {
            text: "当前选择: " + (radioGroup.checkedButton ? radioGroup.checkedButton.text : "无")
        }
    }
    */

    /*
    Pane {
        width: 400; height: 300
        Image {
            id: image; anchors.fill: parent
            source: "https://www.qter.org/temp/back.png"
        }
        BusyIndicator {
            id:busy
            anchors.horizontalCenter:
                            parent.horizontalCenter
            anchors.verticalCenter:
                            parent.verticalCenter
            running: image.status === Image.Loading
        }
        ProgressBar {
            visible: image.status === Image.Loading
            value: image.progress
        }
    }
    */

    /*
    Item {
        width: 200; height: 300

        ComboBox {
            x:10; y:10
            editable: true
            model: ListModel {
                id: model
                ListElement { text: "Banana" }
                ListElement { text: "Apple" }
                ListElement { text: "Coconut" }
            }
            onAccepted: {
                if (find(editText) === -1)
                    model.append({text: editText})
            }
        }
    }
    */

    /*
    Item {
        width: 100; height: 120

        Dial {
            id: dial
            from: 1; to: 10
            stepSize: 1; wrap: true
        }
        Label {
            anchors.top: dial.bottom
            text: dial.value
        }
    }
    */
}

