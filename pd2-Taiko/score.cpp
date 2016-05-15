#include "score.h"
#include <QFont>
#include "game.h"

extern Game * game;

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    score = 0;

    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::gray);
    setFont(QFont("times",16));
}

void Score::increase(){
    score += 600000 / game->timeBetweenSpawn / game->timeBetweenMove + game->combo->combo * game->combo->combo ;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore(){
    return score;
}
