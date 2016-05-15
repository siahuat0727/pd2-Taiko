#include "spawner.h"
#include "drum.h"
#include <QGraphicsScene>
#include <QDebug>
#include "game.h"

extern Game * game;

void Spawner::spawn()
{
    Drum * drum = new Drum();
    scene()->addItem(drum);
    qDebug() << "spawn";
}
