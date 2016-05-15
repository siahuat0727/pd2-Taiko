#ifndef LEFTLEFT
#define LEFTLEFT

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class LeftLeft: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    LeftLeft(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void move();
private:
    int second;
};

#endif // LEFTLEFT

