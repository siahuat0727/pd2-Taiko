#ifndef UP
#define UP

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Up: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Up(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void move();
};

#endif // UP

