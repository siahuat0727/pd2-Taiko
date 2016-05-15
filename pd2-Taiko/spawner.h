#ifndef SPAWNER
#define SPAWNER

#include <QObject>

class Spawner: public QObject{
    Q_OBJECT

public slots:
    void spawn();
};


#endif // SPAWNER

