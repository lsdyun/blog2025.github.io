import QtQuick
import QtQuick.Dialogs
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Window {
    width: 640; height: 480; visible: true

    Button {
        text: qsTr("消息对话框")
        onClicked: dlg.open()
    }

    MessageDialog {
        id: dlg
        title: qsTr("消息对话框")
        text: qsTr("这里是text的内容")
        informativeText: qsTr("这里是informativeText的内容")
        detailedText: qsTr("这里是detailedText的内容")
        buttons: MessageDialog.Ok | MessageDialog.Cancel
        onAccepted: console.log("ok")
    }
}


/*
Window {
    width: 640; height: 480; visible: true

    Image {
        id: image; anchors.fill: parent
        fillMode: Image.PreserveAspectFit
    }

    Button {
        text: qsTr("Choose Image...")
        onClicked: fileDialog.open()
    }

    FileDialog {
        id: fileDialog
        nameFilters: ["Image files (*.png *.jpg)"]
        currentFolder: StandardPaths.writableLocation
                       (StandardPaths.PicturesLocation)
        acceptLabel: qsTr("选择图片")
        onAccepted: image.source = selectedFile
    }
}
*/

/*
Window {
    width: 800; height: 600; visible: true

    RowLayout {
        Button {
            text: qsTr("颜色对话框")
            onClicked: colorDialog.open()
        }
        Label { id: label; text: qsTr("颜色展示")}
    }

    ColorDialog {
        id: colorDialog
        selectedColor: label.color
        options: ColorDialog.ShowAlphaChannel
        onAccepted: label.color = selectedColor
    }
}
*/
