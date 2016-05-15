#ifndef RIGHT
#define RIGHT

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Right: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Right(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void move();
};

#endif // RIGHT

