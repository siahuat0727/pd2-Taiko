#ifndef COUNTDOWN
#define COUNTDOWN

#include <QGraphicsTextItem>
#include <QTimer>

class CountDown: public QGraphicsTextItem{
    Q_OBJECT
public:
    CountDown(QGraphicsItem * parent=0);
    int time;
    QTimer * timer;
    QTimer * deleteTimer;
public slots:
    void countDown();
    void deleteTimerFunc();
};

#endif // COUNTDOWN

