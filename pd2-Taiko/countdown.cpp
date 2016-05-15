#include "countdown.h"
#include <QTimer>
#include <QFont>
#include "game.h"

extern Game * game;

CountDown::CountDown(QGraphicsItem *parent): time(30){
    setPlainText(QString("Time left: ") + QString::number(time));
    setDefaultTextColor(Qt::gray);
    setFont(QFont("times",16));
}

void CountDown::countDown(){
    if(time < 0)
        return;
    if((time-1) % 10 == 0)
        game->changeSpeed(time-1);
    if(time % 10 == 0 && time > 0){

        timer = new QTimer();
        QObject::connect(timer,SIGNAL(timeout()),game->spawn,SLOT(spawn()));
        timer->start(game->timeBetweenSpawn);

        deleteTimer = new QTimer();
        QObject::connect(deleteTimer,SIGNAL(timeout()),this,SLOT(deleteTimerFunc()));
        deleteTimer->start(8500);
    }
    if(time == 0){
        game->gameOver();
        return;
    }
    time--;
    if(time >= 0)
        setPlainText(QString("Time left: ") + QString::number(time));
}

void CountDown::deleteTimerFunc(){
    delete timer;
    delete deleteTimer;
}
