#ifndef COMBO
#define COMBO

#include <QGraphicsTextItem>
#include <QMediaPlayer>

class Combo: public QGraphicsTextItem{
public:
    Combo(QGraphicsItem * parent=0);
    void increase();
    void setZero();
    int combo;
private:
    QMediaPlayer * clearPlayer;
    QMediaPlayer * player;
    QMediaPlayer * missPlayer;
};

#endif // COMBO

