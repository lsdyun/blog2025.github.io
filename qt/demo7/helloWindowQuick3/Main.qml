import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")


    SwipeView {
        id: view; anchors.fill: parent

        Page {
            title: qsTr("页面1")
            header: ToolBar{
                RowLayout {
                    anchors.fill: parent;
                    ToolButton { text: qsTr("按钮1") }
                    ToolButton { text: qsTr("按钮2") }
                }
            }
            footer: ToolBar{
                Label { text: qsTr("工具栏");
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }
        Page {
            title: qsTr("页面2")
            //...
            header: ToolBar{
                RowLayout {
                    anchors.fill: parent;
                    ToolButton { text: qsTr("选项1") }
                    ToolButton { text: qsTr("选项2") }
                }
            }
            footer: ToolBar{
                Label { text: qsTr("工具栏");
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }
    }

    PageIndicator {
            currentIndex: view.currentIndex;  count: view.count
            anchors.bottom: view.bottom; anchors.bottomMargin: 30
            anchors.horizontalCenter: view.horizontalCenter
    }


}
