#ifndef RIGHTRIGHT
#define RIGHTRIGHT

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class RightRight: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    RightRight(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void move();
private:
    int second;
};

#endif // RIGHTRIGHT

