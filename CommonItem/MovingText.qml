import QtQuick 2.15

Rectangle {
    id: root
    color: "transparent"
    clip: true
    property bool isRunning: false

    property string textShow: ""
    property string textColor: "white"
    property int textSize: 35

    property bool checking: false   // for allow horver or not


    signal complete();
    signal next();
    signal trigger();

    onTrigger: {
        timer.start();
    }
    onComplete: {
        aniText.stop();
    }

    Text {
        id: movingText
        text: textShow
        color: textColor
        font.pixelSize: textSize
        anchors.verticalCenter: parent.verticalCenter
        width: parent.width

    }

    // Kiểm tra paintedWidth lớn hơn width của Rectangle
    NumberAnimation {
        id: aniText
        target: movingText
        property: "x"
        duration: movingText.width * 20
        running: root.isRunning
        from: 0
        to: -movingText.paintedWidth
        loops: 1
        onStopped: {
            next();
            movingText.x = 0
        }
    }
    // wait for 1 secs to binding the width of root
    Timer{
        id: timer
        interval: 0
        repeat: false
        running: false
        onTriggered: {
            if(movingText.paintedWidth > root.width){
                // root.isRunning = true;
                aniText.restart();
                // console.log("come here")
            }
            else {
                root.next();
                aniText.stop();
            }
        }
    }
}
