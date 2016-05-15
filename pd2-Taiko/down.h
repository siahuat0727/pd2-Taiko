#ifndef DOWN
#define DOWN


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Down: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Down(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void move();
};

#endif // DOWN

