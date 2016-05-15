#ifndef SPAWN
#define SPAWN

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Spawn: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Spawn();
public slots:
    void spawn();
private:
    int numOfType;
};

#endif // SPAWN

