#include "rightright.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> really large int
#include "game.h"
#include <QKeyEvent>
#include "spawn.h"

extern Game * game;

RightRight::RightRight(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent){
    second = 0;
    setPos(305,0);

    setPixmap(QPixmap(":/images/rightright.png"));

    this->setFlag(QGraphicsItem::ItemIsFocusable);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(game->timeBetweenMove);
}

void RightRight::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Right)
        second++;

    if(second == 2){
        game->score->increase();
        game->combo->increase();
        game->maxCombo->updateMaxCombo();

        scene()->removeItem(this);
        delete this;

    }
}

void RightRight::move(){
    setPos(x(),y()+game->moveSpeed);

    if (pos().y() == game->focusPoint -50){
        this->setFocus();
    }

    if (pos().y() > game->deletePoint){
        game->combo->setZero();
        scene()->removeItem(this);
        delete this;
    }
}
