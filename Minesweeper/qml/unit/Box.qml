import QtQuick 2.0

Item {
    width: 50
    height: 50
    property bool isBomb
    property int status
    property int value
    Rectangle {
        anchors.fill: parent
        color: "transparent"
        border.color: "lightgray"
    }
    Text {
        anchors.centerIn: parent
        font.pixelSize: 24
        text: value
        visible: !isBomb
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            appmain.hmiEvent(model.index, "changevalue");
        }
    }
}
