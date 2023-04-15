import QtQuick 2.15
import QtQuick.Window 2.1
import QtQuick.Controls 2

//Window {
Item {
    id:main
    width: 400; height: 400
    Image {
        id: image00
        objectName: "image00"
        x:0;y:0
        source: "resources/_0.png"
    }
    Image {
        id: image10
        objectName: "image10"
        x:51;y:0
        source: "resources/_0.png"
    }
    Image {
        id: image20
        objectName: "image20"
        x:51*2;y:0
        source: "resources/_0.png"
    }
    Image {
        id: image30
        objectName: "image30"
        x:51*3;y:0
        source: "resources/_0.png"
    }

    Image {
        id: image01
        objectName: "image01"
        x:0;y:51
        source: "resources/_0.png"
    }
    Image {
        id: image11
        objectName: "image11"
        x:51;y:51
        source: "resources/_0.png"
    }
    Image {
        id: image21
        objectName: "image21"
        x:51*2;y:51
        source: "resources/_0.png"
    }
    Image {
        id: image31
        objectName: "image31"
        x:51*3;y:51
        source: "resources/_0.png"
    }

    Image {
        id: image02
        objectName: "image02"
        x:0;y:51*2
        source: "resources/_0.png"
    }
    Image {
        id: image12
        objectName: "image12"
        x:51;y:51*2
        source: "resources/_0.png"
    }
    Image {
        id: image22
        objectName: "image22"
        x:51*2;y:51*2
        source: "resources/_0.png"
    }
    Image {
        id: image32
        objectName: "image32"
        x:51*3;y:51*2
        source: "resources/_0.png"
    }

    Image {
        id: image03
        objectName: "image03"
        x:0;y:51*3
        source: "resources/_0.png"
    }
    Image {
        id: image13
        objectName: "image13"
        x:51;y:51*3
        source: "resources/_0.png"
    }
    Image {
        id: image23
        objectName: "image23"
        x:51*2;y:51*3
        source: "resources/_0.png"
    }
    Image {
        id: image33
        objectName: "image33"
	x:51*3;y:51*3
        source: "resources/_0.png"
    }
    ProgressBar {
	id: progressBar
	objectName: "progressBar"
	x:image00.x; y:image33.y+51;
	width: 4*51; height:20 
	value: 0.5
    }
}

