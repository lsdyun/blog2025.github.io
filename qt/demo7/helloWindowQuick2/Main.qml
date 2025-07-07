import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 400; height: 300; visible: true

    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: (mouse) => {
            if (mouse.button === Qt.RightButton)
                contextMenu.popup()
        }

        Menu {
            id: contextMenu
            MenuItem { text: qsTr("Cut") }
            MenuItem { text: qsTr("Copy") }
            MenuItem { text: qsTr("Paste") }
        }
    }

    Button {
        id: fileButton
        text: "File"; x: 0; y: 0
        onClicked: menu.open()

        Menu {
            id: menu
            y: fileButton.height

            MenuItem { text: qsTr("New...") }
            MenuItem { text: qsTr("Open...") }
            MenuItem { text: qsTr("Save") }
        }
    }

    GroupBox {
        contentWidth: 150; contentHeight: 80
        x: 50; y: 50

        label: CheckBox {
            id: checkBox
            checked: true; text: qsTr("Synchronize")
        }
        ColumnLayout {
            anchors.fill: parent; anchors.topMargin: 10
            enabled: checkBox.checked
            CheckBox { text: qsTr("E-mail") }
            CheckBox { text: qsTr("Calendar") }
            CheckBox { text: qsTr("Contacts") }
        }
    }


}

