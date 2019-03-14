import QtQuick 2.0

import "qrc:/qml/unit"

Item {
    GridView {
        anchors.centerIn: parent
        width: Math.sqrt(listModel.rowCount()) * cellWidth
        height: width
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
