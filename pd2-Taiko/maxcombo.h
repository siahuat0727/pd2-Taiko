#ifndef MAXCOMBO
#define MAXCOMBO

#include <QGraphicsTextItem>

class MaxCombo: public QGraphicsTextItem{
public:
    MaxCombo(QGraphicsItem * parent=0);
    void updateMaxCombo();
    int getMaxCombo();
private:
    int maxCombo;
};

#endif // MAXCOMBO

