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

bool Player::isOnPlatform() {
    QList<QGraphicsItem*> collidingItems1 = scene()->collidingItems(this);
    for (QGraphicsItem* item : collidingItems1) {
        Platform* platform = dynamic_cast<Platform*>(item);
        if (platform) {
            // Check if the player is on top of the platform
            if (position.x + pixmap().width() > platform->x() && position.x < platform->x() + platform->pixmap().width()) {
                position.y = platform->y() - pixmap().height();
                return true;
            }
        }
    }
    return false;
}

bool Player::isOnPlatformSmallTall() {
    QList<QGraphicsItem*> collidingItems2 = scene()->collidingItems(this);
    for (QGraphicsItem* item : collidingItems2) {
        PlatformSmallTall* platformSmallTall = dynamic_cast<PlatformSmallTall*>(item);
        if (platformSmallTall) {
            // Check if the player is on top of the small or tall platform
            if (position.x + pixmap().width() - 10 > platformSmallTall->x() && position.x < platformSmallTall->x() + platformSmallTall->pixmap().width() + 10 &&
                    position.y + pixmap().height() - GROUND_TOLERANCE - platformSmallTall->pixmap().height()/3 <= platformSmallTall->y()) {
                position.y = platformSmallTall->y() - pixmap().height();
                return true;
            }
        }
    }
    return false;
}
