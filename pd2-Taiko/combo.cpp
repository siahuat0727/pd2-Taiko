#include "combo.h"
#include <QFont>

Combo::Combo(QGraphicsItem *parent): QGraphicsTextItem(parent){

    combo = 0;

    setPlainText(QString("Combo: ") + QString::number(combo));
    setDefaultTextColor(Qt::gray);
    setFont(QFont("times",16));

    player = new QMediaPlayer();
    clearPlayer = new QMediaPlayer();
    missPlayer = new QMediaPlayer();
}

void Combo::increase(){
    clearPlayer->setMedia(QUrl("qrc:sounds/clear.mp3"));
    clearPlayer->play();

    combo++;
    setPlainText(QString("Combo: ") + QString::number(combo));

    switch(combo){
    case  1: player->setMedia(QUrl("qrc:sounds/C-2.mp3"));
             break;
    case  2: player->setMedia(QUrl("qrc:sounds/D-2.mp3"));
             break;
    case  3: player->setMedia(QUrl("qrc:sounds/E-2.mp3"));
             break;
    case  4: player->setMedia(QUrl("qrc:sounds/F-2.mp3"));
             break;
    case  5: player->setMedia(QUrl("qrc:sounds/G-2.mp3"));
             break;
    case  6: player->setMedia(QUrl("qrc:sounds/A-2.mp3"));
             break;
    case  7: player->setMedia(QUrl("qrc:sounds/B-2.mp3"));
             break;
    case  8: player->setMedia(QUrl("qrc:sounds/C-3.mp3"));
             break;
    case  9: player->setMedia(QUrl("qrc:sounds/D-3.mp3"));
             break;
    case 10: player->setMedia(QUrl("qrc:sounds/E-3.mp3"));
             break;
    case 11: player->setMedia(QUrl("qrc:sounds/F-3.mp3"));
             break;
    case 12: player->setMedia(QUrl("qrc:sounds/G-3.mp3"));
             break;
    case 13: player->setMedia(QUrl("qrc:sounds/A-3.mp3"));
             break;
    case 14: player->setMedia(QUrl("qrc:sounds/B-3.mp3"));
             break;
    case 15: player->setMedia(QUrl("qrc:sounds/C-4.mp3"));
             break;
    case 16: player->setMedia(QUrl("qrc:sounds/D-4.mp3"));
             break;
    case 17: player->setMedia(QUrl("qrc:sounds/E-4.mp3"));
             break;
    case 18: player->setMedia(QUrl("qrc:sounds/F-4.mp3"));
             break;
    case 19: player->setMedia(QUrl("qrc:sounds/G-4.mp3"));
             break;
    case 20: player->setMedia(QUrl("qrc:sounds/A-4.mp3"));
             break;
    case 21: player->setMedia(QUrl("qrc:sounds/B-4.mp3"));
             break;
    case 22: player->setMedia(QUrl("qrc:sounds/C-5.mp3"));
             break;
    case 23: player->setMedia(QUrl("qrc:sounds/D-5.mp3"));
             break;
    case 24: player->setMedia(QUrl("qrc:sounds/E-5.mp3"));
             break;
    case 25: player->setMedia(QUrl("qrc:sounds/F-5.mp3"));
             break;
    case 26: player->setMedia(QUrl("qrc:sounds/G-5.mp3"));
             break;
    case 27: player->setMedia(QUrl("qrc:sounds/A-5.mp3"));
             break;
    case 28: player->setMedia(QUrl("qrc:sounds/B-5.mp3"));
             break;
    case 29: player->setMedia(QUrl("qrc:sounds/C-6.mp3"));
             break;
    case 30: player->setMedia(QUrl("qrc:sounds/D-6.mp3"));
             break;
    case 31: player->setMedia(QUrl("qrc:sounds/E-6.mp3"));
             break;
    case 32: player->setMedia(QUrl("qrc:sounds/F-6.mp3"));
             break;
    case 33: player->setMedia(QUrl("qrc:sounds/G-6.mp3"));
             break;
    case 34: player->setMedia(QUrl("qrc:sounds/A-6.mp3"));
             break;
    case 35: player->setMedia(QUrl("qrc:sounds/B-6.mp3"));
             break;
    case 36: player->setMedia(QUrl("qrc:sounds/C-7.mp3"));
             break;
    case 37: player->setMedia(QUrl("qrc:sounds/D-7.mp3"));
             break;
    case 38: player->setMedia(QUrl("qrc:sounds/E-7.mp3"));
             break;
    case 39: player->setMedia(QUrl("qrc:sounds/F-7.mp3"));
             break;
    }
    if(combo > 39)
        player->setMedia(QUrl("qrc:sounds/Fsharp-7.mp3"));

    player->play();
}

void Combo::setZero(){
    combo = 0;
    setPlainText(QString("Combo: ") + QString::number(combo));

    missPlayer->setMedia(QUrl("qrc:sounds/miss.mp3"));
    missPlayer->play();
}
