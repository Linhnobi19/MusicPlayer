import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: root
    width: 1290
    height: 720
    visible: true
    title: qsTr("Media Player")
    // property int index: -1


    Header{
        id: header
        width: parent.width
        height: parent.height / 10

        onComeToList: {
            container.state = "listScreen";
        }

        onBackToMain: {
            container.state = "mainScreen"
        }
        onPauseList: {
            mainScreen.isPlaying = false;
        }
    }

    Rectangle{
        id: container
        width: parent.width
        height: parent.height - header.height
        anchors.top:  header.bottom
        MainScreen{
            id: mainScreen
            width: parent.width
            height: parent.height
            visible: true
        }

        ListSongScreen{
            id: listsongScreen
            width: parent.width
            height: parent.height
            visible: false
        }

        states: [
            State{
                name: "mainScreen"
                PropertyChanges {
                    target: mainScreen
                    visible: true
                    opacity: 1
                }
                PropertyChanges {
                    target: listsongScreen
                    visible: false
                    opacity: 0
                }
            },
            State{
                name: "listScreen"
                PropertyChanges {
                    target: mainScreen
                    visible: false
                    opacity: 0
                }
                PropertyChanges {
                    target: listsongScreen
                    visible: true
                    opacity: 1
                }
            }
        ]

        transitions: Transition
        {
            from: "*"
            to: "*"
            reversible: true
            SequentialAnimation{
                NumberAnimation{
                    property: "opacity"
                    duration: 500
                }
                NumberAnimation{
                    property: "visible"
                    duration: 100
                }

            }
        }


        Component.onCompleted: {
            container.state = "mainScreen"
        }
    }



}
