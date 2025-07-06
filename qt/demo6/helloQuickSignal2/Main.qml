import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    /*
    Rectangle {
        id: rect; width: 400; height: 300

        MouseArea {
            id: mouseArea
            anchors.fill: parent
        }

        Connections {
            target: mouseArea
            function onClicked() {
                rect.color = "red"
            }
        }
    }
    */
    /*
    Rectangle {
        id: relay

        signal messageReceived(string person, string notice)

        Component.onCompleted: {
            relay.messageReceived.connect(sendToPost)
            relay.messageReceived.connect(sendToTelegraph)
            relay.messageReceived("Tom", "Happy Birthday")
        }

        function sendToPost(person, notice) {
            console.log("Sending to post: " + person + ", " + notice)
        }
        function sendToTelegraph(person, notice) {
            console.log("Sending to telegraph: " + person + ", " + notice)
        }
    }
    */
    Rectangle {
        id: forwarder; width: 400; height: 300

        signal send()
        onSend: console.log("Send clicked")

        MouseArea {
            id: mouseArea; anchors.fill: parent
            onClicked: console.log("MouseArea clicked")
        }

        Component.onCompleted: {
            mouseArea.clicked.connect(send)
        }
    }



}
