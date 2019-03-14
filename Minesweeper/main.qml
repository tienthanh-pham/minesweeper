import QtQuick 2.9

Item {
    width: 800
    height: 600
    property string mainSourceLoader: ""
    Loader {
        anchors.fill: parent
        source: mainSourceLoader
    }
}
