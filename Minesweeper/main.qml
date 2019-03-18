import QtQuick 2.9

Item {
    anchors.fill: parent
//    width: 600
//    height: 720
    property string mainSourceLoader: ""
    Loader {
        anchors.fill: parent
        source: mainSourceLoader
    }
}
