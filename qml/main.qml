import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.15
import QtQuick.Dialogs 1.3

Window {
    id: root
    visible: true
    title: "ITBox"
    width: 640
    height: 480
    ColumnLayout {
		id: layout
        spacing: 30
        anchors.fill: parent

        Text {
            text: "ITBox"
            font.family: "Helvetica"
            font.pixelSize: 48
            color: "#3498db" // A nice shade of blue
            Layout.alignment: Qt.AlignHCenter 
        }
		
		RowLayout{
			id: rowSearching
			Layout.alignment: Qt.AlignHCenter
			spacing: 4
			TextField {
				id: search_string
				//Layout.preferredWidth: parent.width * 0.8	
			}
        	
        	Button {
				text: "Open Directory"
				onClicked: fileDialog.open()
			}
        			
			Button {
				text: "Search"
				//onClicked: fileDialog.open()
			}
		}
		
		
		
		FileDialog {
			id: fileDialog
			title: "Select Folder"
			folder: shortcuts.home
			selectFolder: true
			onAccepted: {
				console.log("Selected Folder:", fileDialog.folder)
				search_string.text = fileDialog.folder
			}
			onRejected: {
				console.log("Canceled")
			}
		}

    }
}
