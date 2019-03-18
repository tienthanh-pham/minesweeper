import QtQuick 2.0

Item {
    //anchors.fill: parent
    width: 200
    height: 180
    Image {
        id: bg
        anchors.fill: parent
        source: "qrc:/res/game_over.jpg"
    }
    Text {
        id: txtNoty
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        font.pixelSize: 30
        text: "Press to play again!"
        Behavior on color {
            SequentialAnimation {
                loops: Animation.Infinite
                ColorAnimation { from: "white"; to: "red"; duration: 500 }
                ColorAnimation { from: "red"; to: "white";  duration: 500 }
            }
        }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            appmain.hmiEvent(3, "restart")
        }
    }
    Component.onCompleted: txtNoty.color = "blue"
}
