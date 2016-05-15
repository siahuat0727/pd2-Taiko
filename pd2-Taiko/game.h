#ifndef GAME
#define GAME

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "score.h"
#include "combo.h"
#include "maxcombo.h"
#include "countdown.h"
#include "spawn.h"
#include <QTimer>
#include <QMediaPlayer>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>

class Game: public QGraphicsView{
        Q_OBJECT
public:
    Game();
    void displayMenu();
    void changeSpeed(const int&);
    void gameOver();

    QGraphicsScene * scene;
    Score * score;
    Combo * combo;
    MaxCombo * maxCombo;
    CountDown * countDown;
    Spawn * spawn;
    QGraphicsTextItem * hint;
    QGraphicsTextItem * hint2;
    QGraphicsTextItem * hint3;
    int focusPoint;
    int deletePoint;
    float timeBetweenMove;
    float moveSpeed;
    float timeBetweenSpawn;
private:
    int widgetWidth;
    int widgetHeight;
    QTimer * countDownTimer;
    QMediaPlayer * startPlayer;
    QGraphicsPixmapItem * drum;

public slots:
    void start();
};

#endif // GAME

