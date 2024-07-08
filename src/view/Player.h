#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include "Position.h"

class Player : public QObject, public QGraphicsPixmapItem {
Q_OBJECT

public:
    Player(int SceneWidth, int SceneHeight, QGraphicsItem *parent = nullptr);

    void handleRightMovement();
    void handleLeftMovement();
    void handleUpMovement();

    float distanceTraveled; // field to track the distance traveled by the player



public slots:
    void handleGravity();



private:
    bool isOnPlatform();
    bool isOnPlatformSmallTall();
    Position position;
    Position velocity;

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

    QTimer *gravityTimer;


};

#endif
