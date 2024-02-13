import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.15
import QtWebEngine 1.15

Window {
    id: root
    visible: true
    title: "ITBox"
    width: 640
    height: 480
    ColumnLayout {
        spacing: 30
        anchors.fill: parent

        Text {
            text: "ITBox"
            font.family: "Helvetica"
            font.pixelSize: 48
            color: "#3498db" // A nice shade of blue
            Layout.alignment: Qt.AlignHCenter 
        }

        TextField {
            id: search_string
            Layout.preferredWidth: parent.width * 0.8
            Layout.alignment: Qt.AlignHCenter 
        }
    }
}
