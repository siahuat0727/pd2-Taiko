#ifndef LEFT
#define LEFT

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Left: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Left(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void move();
};

#endif // LEFT

