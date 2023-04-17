import QtQuick 2.15
import QtQuick.Window 2.1
import QtQuick.Controls 2

//Window {
Item {
    id:main
    width: 400; height: 400

    Image {id: image00;objectName: "image00"}
    Image {id: image10;objectName: "image10"}
    Image {id: image20;objectName: "image20"}
    Image {id: image30;objectName: "image30"}
    Image {id: image01;objectName: "image01"}
    Image {id: image11;objectName: "image11"}
    Image {id: image21;objectName: "image21"}
    Image {id: image31;objectName: "image31"}
    Image {id: image02;objectName: "image02"}
    Image {id: image12;objectName: "image12"}
    Image {id: image22;objectName: "image22"}
    Image {id: image32;objectName: "image32"}
    Image {id: image03;objectName: "image03"}
    Image {id: image13;objectName: "image13"}
    Image {id: image23;objectName: "image23"}
    Image {id: image33;objectName: "image33"}

    TextInput {
	id: text00;
	objectName: "text00";
	validator: RegularExpressionValidator{regularExpression: /^[a-zA-Z]$/ }
	signal qmlSignal(msg: string)
	onTextChanged: text00.qmlSignal(0)
	/* MouseArea {
            anchors.fill: parent
            onClicked: text00.qmlSignal(text00)
	} */
    }
    TextInput {
	id: text01;
	objectName: "text01";
	validator: RegularExpressionValidator{regularExpression: /^[a-zA-Z]$/ }
	signal qmlSignal(msg: string)
	onTextChanged: text01.qmlSignal(1)
    }
    TextInput {
	id: text02;
	objectName: "text02";
	validator: RegularExpressionValidator{regularExpression: /^[a-zA-Z]$/ }
	signal qmlSignal(msg: string)
	onTextChanged: text02.qmlSignal(2)
    }
    TextInput {
	id: text03;
	objectName: "text03";
	validator: RegularExpressionValidator{regularExpression: /^[a-zA-Z]$/ }
	signal qmlSignal(msg: string)
	onTextChanged: text03.qmlSignal(3)
    }
    TextInput {
	id: text10;
	objectName: "text10";
	validator: RegularExpressionValidator{regularExpression: /^[a-zA-Z]$/ }
	signal qmlSignal(msg: string)
	onTextChanged: text10.qmlSignal(4)
    }
    TextInput {
	id: text11;
	objectName: "text11";
	validator: RegularExpressionValidator{regularExpression: /^[a-zA-Z]$/ }
	signal qmlSignal(msg: string)
	onTextChanged: text11.qmlSignal(5)
    }
    TextInput {
	id: text12;
	objectName: "text12";
	validator: RegularExpressionValidator{regularExpression: /^[a-zA-Z]$/ }
	signal qmlSignal(msg: string)
	onTextChanged: text12.qmlSignal(6)
    }
    TextInput {
	id: text13;
	objectName: "text13";
	validator: RegularExpressionValidator{regularExpression: /^[a-zA-Z]$/ }
	signal qmlSignal(msg: string)
	onTextChanged: text13.qmlSignal(7)
    }
    TextInput {
	id: text20;
	objectName: "text20";
	validator: RegularExpressionValidator{regularExpression: /^[a-zA-Z]$/ }
	signal qmlSignal(msg: string)
	onTextChanged: text20.qmlSignal(8)
    }
    TextInput {
	id: text21;
	objectName: "text21";
	validator: RegularExpressionValidator{regularExpression: /^[a-zA-Z]$/ }
	signal qmlSignal(msg: string)
	onTextChanged: text21.qmlSignal(9)
	/* MouseArea {
            anchors.fill: parent
            onClicked: text21.qmlSignal(text21)
	} */
    }
    TextInput {
	id: text22;
	objectName: "text22";
	validator: RegularExpressionValidator{regularExpression: /^[a-zA-Z]$/ }
	signal qmlSignal(msg: string)
	onTextChanged: text22.qmlSignal(10)
	/* MouseArea {
            anchors.fill: parent
            onClicked: text22.qmlSignal(text22)
	} */
    }
    TextInput {
	id: text23;
	objectName: "text23";
	validator: RegularExpressionValidator{regularExpression: /^[a-zA-Z]$/ }
	signal qmlSignal(msg: string)
	onTextChanged: text23.qmlSignal(11)
	/* MouseArea {
            anchors.fill: parent
            onClicked: text23.qmlSignal(text23)
	} */
    }
    TextInput {
	id: text30;
	objectName: "text30";
	validator: RegularExpressionValidator{regularExpression: /^[a-zA-Z]$/ }
	signal qmlSignal(msg: string)
	onTextChanged: text30.qmlSignal(12)
	/* MouseArea {
            anchors.fill: parent
            onClicked: text30.qmlSignal(text30)
	} */
    }
    TextInput {
	id: text31;
	objectName: "text31";
	validator: RegularExpressionValidator{regularExpression: /^[a-zA-Z]$/ }
	signal qmlSignal(msg: string)
	onTextChanged: text31.qmlSignal(13)
	/* MouseArea {
            anchors.fill: parent
            onClicked: text31.qmlSignal(text31)
	} */
    }
    TextInput {
	id: text32;
	objectName: "text32";
	validator: RegularExpressionValidator{regularExpression: /^[a-zA-Z]$/ }
	signal qmlSignal(msg: string)
	onTextChanged: text32.qmlSignal(14)
	/* MouseArea {
            anchors.fill: parent
            onClicked: text32.qmlSignal(text32)
	} */
    }
    TextInput {
	id: text33;
	objectName: "text33";
	validator: RegularExpressionValidator{regularExpression: /^[a-zA-Z]$/ }
	signal qmlSignal(msg: string)
	onTextChanged: text33.qmlSignal(15)
	/* MouseArea {
            anchors.fill: parent
            onClicked: text33.qmlSignal(text33)
	} */
    }

    /*
    TextInput {
        id: text00
        objectName: "text00"
        x:0;y:0
        width: 50;height: 50
        text: "?"
        validator: RegularExpressionValidator{regularExpression: /^[a-zA-Z]$/ }
    }
    */
    ProgressBar {
        id: progressBar
        objectName: "progressBar"
        x:image00.x; y:image33.y+51;
        width: 4*51; height:20
        value: 0.5
    }

    Button {
        id: solve
        objectName: "solve"
        x: image30.x + 51;y:image30.y
        text: "solve"
	signal qmlSignal(msg: string)
	onClicked: solve.qmlSignal(solve)
    }

    Button {
	id: play
        objectName: "play"
        x: solve.x ;y:solve.y+51
        text: "play"
	signal qmlSignal(msg: string)
	onClicked: play.qmlSignal(play)
    }

    RadioButton {
        id: rotation
        objectName: "rotation"
        x: play.x;y: play.y+51
        text: "rotation"
    }

    TextInput {
        id: duree
        objectName: "duree"
        x: solve.x ;y:rotation.y+51
        text: "180 sec"
    }

}

