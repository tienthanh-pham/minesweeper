import QtQuick 2.0

Item {
    width: 50
    height: 50

    property bool isBomb
    property int status
    property int value
    property var colorData: ["black", "#eccc68", "#ff7f50", "#ffa502", "#ff6348", "#e74c3c", "#c0392b", "#EA2027", "#0c2461", "transparent"]
    Rectangle {
        anchors.fill: parent
        color: (model.isOpen && value === 0) || mouseLeft.pressed ? "#E4E4E4" : "transparent"
        border.color: "#BDBDBD"
    }
    Text {
        anchors.centerIn: parent
        font.pixelSize: 24
        text: value ? value : "."
        visible: !isBomb && model.isOpen
        color: value == -1 ? "transparent" : colorData[value]
    }
    Image {
        anchors.centerIn: parent
        source: (isBomb && model.isOpen) ? "qrc:/res/bomb.png" : "qrc:/res/flag.png"
        visible: (isBomb && model.isOpen) || model.isFlag
    }
//    MouseArea {
//        id: mouseLeft
//        acceptedButtons: Qt.LeftButton
//        enabled: !model.isOpen && !model.isFlag
//        anchors.fill: parent
//        onClicked: {
//            appmain.hmiEvent(1, model.index);

//            if (isBomb) {
//                appmain.hmiEvent(2, "Gameover");
//            }
//        }
//    }
//    MouseArea {
//        acceptedButtons: Qt.RightButton
//        enabled: !model.isOpen
//        anchors.fill: parent
//        onClicked: {
//            appmain.hmiEvent(0, model.index + "," + (model.isFlag ? "0" : "1"));
//        }
//    }
    MouseArea {
        id: mouseLeft
        anchors.fill: parent
        onClicked: {
            if (!model.isOpen && !model.isFlag){
                appmain.hmiEvent(1, model.index)
            }

            if (isBomb) {
                appmain.hmiEvent(2, "Gameover");
            }
        }
        onPressAndHold: {
            if (!model.isOpen){
                appmain.hmiEvent(0, model.index + "," + (model.isFlag ? "0" : "1"));
            }
        }
    }
}
