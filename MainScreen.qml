import QtQuick 2.15
import "CommonItem"
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtMultimedia 5.15
import QtGraphicalEffects 1.15

Rectangle {
    id: root
    width: 500
    height: 500

    property string nameSong: ""
    property string albumSong: ""

    property bool isRandom: false
    property bool isLoops: false

    property bool isPlaying: false
    property string isplayButton: isPlaying ? "qrc:Image/PlayingButton/play_button.png"
                                            :"qrc:Image/PlayingButton/pause_button.png"

    property int titleWidth: 0

    property int currentIndex: -1
    signal changeCurrent(index : int);
    signal updateSource();

    property string source: ""

    onIsPlayingChanged: {
        if(isPlaying){
            isplayButton = "qrc:Image/PlayingButton/play_button.png";
        }
        else {
            isplayButton = "qrc:Image/PlayingButton/pause_button.png";
        }
    }

    onIsRandomChanged: {
        if(isRandom){
            randomButtom.source = "qrc:Image/PlayingButton/shuffle.png";
        }
        else {
            randomButtom.source = "qrc:Image/PlayingButton/shuffle (1).png";
        }
    }

    onIsLoopsChanged: {
        if(!isLoops){
            loopButtom.source = "qrc:Image/PlayingButton/refresh (1).png";
        }
        else {
            loopButtom.source = "qrc:Image/PlayingButton/refresh.png";
        }
    }

    onUpdateSource: {
        root.nameSong = songList.title;
        root.albumSong = songList.album;

        isPlaying = true;

        songTitle.complete();
        albumTitle.complete();
        songTitle.trigger();

    }

    onChangeCurrent: {
        songList.indexPath = index;
        root.updateSource();
        controller.playRandom(index);
    }


    // background of mediaplayer
    Image {
        id: name
        width: parent.width
        height: parent.height
        source: "file:///" + songList.art
        fillMode: Image.PreserveAspectCrop
    }
    FastBlur{
        source: name
        radius: 32
        anchors.fill: name
    }


    // text of name song and album on the left side
    Rectangle{
        id: songInfo
        width: root.width / 2 - 50
        height: root.height * 3 / 5
        anchors.left: root.left
        anchors.top: root.top
        anchors.leftMargin: 50
        color: "Transparent"
        clip: true

        MovingText{
            id: songTitle
            width: parent.width
            height: 60
            anchors.top: parent.top
            anchors.topMargin: 100

            textShow: root.nameSong

            onNext: {
                albumTitle.trigger();
            }
        }

        MovingText{
            id: albumTitle
            width: parent.width
            height: 40
            textSize: 30
            anchors.top: songTitle.bottom
            // anchors.topMargin: 20

            textShow: root.albumSong

            onNext: {
                songTitle.trigger();
            }
        }

        Component.onCompleted: {
            songTitle.trigger();
        }

    }


    // for saving current info of the song to qsettings every 1s
    Timer{
        interval: 1000
        repeat: true
        running: true
        onTriggered: {
            // console.log("Source ",);
            controller.saveCurrentSong(songList.source, timerSlider.value);
        }
    }

    // path album art
    PathElement {
        id: songList
        width: parent.width - songInfo.width
        height: root.height
        anchors.left: songInfo.right
        anchors.top: root.top
        anchors.topMargin: 50

        onFlickPath: {
            root.currentIndex = indexPath;
            // updateSource();
            controller.playRandom(indexPath);
        }

        Component.onCompleted: {
            console.log("path complete")
            root.currentIndex = indexPath;
            root.nameSong = songList.title
            root.albumSong = songList.album;

        }

        onIndexPathChanged: {
            root.currentIndex = songList.indexPath
        }
    }

    Connections{
        target: controller
        function onChangeSong() {
            songList.indexPath = controller.currentIndex;
            root.updateSource();
        }
    }


    Rectangle{
        id: playButtonContainer
        width: parent.width * 7 / 10
        height: parent.height / 5
        color: "transparent"

        anchors.top: songInfo.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        // anchors.topMargin: 100

        Row{
            spacing: 50
            // width
            height: parent.height - 40
            anchors.centerIn: parent


            MyButton{
                id: randomButtom
                radius: 15
                colorBackground: "transparent"
                scale: 0.7
                source: "qrc:/Image/PlayingButton/shuffle (1).png"
                colorHover: "#FEF9D9"

                onClickButton: {
                    root.isRandom = !root.isRandom
                    if(root.isRandom){
                        controller.setRandom();
                    }

                }
            }

            MyButton{
                radius: 15
                source: "qrc:Image/PlayingButton/prev_button.png"

                onClickButton: {
                    if(root.isLoops){
                        controller.playRandom(root.currentIndex);
                    }
                    else if (root.isRandom){
                        controller.playRandom(-1);
                    }
                    else{
                        controller.prev();
                    }
                }
            }

            MyButton{
                radius: 15
                source: isplayButton
                onClickButton: {
                    if(!isPlaying){
                        player.play();
                    }
                    else{
                        player.pause();
                    }
                    isPlaying = !isPlaying;

                }

            }

            MyButton{
                radius: 15
                source: "qrc:Image/PlayingButton/next_button.png"
                onClickButton: {
                    if(root.isLoops){
                        controller.playRandom(root.currentIndex);
                    }
                    else if (root.isRandom){
                        controller.playRandom(-1);
                    }
                    else {
                        controller.next();
                    }
                }
            }

            MyButton{
                id: loopButtom
                radius: 15
                color: "transparent"
                scale: 0.7
                source: "qrc:/Image/PlayingButton/refresh (1).png"
                colorBackground: "transparent"
                colorHover: "#FEF9D9"

                onClickButton: {
                    root.isLoops = !root.isLoops
                    if(root.isLoops){
                        controller.setLoop();
                    }
                }
            }
        }
    }

    Rectangle{
        id: backgroundBlur
        width: timeSongContainer.width + 80
        radius: 20
        height: timeSongContainer.height
        color: "black"
        opacity: 0.3

        anchors.centerIn: timeSongContainer
    }

    FastBlur{
        source: backgroundBlur
        radius: 20
        anchors.fill: backgroundBlur
        opacity: 0.3
    }

    Rectangle{
        id: timeSongContainer
        width: parent.width - 100
        height: root.height/ 5
        color: "transparent"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10

        Slider{
            id: timerSlider
            width: parent.width - 150
            height: 40
            Layout.minimumWidth: 200
            anchors.horizontalCenter: timeSongContainer.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            from: 0
            to: player.duration
            value: player.position
            // enabled: true
            background: Rectangle {
                id: bgSlider
                width: timerSlider.availableWidth
                x: timerSlider.leftPadding
                height: 4
                radius: 2
                color: "#CEDF9F"
                anchors.verticalCenter: parent.verticalCenter

                Rectangle {
                    id: visualSlider
                    width: timerSlider.visualPosition * parent.width
                    height: 4
                    radius: 2
                    color: "#4af0df"
                }
            }

            handle: Rectangle {
                id: point
                //            y: parent.padding
                // x: parent.leftPadding + parent.visualPosition * (parent.availableWidth ) - point.width / 2
                x: parent.leftPadding + parent.visualPosition * (parent.availableWidth) - width / 2
                y: parent.topPadding + parent.availableHeight / 2 - height / 2
                width: 20
                height: 20
                radius: 10
                anchors.verticalCenter: parent.verticalCenter
                color: "#7695FF"

            }

            onMoved: {
                player.position = timerSlider.value
            }

        }

        Text {
            id: durationTime
            text: controller.getTime(timerSlider.value)
            anchors.verticalCenter: timerSlider.verticalCenter
            anchors.right: timerSlider.left
            anchors.rightMargin: 20
            font.pointSize: 16

            color: "white"
        }

        Text {
            id: totalTime
            text: controller.getTime(timerSlider.to)
            anchors.verticalCenter: timerSlider.verticalCenter
            anchors.left: timerSlider.right
            anchors.leftMargin: 20
            font.pointSize: 16

            color: "white"
        }

    }

}

