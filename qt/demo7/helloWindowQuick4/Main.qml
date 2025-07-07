import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    /*
    ScrollView {
        width: 200; height: 200

        ListView {
            model: 20
            delegate: ItemDelegate {
                text: "Item " + index
                required property int index
            }
        }
    }
    */

    /*
    ScrollView {
        width: 200; height: 200
        Label { text: "ABC"; font.pixelSize: 224 }
    }
    */

    /*
    SplitView {
        id: splitView
        anchors.fill: parent; orientation: Qt.Horizontal

        Rectangle {
            implicitWidth: 200
            SplitView.maximumWidth: 400; color: "lightblue"
            Label { text: "View 1"; anchors.centerIn: parent }
        }
        Rectangle {
            id: centerItem
            SplitView.minimumWidth: 50; SplitView.fillWidth: true
            color: "lightgray"
            Label { text: "View 2"; anchors.centerIn: parent }
        }
        Rectangle {
            implicitWidth: 200; color: "lightgreen"
            Label { text: "View 3"; anchors.centerIn: parent }
        }
    }
    */

    /*
    ToolButton {
                    text: qsTr("弹窗"); onClicked: popup.open()
    }
    Popup {
        id: popup; width: 250; height: 150
        parent: Overlay.overlay; modal: true; focus: true
        x: Math.round((parent.width - width) / 2)
        y: Math.round((parent.height - height) / 2)

        Label {
            id: label; text: "这是个Popup"
            font.pixelSize: 16; font.italic: true
            x: Math.round((parent.width - width) / 2)
            y: Math.round((parent.height - height) / 2)
        }

        Button {
            text: "Ok"; onClicked: popup.close()
            anchors.top: label.bottom; anchors.topMargin: 10
            anchors.horizontalCenter: label.horizontalCenter
        }
    }
    */

    /*
    ToolButton {
        text: qsTr("弹窗"); onClicked: dialog.open()
    }
    Dialog {
        id: dialog
        title: "Title"
        anchors.centerIn: Overlay.overlay
        standardButtons: Dialog.Ok | Dialog.Cancel

        onAccepted: console.log("Ok clicked")
        onRejected: console.log("Cancel clicked")

        Label {
            text: "this is a dialog!"
        }
    }
    */

    /*
    Button {
        text: qsTr("Button")
        onClicked: dialog.open()
        ToolTip.visible: hovered
        ToolTip.text: qsTr("打开对话框")
        ToolTip.timeout: 10000
        ToolTip.delay: 500
    }
    */

    ToolBar {
        id: header
        width: parent.width
        Label {
            text: "My Application"
            anchors.centerIn: parent
        }
    }
    Drawer {
        id: drawer
        width: window.width * 0.6
        height: window.height - header.height
        y: header.height;


        //Label {
        //    text: "Content goes here!"
        //    anchors.centerIn: parent
        //}


        Label {
            id: content
            text: "Content"; font.pixelSize: 25; anchors.fill: parent
            verticalAlignment: Label.AlignVCenter
            horizontalAlignment: Label.AlignHCenter

            transform: Translate {
                x: drawer.position * content.width * 0.33
            }
        }

    }

    Button {
           text: "Open Drawer"
           onClicked: drawer.open()
    }

}
