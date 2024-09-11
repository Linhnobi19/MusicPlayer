import QtQuick 2.15
import "CommonItem"
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3

Item {
    id: root
    width: 100
    height: 100

    property bool inList: false
    signal comeToList();
    signal backToMain();
    property string direction: ""
    signal pauseList();

    Rectangle{
        id: header
        width: parent.width
        height: parent.height
        color: "black"

        property string hours
        property string minutes
        property string day
        property string month
        property string typeHour

        function updateTime(){
            var dateTime = new Date();
            hours = dateTime.getHours();
            minutes = dateTime.getMinutes();
            day = dateTime.getUTCDate();
            // day = dateTime.get
            month = dateTime.getUTCMonth() + 1;

            typeHour = hours > 12 ? "PM" : "AM";
            hours = hours > 12 ? hours - 12 : hours;
            hours = hours > 9 ? hours : "0" + hours;
            minutes = minutes > 9 ? minutes : "0" + minutes;
            // console.log(dateTime.getMonth());
        }


        Timer{
            repeat: true
            running: true
            interval: 1000
            onTriggered: {
                header.updateTime();
            }
        }

        Component.onCompleted: {
            header.updateTime();
        }

        Row{
            width: parent.width / 3
            height: parent.height - 10
            spacing: 10
            anchors.verticalCenter: parent.verticalCenter
            leftPadding: 20

            MyButton{
                id: returnButton
                height: parent.height
                interact: false
                source: "qrc:Image/StatusButton/return.png"

                onClickButton: {
                    root.backToMain();
                    root.inList = false;
                    interact = false;
                    console.log("return");
                }
            }

            MyButton{
                height: parent.height
                interact: false
                source: "qrc:Image/StatusButton/home.png"
            }

            MyButton{
                id: listButton
                height: parent.height
                visible: !inList
                source: "qrc:Image/StatusButton/list.png"
                onClickButton: {
                    root.comeToList();
                    root.inList = true
                    returnButton.interact = true
                }
            }

        }


        Rectangle{
            id: time
            width: 100
            height: parent.height
            anchors.centerIn: parent
            color: "transparent"

            Text{
                id: timeId
                color: "white"
                font.pointSize: 15
                font.bold: true
                text: header.hours + ":" + header.minutes + " " + header.typeHour
                anchors.centerIn: parent
            }

            Text{
                id: dateId
                color: "white"
                font.pointSize: 12
                text: header.day + "." + header.month
                anchors.left: parent.right
                anchors.leftMargin: 20
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        MyButton{
            id: folderChoosing
            height: parent.height - 10
            source: "qrc:Image/StatusButton/folder.png"
            anchors.right: parent.right
            anchors.rightMargin: 20
            anchors.verticalCenter: parent.verticalCenter
            visible: !inList

            onClickButton: {
                folderSection.open();
            }
        }

        FileDialog{
            id: folderSection
            title: "Choosing folder to load music"
            selectFolder: true

            onAccepted: {
                root.direction = folder
                root.direction = root.direction.substring(8);
                console.log(root.direction);

                controller.setPlaylist(root.direction);
                controller.savePath(root.direction);
                root.pauseList();
            }
            onRejected: {
                folderSection.close();
                root.direction = ""
            }
        }
    }
}
