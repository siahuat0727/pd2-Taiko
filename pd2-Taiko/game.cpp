#include "game.h"
#include <QFont>
#include <QBrush>
#include <QImage>
#include <QMediaPlayer>
#include "button.h"

Game::Game():widgetWidth(700),widgetHeight(650){

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,widgetWidth,widgetHeight);
    setBackgroundBrush(QBrush(QImage(":/images/backGround.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(widgetWidth,widgetHeight);
    startPlayer = new QMediaPlayer();
}

void Game::start(){
    moveSpeed = 5;
    timeBetweenSpawn = 500;
    timeBetweenMove = 12;
    focusPoint = 460;
    deletePoint = 600;

    scene->clear();
    startPlayer->setMedia(QUrl("qrc:sounds/start.mp3"));

    score = new Score();
    scene->addItem(score);

    maxCombo = new MaxCombo();
    maxCombo->setPos(maxCombo->x(),maxCombo->y()+50);
    scene->addItem(maxCombo);

    combo = new Combo();
    combo->setPos(combo->x(),combo->y()+100);
    scene->addItem(combo);

    countDown = new CountDown();
    countDown->setPos(countDown->x(),countDown->y()+150);
    scene->addItem(countDown);

    hint = new QGraphicsTextItem;
    hint->setPlainText(QString("How to clear?\nHints :\n-  KEEP ON\nlearning C++"));
    hint->setDefaultTextColor(Qt::gray);
    hint->setFont(QFont("times",16));
    hint->setPos(widgetWidth - 250,0);
    scene->addItem(hint);

    drum = new QGraphicsPixmapItem();
    drum->setPos(widgetWidth/2 - 100, widgetHeight - 115);
    drum->setPixmap(QPixmap(":/images/drum.png"));
    scene->addItem(drum);

    spawn = new Spawn();
    scene->addItem(spawn);

    countDownTimer = new QTimer(this);
    QObject::connect(countDownTimer, SIGNAL(timeout()), countDown, SLOT(countDown()));
    countDownTimer->start(1000);
}

void Game::displayMenu(){

    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("C++ TaiKo"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    titleText->setDefaultTextColor(Qt::white);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 300;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    QGraphicsPixmapItem* bg = new QGraphicsPixmapItem();
    bg->setPos(widgetWidth/2 - 300, 0);
    bg->setPixmap(QPixmap(":/images/bg.png"));
    scene->addItem(bg);

    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 400;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 500;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);


    startPlayer->setMedia(QUrl("qrc:sounds/start.mp3"));
    startPlayer->play();
}

void Game::changeSpeed(const int & time){
    switch (time) {
    case 20:{
        timeBetweenMove -=2;
        timeBetweenSpawn -= 100;

        hint2 = new QGraphicsTextItem;
        hint2->setPlainText(QString("-  WORK HARDER\nin order to learn more"));
        hint2->setDefaultTextColor(Qt::gray);
        hint2->setFont(QFont("times",16));
        hint2->setPos(widgetWidth - 250,100);
        scene->addItem(hint2);
        break;
    }
    case 10:{
        timeBetweenMove -=2;
        timeBetweenSpawn -= 100;

        hint3 = new QGraphicsTextItem;
        hint3->setPlainText(QString("-  However,\nit is hard to get\nPERFECT\nGOOD LUCK!"));
        hint3->setDefaultTextColor(Qt::gray);
        hint3->setFont(QFont("times",16));
        hint3->setPos(widgetWidth - 250,150);
        scene->addItem(hint3);
        break;
    }
    }
}

void Game::gameOver(){
    /*
    for(size_t i = 0, n = scene->items().size(); i < n; i++){
        scene->items()[i]->setEnabled(false);
    }
    */
    QGraphicsTextItem* timesUpText = new QGraphicsTextItem(QString("Time's Up  !"));
    QFont titleFont("comic sans",40);
    timesUpText->setFont(titleFont);
    timesUpText->setDefaultTextColor(Qt::white);
    int txPos = this->width()/2 - timesUpText->boundingRect().width()/2;
    int tyPos = 250;
    timesUpText->setPos(txPos,tyPos);
    scene->addItem(timesUpText);

    startPlayer->setMedia(QUrl("qrc:sounds/timesUp.mp3"));
    startPlayer->play();

    Button* playAgain = new Button(QString("Play Again"));
    playAgain->setPos(250,350);
    scene->addItem(playAgain);
    connect(playAgain, SIGNAL(clicked()), this, SLOT(start()));

    Button* quit = new Button(QString("Quit"));
    quit->setPos(250,450);
    scene->addItem(quit);
    connect(quit, SIGNAL(clicked()), this, SLOT(close()));
}
