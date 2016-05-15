#include "down.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> really large int
#include "game.h"
#include <QKeyEvent>
#include "spawn.h"

extern Game * game;

Down::Down(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent){

    setPos(305,0);

    setPixmap(QPixmap(":/images/down.png"));

    this->setFlag(QGraphicsItem::ItemIsFocusable);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(game->timeBetweenMove);
}

void Down::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Down){
        game->score->increase();
        game->combo->increase();
        game->maxCombo->updateMaxCombo();

        scene()->removeItem(this);
        delete this;
    }
}

void Down::move(){
    setPos(x(),y()+game->moveSpeed);

    if (pos().y() == game->focusPoint){
        this->setFocus();
    }

    if (pos().y() > 650){
        game->combo->setZero();
        scene()->removeItem(this);
        delete this;
    }
}
