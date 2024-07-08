#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QKeyEvent>
#include "Position.h"

class Player : public QObject, public QGraphicsPixmapItem {
Q_OBJECT

public:
    Player(int SceneWidth, int SceneHeight, QGraphicsItem *parent = nullptr);

    void handleRightMovement();
    void handleLeftMovement();
    void handleUpMovement();
    void handleMovement(QKeyEvent *event);
    void handleKeyRelease(QKeyEvent *event);

    float distanceTraveled; // field to track the distance traveled by the player
    QTimer *movingTimer;

signals:
    void moveBackgroundLeft(float speed);

public slots:
    void handleGravity();
    void handleHorizon();
    void updateSprite();


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
    int currentFrame;

    bool movingUp;
    bool movingRight;
    bool movingLeft;
    bool isRightDirection;

    QTimer *gravityTimer;


};

#endif
