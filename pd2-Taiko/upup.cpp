#include "upup.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> really large int
#include "game.h"
#include <QKeyEvent>
#include "spawn.h"

extern Game * game;

UpUp::UpUp(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent){
    second = 0;
    setPos(305,0);

    setPixmap(QPixmap(":/images/upup.png"));

    this->setFlag(QGraphicsItem::ItemIsFocusable);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(game->timeBetweenMove);
}

void UpUp::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Up)
        second++;

    if(second == 2){
        game->score->increase();
        game->combo->increase();
        game->maxCombo->updateMaxCombo();

        scene()->removeItem(this);
        delete this;
    }
}

void UpUp::move(){
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
