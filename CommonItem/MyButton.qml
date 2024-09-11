import QtQuick 2.15

Rectangle{
    id: root
    width: 100
    height: 80
    color: interact ? colorBackground : "gray"
    border.width: 2
    radius: 15

    property string colorBackground: "white"
    property string colorHover: "#FFDBB5"

    property string source
    // property bool display: true
    property bool interact: true

    signal clickButton()

    Image{
        anchors.fill: parent
        source: root.source
        fillMode: Image.PreserveAspectFit
    }

    MouseArea{
        anchors.fill: parent
        enabled: interact
        onClicked: {
            clickButton();
        }

        hoverEnabled: root.interact
        onEntered: {
            root.color = root.interact ? colorHover : "gray"
        }
        onExited: {
            root.color = root.interact ? colorBackground : "gray"
        }
    }
}
