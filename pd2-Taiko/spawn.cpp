#include "spawn.h"
#include "up.h"
#include "upup.h"
#include "down.h"
#include "downdown.h"
#include "left.h"
#include "leftleft.h"
#include "right.h"
#include "rightright.h"
#include <stdlib.h>
#include "game.h"
#include <QGraphicsTextItem>
#include <time.h>

extern Game * game;

Spawn::Spawn():numOfType(4){
    srand(time(NULL));
}

void Spawn::spawn(){
    if(game->countDown->time < 20)
        numOfType = 8;

    switch(rand()%numOfType){
    case 7:{
        UpUp * upUp = new UpUp();
        scene()->addItem(upUp);
        break;
    }
    case 6:{
        DownDown * downDown = new DownDown();
        scene()->addItem(downDown);
        break;
    }
    case 5:{
        LeftLeft * leftLeft = new LeftLeft();
        scene()->addItem(leftLeft);
        break;
    }
    case 4:{
        RightRight * rightRight = new RightRight();
        scene()->addItem(rightRight);
        break;
    }
    case 3:{
        Up * up = new Up();
        scene()->addItem(up);
        break;
    }
    case 2:{
        Down * down = new Down();
        scene()->addItem(down);
        break;
    }
    case 1:{
        Left * left = new Left();
        scene()->addItem(left);
        break;
    }
    case 0:{
        Right * right = new Right();
        scene()->addItem(right);
        break;
    }
    }
}
