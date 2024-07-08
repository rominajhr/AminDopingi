#include "Player.h"
#include "Platform.h"
#include "PlatformSmallTall.h"
#include <QGraphicsScene>


Player::Player(int SceneWidth, int SceneHeight, QGraphicsItem *parent)
        : QGraphicsPixmapItem(parent), sceneWidth(SceneWidth), sceneHeight(SceneHeight), currentFrame(0), movingRight(false), movingLeft(false), isRightDirection(true), distanceTraveled(0.0) {
    spriteRunLeft = QPixmap(":/images/spriteRunLeft");
    spriteRunRight = QPixmap(":/images/spriteRunRight");
    spriteStandLeft = QPixmap(":/images/spriteStandLeft");
    spriteStandRight = QPixmap(":/images/spriteStandRight");

    // Set initial pixmap and scale it
    QPixmap initialPixmap = spriteStandRight.copy(0, 0, spriteStandRight.width() / 60, spriteStandRight.height());
    setPixmap(initialPixmap.scaled(100, 225.9));

    // Set initial position to bottom-left corner
    position.x = 0;
    position.y = sceneHeight - 225.9; // Start on the ground
    setPos(position.x, position.y);

}
