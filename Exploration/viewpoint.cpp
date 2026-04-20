#include "viewpoint.h"
#include "keyitem.h"
#include "item.h"
#include "movearrow.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QTimer>

Viewpoint::Viewpoint() {



}

void Viewpoint::loadScene(SceneID id){
    clear();

    setSceneRect(0, 0, 4080, 3072);
    setBackgroundBrush(QBrush(QImage(":/images/View01.png").scaled(4080, 3072)));

    //All key items preloaded
    item * kitkat1 = new item();
    item * chips2 = new item();
    item * slushies3 = new item();
    item * whiteclaw4 = new item();
    item * icechest5 = new item();
    item * hotdoggrill6 = new item();


    switch(id) {
    case Scene01:{}

//Main view of interior gas station
    case Scene02: {
        setBackgroundBrush(QBrush(QImage(":/images/View02.png").scaled(4080, 3072)));
        MoveArrow *leftAisle = new MoveArrow(Scene02);
        leftAisle->setPixmap(QPixmap(":/images/ArrowImg01.png").scaled(2068,2057));
        leftAisle->setPos(100, 300);

        MoveArrow *rightAisle = new MoveArrow(Scene02);
        rightAisle->setPixmap(QPixmap(":/images/ArrowImg02.png").scaled(1200,1665));
        rightAisle->setPos(1000, 300);

        addItem(leftAisle);
        addItem(rightAisle);
        break;
    }

//Close up of candy aisle
    case Scene03: {
        setBackgroundBrush(QBrush(QImage(":/images/View03.png").scaled(4080, 3072)));
        if (!kitkat1->isCollected){
            kitkat1->setPixmap(QPixmap(":/images/Item01.png").scaled(390,308));
            kitkat1->setPos(100, 300);
            addItem(kitkat1);
        }
    }

//Close up of chip aisle
    case Scene04:
    {
        setBackgroundBrush(QBrush(QImage(":/images/View04.png").scaled(4080, 3072)));
        if (!chips2->isCollected){
            chips2->setPixmap(QPixmap(":/images/Item01.png").scaled(583,749));
            chips2->setPos(100, 300);
            addItem(chips2);
        }
    }

//Hallway w/ bathroom and slushie machine
    case Scene05:{
        setBackgroundBrush(QBrush(QImage(":/images/View05.png").scaled(4080, 3072)));

        MoveArrow *slushieMachine = new MoveArrow(Scene05);
        slushieMachine->setPixmap(QPixmap(":/images/ArrowImg03.png").scaled(1454,3072));
        slushieMachine->setPos(2626, 0);

        addItem(slushieMachine);

        MoveArrow *bathroomDoor = new MoveArrow(Scene05);
        bathroomDoor->setPixmap(QPixmap(":/images/Item07.png").scaled(613,1619));
        bathroomDoor->setPos(1626, 0);

        addItem(bathroomDoor);
    }

//Hallway w/ bathroom and slushie machine AND open door
    case Scene06:{
        setBackgroundBrush(QBrush(QImage(":/images/View06.png").scaled(4080, 3072)));
        setBackgroundBrush(QBrush(QImage(":/images/View05.png").scaled(4080, 3072)));

        MoveArrow *slushieMachine = new MoveArrow(Scene06);
        slushieMachine->setPixmap(QPixmap(":/images/ArrowImg03.png").scaled(1454,3072));
        slushieMachine->setPos(2626, 0);

        addItem(slushieMachine);

        MoveArrow *bathroomDoor = new MoveArrow(Scene06);
        bathroomDoor->setPixmap(QPixmap(":/images/Item08.png").scaled(601,1612));
        bathroomDoor->setPos(1626, 0);

        addItem(bathroomDoor);
    }

//Close up of slushie machine
    case Scene07:{
        setBackgroundBrush(QBrush(QImage(":/images/View07.png").scaled(4080, 3072)));

        if (!slushies3->isCollected){
            slushies3->setPixmap(QPixmap(":/images/Item03.png").scaled(583,749));
            slushies3->setPos(100, 300);
            addItem(slushies3);
    }

//Bathroom door closed
    case Scene08:{
        setBackgroundBrush(QBrush(QImage(":/images/View08.png").scaled(4080, 3072)));

        MoveArrow *bathroomDoor = new MoveArrow(Scene08);
        bathroomDoor->setPixmap(QPixmap(":/images/Item10.png").scaled(1933,3072));
        bathroomDoor->setPos(1626, 0);

        addItem(bathroomDoor);

    }

//Bathroom door open
    case Scene09:{
        setBackgroundBrush(QBrush(QImage(":/images/View09.png").scaled(4080, 3072)));

        MoveArrow *toilet = new MoveArrow(Scene09);
        toilet->setPixmap(QPixmap(":/images/Item09.png").scaled(1947,3072));
        toilet->setPos(1626, 0);

        addItem(toilet);
    }

//Drink fridges
    case Scene10:{
        setBackgroundBrush(QBrush(QImage(":/images/View10.png").scaled(4080, 3072)));

        if (!whiteclaw4->isCollected){
            whiteclaw4->setPixmap(QPixmap(":/images/Item04.png").scaled(391,318));
            whiteclaw4->setPos(100, 300);
            addItem(whiteclaw4);
        }
    }

//Freezer chest
    case Scene11:{
        setBackgroundBrush(QBrush(QImage(":/images/View11.png").scaled(4080, 3072)));

        if (!icechest5->isCollected){
            icechest5->setPixmap(QPixmap(":/images/Item04.png").scaled(3514,2163));
            icechest5->setPos(100, 300);
            addItem(icechest5);
        }
    }

//Hot dog machine
    case Scene12:{
        setBackgroundBrush(QBrush(QImage(":/images/View12.png").scaled(4080, 3072)));

        if (!hotdoggrill6->isCollected){
            hotdoggrill6->setPixmap(QPixmap(":/images/Item04.png").scaled(1166,1200));
            hotdoggrill6->setPos(100, 300);
            addItem(hotdoggrill6);
        }

    }

//Outside - dumpster
    case Scene13:{
        setBackgroundBrush(QBrush(QImage(":/images/View13.png").scaled(4080, 3072)));
    }

//Outside fence
    case Scene14:{
        setBackgroundBrush(QBrush(QImage(":/images/View14.png").scaled(4080, 3072)));
    }




    }
    }

}

