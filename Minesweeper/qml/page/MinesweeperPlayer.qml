import QtQuick 2.0

import "qrc:/qml/unit"

Item {
    anchors.centerIn: parent
    GridView {
        anchors.centerIn: parent
        width: widthCount * cellWidth
        height: heightCount * cellWidth
        cellWidth: 50
        cellHeight: cellWidth
        boundsBehavior: Flickable.StopAtBounds
        model: listModel
        delegate: Box {
            value: model.value
            isBomb: model.isBomb
        }
    }
}
