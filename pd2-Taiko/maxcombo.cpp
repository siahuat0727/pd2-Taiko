#include "maxcombo.h"
#include "game.h"
extern Game * game;

MaxCombo::MaxCombo(QGraphicsItem *parent){
    maxCombo = 0;

    setPlainText(QString("Max Combo: ") + QString::number(maxCombo));
    setDefaultTextColor(Qt::gray);
    setFont(QFont("times",16));
}

void MaxCombo::updateMaxCombo(){
    if(game->combo->combo > maxCombo)
        maxCombo = game->combo->combo;
    setPlainText(QString("Max Combo: ") + QString::number(maxCombo));
}

int MaxCombo::getMaxCombo(){
    return maxCombo;
}

