#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include "Position.h"

class Player : public QObject, public QGraphicsPixmapItem {
Q_OBJECT

public:
    Player(int SceneWidth, int SceneHeight, QGraphicsItem *parent = nullptr);

    float distanceTraveled; // field to track the distance traveled by the player


private:
    Position position;

    int sceneWidth;
    int sceneHeight;

    QPixmap spriteRunLeft;
    QPixmap spriteRunRight;
    QPixmap spriteStandLeft;
    QPixmap spriteStandRight;

    bool movingUp;
    bool movingRight;
    bool movingLeft;
    bool isRightDirection;


};

#endif
