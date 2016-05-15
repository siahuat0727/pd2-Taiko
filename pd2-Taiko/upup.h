#ifndef UPUP
#define UPUP

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class UpUp: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    UpUp(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void move();
private:
    int second;
};

#endif // UPUP

