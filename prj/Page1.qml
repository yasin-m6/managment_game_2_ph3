import QtQuick 2.9
import QtQuick.Controls 2.5
Item
{

    Rectangle
    {
        id : backGround
        width: root.width
        height : root.height
        color: "lightskyblue"

        Image {
            id: goToShop
            source: "qrc:/images/shop_icon.png"
            sourceSize: Qt.size(parent.width/10 , parent.width/10)
            anchors.top : backGround.top
            anchors.left: backGround.left
            MouseArea
            {
                anchors.fill: parent
                onClicked: {
                    console.log("shop")
                    stackView.push("Test1.qml")
                }
            }

        }

        Button
        {
            width: backGround.height / 2
            height: width
            anchors.centerIn: parent
            id : test
            onClicked:
            {
                if(useManager.get_farm_type() ===  0)
                {
                    if(1)
                    {
                        useManager.plowFarm()
                        khak.source = "qrc:/images/plow_farm.jpg"
                        nowTime.text = "     farm is plowed \nits ready for plant seeds"
                    }
                }
                else if(useManager.get_farm_type() === 6)
                {
                    if(1)
                    {
                        useManager.plantSeed(1);
                        farm.visible = true;
                        farm.source = "qrc:/images/tomato_farm.png"
                        nowTime.text = "plow farm befor plant seeds"
                        spoiledWaterTime.interval = useManager.spoiled_water_timer() * 1000
                        waterTime.interval = useManager.water_timer()  * 1000
                        spoiledCropTime.interval = useManager.spoiled_crop_timer() * 1000
                        cropTime.interval = useManager.crop_timer() * 1000
                        waterTime.start()
                        cropTime.start()
                        forTest.start();


                    }
                }
                else
                {
                    if(1)
                    {
                        if(useManager.checkCropTime() === true)
                        {
                            forTest.stop()
                            waterTime.stop()
                            cropTime.stop()
                            spoiledCropTime.stop()
                            spoiledWaterTime.stop()
                            useManager.cropProduct();
                            nowTime.text = "plow farm befor plant seeds"
                            khak.source = "qrc:/images/Khak_farm.jpg"
                            farm.visible = false
                            cropWater.visible = false;
                        }
                        else if(useManager.checkWaterTime() === true)
                        {
                            useManager.waterVeg();
                            cropWater.visible = false
                            waterTime.interval = useManager.water_timer()  * 1000
                            waterTime.restart();
                            spoiledWaterTime.stop()

                        }

                    }
                }

            }

            Image {
                id: khak
                source: "qrc:/images/Khak_farm.jpg"
                anchors.fill: parent
            }
            Image {
                id: farm
                visible: false
                source: "qrc:/images/tomato_farm.png"
                anchors.fill: parent

            }
            Image
            {
                id : cropWater
                source: "qrc:/images/water.png"
                visible: false
                sourceSize: Qt.size(parent.width/4 , width*2/3);
                anchors.top : parent.top
                anchors.right: parent.right
            }

            ToolTip
            {
                id : nowTime
                text : "plow farm befor plant seeds"
                visible: test.hovered
            }


        }

        Timer{
            id : forTest
            interval: 100
            repeat: true
            onTriggered:
            {
                if(useManager.checkCropTime() === true)
                {
                    nowTime.text = "crop it sooner!!! : " + useManager.get_crop_spoiled() + "s";
                }
                else if(useManager.checkWaterTime() === true)
                {
                    nowTime.text = "crop time : " + useManager.getCropTime() + "s \nwater vegtebale sooner!!! : " + useManager.get_water_spoiled() + "s";
                }
                else
                {
                    nowTime.text = "crop time : " + useManager.getCropTime() + "s \nwater time : " + useManager.getWaterTime() + "s";
                }
            }

        }

        Timer
        {
            id : waterTime
            interval: (useManager.water_timer()) * 1000
            onTriggered:
            {
                cropWater.source = "qrc:/images/water.png"
                cropWater.visible = true
                spoiledWaterTime.start()
                console.log("w")
            }
        }

        Timer
        {
            id : cropTime
            interval: (useManager.crop_timer()) * 1000
            onTriggered:
            {
                cropWater.source = "qrc:/images/bil_icon.ico"
                cropWater.visible = true
                spoiledCropTime.start()
                console.log("c")
                waterTime.stop()
                spoiledWaterTime.stop()
            }
        }

        Timer
        {
            id : spoiledWaterTime
            interval: (useManager.spoiled_water_timer()) * 1000
            onTriggered:
            {
                forTest.stop()
                waterTime.stop()
                cropTime.stop()
                spoiledCropTime.stop()
                useManager.spoiled_product()
                nowTime.text = "plow farm befor plant seeds"
                khak.source = "qrc:/images/Khak_farm.jpg"
                farm.visible = false
                cropWater.visible = false;
                console.log("sw")
            }
        }

        Timer
        {
            id : spoiledCropTime
            interval: (useManager.spoiled_water_timer()) * 1000
            onTriggered:
            {
                forTest.stop()
                waterTime.stop()
                cropTime.stop()
                spoiledWaterTime.stop()
                useManager.spoiled_product()
                nowTime.text = "plow farm befor plant seeds"
                khak.source = "qrc:/images/Khak_farm.jpg"
                farm.visible = false
                cropWater.visible = false;
                console.log("sc")
            }
        }


    }



}
