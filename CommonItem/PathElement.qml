import QtQuick 2.15
import QtGraphicalEffects 1.15


Item {
    id: root

    property alias indexPath: songList.currentIndex
    property string title: songList.model[songList.currentIndex].title
    property string album: songList.model[songList.currentIndex].album
    property string source: songList.model[songList.currentIndex].source
    property string art: songList.model[songList.currentIndex].albumArt

    property int count: songList.count

    signal flickPath();

    signal increase();
    signal decrease();

    property int widthPath: root.width
    property int widthImage: 200

    onIncrease: {
        songList.incrementCurrentIndex();
    }
    onDecrease: {
        songList.decrementCurrentIndex();
    }

    clip: true
    // color: "red"
    PathView{
        id: songList
        width: root.width
        height: root.height
        model: controller.model.playlist
        pathItemCount: 3
        currentIndex: controller.currentIndex

        onCountChanged: {
            root.count = songList.count;
        }

        delegate: Rectangle{
            id: converId
            width: root.widthImage
            height: root.widthImage
            radius: 15
            border.color: "#7C93C3"
            border.width: 10
            scale: PathView.iconScale
            z: PathView.direction
            opacity: PathView.seeing

            property var myData: model
            color: "transparent"

            // visible: {
            //     var check = false;
            //     if(songList.currentIndex === 0){
            //         check = index === songList.count - 1;
            //     }
            //     if(songList.currentIndex == songList.count - 1){
            //         check = index === 0;
            //     }

            //     if(index === songList.currentIndex ||
            //             index === songList.currentIndex - 1 ||
            //             index === songList.currentIndex + 1)
            //         return true;
            //     return check;
            // }

            DropShadow {
                anchors.fill: backgroundId
                horizontalOffset: 20
                verticalOffset: 20
                radius: 8.0
                samples: 17
                color: "#000"
                opacity: 0.4
                z: -2
                source: backgroundId
            }

            Image {
                id: backgroundId
                width: parent.width
                height: parent.height
                fillMode: Image.PreserveAspectCrop
                anchors.fill: parent
                anchors.margins: 9
                source: "file:///" + myData.modelData.albumArt
                z: -1
            }

            Text{
                text: index
                anchors.top: converId.bottom
            }


            MouseArea{
                anchors.fill: parent
                onClicked: {
                    console.log(model.modelData.title);
                }
            }
        }


        onCurrentIndexChanged: {
            root.title = songList.model[songList.currentIndex].title;
            root.album= songList.model[songList.currentIndex].album;

        }

        onFlickEnded: {
            root.title = songList.model[songList.currentIndex].title;
            root.album= songList.model[songList.currentIndex].album;

            root.flickPath();
        }

        path: Path{

            startX: songList.width / 2 ; startY: root.widthImage
            PathAttribute { name: "iconScale"; value: 1 }
            PathAttribute{
                name: "direction"
                value: 1
            }
            PathAttribute{
                name: "seeing"
                value: 1.0
            }


            PathQuad
            { x: songList.width - 200; y: 0;
                controlX: songList.width - 100; controlY: root.widthImage}
            PathAttribute { name: "iconScale"; value: 0.7 }
            PathAttribute{
                name: "direction"
                value: 0
            }
            PathAttribute{
                name: "seeing"
                value: 0.5
            }
            PathPercent{value: 0.5}


            PathQuad
            {
                x: 200
                y: 0
                controlX: songList.width/2
                controlY: -root.widthImage
            }
            PathAttribute { name: "iconScale"; value: 0.7 }
            PathAttribute{
                name: "direction"
                value: 0
            }
            PathAttribute{
                name: "seeing"
                value: 0.5
            }
            PathPercent{value: 0.5}

            PathQuad
            {
                x: songList.width/2
                y: root.widthImage
                controlX: 100
                controlY: root.widthImage
            }
            PathAttribute { name: "iconScale"; value: 1.0 }
            PathAttribute{
                name: "direction"
                value: 1
            }
            PathAttribute{
                name: "seeing"
                value: 1.0
            }
        }

        Component.onCompleted: {
            root.title = songList.model[songList.currentIndex].title;
            root.album= songList.model[songList.currentIndex].album;
        }

    }

}


