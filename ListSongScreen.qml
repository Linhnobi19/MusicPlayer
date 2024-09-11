import QtQuick 2.15
import "CommonItem"
import QtQuick.Controls 2.15

Rectangle {
    // color: "red"
    id: root

    property alias currentIndex: listSong.currentIndex
    property int textSize: 25
    property string textColor: "black"
    property int myIndex: -1

    Image {
        id: name
        width: parent.width
        height: parent.height
        source: "qrc:Image/background.jpg"
        fillMode: Image.PreserveAspectCrop
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            inputText.focus = false;
        }
    }

    Rectangle{
        id: titleSearch
        width: parent.width / 2
        height: 60
        radius: 20
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        border.color: inputText.focus ? "#E8B86D" : "black"
        border.width: 5

        color: "transparent"
        Row{
            spacing: 20
            anchors.fill: parent
            TextField{
                id: inputText
                width: parent.width - 70
                height: parent.height
                color: "white"
                focus: true
                background: Rectangle{
                    width: parent.width
                    height: parent.height
                    color: "Transparent"
                    radius: 15
                }
                clip: true
                leftPadding: 20

                placeholderText: "Enter name song"
                font.pointSize: 18
                onTextChanged: {
                    if(text != ""){
                        listSong.model = controller.searchSong(text);
                        listSong.currentIndex = root.myIndex;
                    }
                    else{
                        listSong.model = controller.model.playlist
                        listSong.currentIndex = root.myIndex;
                    }
                }
            }

            Image{
                width: 40
                height: 40
                source: "qrc:/Image/loupe.png"
                anchors.verticalCenter: parent.verticalCenter
            }

        }
    }

    Connections{
        target: controller
        function onFindSong(index) {
            // signal is emit before assign model so need to store in variable
            root.myIndex = index;
        }
        function onChangeSong() {
            if(inputText.text == ""){
                listSong.currentIndex = controller.currentIndex;
            }
        }
    }


    ListView {
        id: listSong
        width: parent.width
        height: parent.height - 50
        anchors.top: titleSearch.bottom
        anchors.topMargin: 30

        highlight: Rectangle{
            color: "#98DED9"
            opacity: 0.5
            radius: 20
        }


        model: controller.model.playlist
        clip: true

        property int isCurrent: 0

        delegate: Rectangle{
            id: container
            width: parent.width
            height: 80
            color: "Transparent"
            property bool stopped: true

            onStoppedChanged: {
                if(!stopped){
                    sourceTitle.trigger();
                }
                else{
                    sourceTitle.complete();
                    songTitle.complete();
                    singerTitle.complete();
                }
            }

            MouseArea{
                id: mouseSecond
                hoverEnabled: true
                anchors.fill: container

                onClicked: {
                    root.currentIndex = index;
                    inputText.focus = false;
                    controller.playRandom(-1, modelData.source);
                }

                onEntered: {
                    container.stopped = false;
                }
                onExited: {
                    container.stopped = true;
                }
            }

            MovingText{
                id: sourceTitle
                width: parent.width * 2 / 5
                height: parent.height
                anchors.left: parent.left
                anchors.leftMargin: 20
                textColor: listSong.currentIndex == index ? "red" : "white"

                textShow: modelData.source

                onNext: {
                    sourceTitle.complete();
                    singerTitle.complete();
                    if(!container.stopped || listSong.currentIndex ==  index){
                        songTitle.trigger();
                    }
                    // songTitle.trigger();

                }
            }

            MovingText{
                id: songTitle
                width: parent.width * 1 / 5
                height: parent.height
                anchors.left: sourceTitle.right
                anchors.leftMargin: 20
                textColor: listSong.currentIndex == index ? "red" : "white"

                textShow: modelData.title

                onNext: {
                    sourceTitle.complete();
                    songTitle.complete();
                    if(!container.stopped || listSong.currentIndex ==  index){
                        singerTitle.trigger();
                    }

                }
            }

            MovingText{
                id: singerTitle
                width: parent.width * 1 / 5
                height: parent.height
                anchors.left: songTitle.right
                anchors.leftMargin: 20
                textColor: listSong.currentIndex == index ? "red" : "white"

                textShow: modelData.singer

                onNext: {
                    singerTitle.complete();
                    songTitle.complete();
                    if(!container.stopped || listSong.currentIndex ==  index){
                        sourceTitle.trigger();
                    }

                }
            }



            AnimatedImage{
                id: isPlayingGif
                width: 100
                height: parent.height - 20
                anchors.top: parent.top
                anchors.right: parent.right
                anchors.rightMargin: 20
                source: "qrc:Image/playing.gif"
                visible: root.currentIndex == index

            }
            Rectangle{
                id: straightLine
                width: parent.width - 50
                height: 2
                anchors.bottom: parent.bottom
                color: "lightblue"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottomMargin: 10
            }

        }


        Component.onCompleted: {
            listSong.currentIndex = controller.currentIndex;
        }
    }
}

