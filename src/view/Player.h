#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include "Position.h"

class Player : public QObject, public QGraphicsPixmapItem {


public:
    Player(int SceneWidth, int SceneHeight, QGraphicsItem *parent = nullptr);


private:
    Position position;

    int sceneWidth;
    int sceneHeight;

    QPixmap spriteRunLeft;
    QPixmap spriteRunRight;
    QPixmap spriteStandLeft;
    QPixmap spriteStandRight;


};

#endif
