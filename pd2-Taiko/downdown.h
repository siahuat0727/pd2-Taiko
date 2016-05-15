#ifndef DOWNDOWN
#define DOWNDOWN

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class DownDown: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    DownDown(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void move();
private:
    int second;
};

#endif // DOWNDOWN

