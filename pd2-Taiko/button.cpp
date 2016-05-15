#include "button.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QFont>
#include <QMediaPlayer>

Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    setRect(0,0,150,50);
    /*
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBrush(brush);
    */

    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width();
    int yPos = rect().height()/2 - text->boundingRect().height();
    text->setPos(xPos,yPos);
    text->setDefaultTextColor(Qt::lightGray);
    text->setFont(QFont("times",30));

    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
    clickPlayer = new QMediaPlayer();
    clickPlayer->setMedia(QUrl("qrc:sounds/button.mp3"));
    clickPlayer->play();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    text->setDefaultTextColor(Qt::white);
    hoverEnterPlayer = new QMediaPlayer();
    hoverEnterPlayer->setMedia(QUrl("qrc:sounds/clear.mp3"));
    hoverEnterPlayer->play();
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    text->setDefaultTextColor(Qt::lightGray);
}
