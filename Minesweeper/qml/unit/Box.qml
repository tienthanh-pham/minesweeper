import QtQuick 2.0

Item {
    width: 50
    height: 50

    property bool isBomb
    property bool isOpen
    property bool isFlag
    property int index
    property int status
    property int value
    property var colorData: ["black", "#eccc68", "#ff7f50", "#ffa502", "#ff6348", "#e74c3c", "#c0392b", "#EA2027", "#0c2461", "transparent"]

    function openBox() {
        if (!isOpen && !isFlag){
            appmain.hmiEvent(1, index)
        }
        if (isBomb) {
            appmain.hmiEvent(2, "Gameover");
        }
    }
    function pinFlag() {
        if (!isOpen){
            appmain.hmiEvent(0, index + "," + (isFlag ? "0" : "1"));
        }
    }

    Rectangle {
        anchors.fill: parent
        color: (isOpen && value === 0) || mouseLeft.pressed ? "#E4E4E4" : "transparent"
        border.color: "#BDBDBD"
    }
    Text {
        anchors.centerIn: parent
        font.pixelSize: 24
        text: value ? value : "."
        visible: !isBomb && isOpen
        color: value == -1 ? "transparent" : colorData[value]
    }
    Image {
        anchors.centerIn: parent
        source: (isBomb && isOpen) ? "qrc:/res/bomb.png" : "qrc:/res/flag.png"
        visible: (isBomb && isOpen) || isFlag
    }
    MouseArea {
        id: mouseLeft
        acceptedButtons: Qt.LeftButton
        anchors.fill: parent
        onClicked: openBox()
        onPressAndHold: pinFlag()
    }
    MouseArea {
        acceptedButtons: Qt.RightButton
        anchors.fill: parent
        onClicked: pinFlag()
    }
}
