#include "Player.h"
#include "Platform.h"
#include "PlatformSmallTall.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>


const float GRAVITY = 980.0; // Gravity constant (in pixels per second squared)
const float TIME_STEP = 0.016; // Time step for simulation (60 FPS)
const float MOVE_SPEED = 30.0; // Movement speed (in pixels per frame)
const float JUMP_SPEED = 700.0; // Jump speed (in pixels per second)
const float GROUND_TOLERANCE = 1.0; // Tolerance for ground check

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

    // Initialize velocity
    velocity.x = 0;
    velocity.y = 0;

                
    // Set up a timer to handle gravity and movement updates
    gravityTimer = new QTimer();
    connect(gravityTimer, &QTimer::timeout, this, &Player::handleGravity);
    gravityTimer->start(TIME_STEP * 1000); // Convert TIME_STEP to milliseconds

    // Set up a timer to handle sprite animation updates
    movingTimer = new QTimer();
    movingTimer->setInterval(100);
    connect(movingTimer , &QTimer::timeout , this , &Player::handleHorizon);
    movingTimer->start();

}

void Player::handleGravity() {
    // Check for collision with platforms
    if (!movingUp && ( isOnPlatformSmallTall()||isOnPlatform() ) ) {
        velocity.y = 0; // Reset velocity when hitting a platform
    } else {
        // Update the vertical velocity based on gravity
        velocity.y += GRAVITY * TIME_STEP;

        // Update the position based on the new velocity
        position.y += velocity.y * TIME_STEP;
    }


    // Update the player's position in the scene
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

void Player::handleRightMovement() {

    movingRight = true;
    movingLeft = false;
    isRightDirection = true; // Set direction to right
   updateSprite();
}

void Player::handleLeftMovement() {

    // Update sprite to run left
    movingRight = false;
    movingLeft = true;
    isRightDirection = false; // Set direction to left
    updateSprite();
    
}

void Player::handleUpMovement() {
    // Implement up movement logic
    movingUp = true;
    velocity.y = -JUMP_SPEED; // Jumping up
   
}

void Player::handleMovement(QKeyEvent *event) {
    // Implement movement handling based on key press
    if (event->key() == Qt::Key_Right) {
        handleRightMovement();
    } else if (event->key() == Qt::Key_Left) {
        handleLeftMovement();
    } else if (event->key() == Qt::Key_Up || event->key() == Qt::Key_Space) {
        handleUpMovement();
    }
}
void Player::handleKeyRelease(QKeyEvent *event) {
    // Implement sprite update based on key release
    if (event->key() == Qt::Key_Right) {
        movingRight = false;
    } else if (event->key() == Qt::Key_Left) {
        movingLeft = false;
    } else if (event->key() == Qt::Key_Up || event->key() == Qt::Key_Space) {
        movingUp = false;
    }

    updateSprite(); // Call updateSprite to update the sprite based on the current
}


void Player::updateSprite() {
    // Implement sprite update logic based on current frame
    if (movingRight) {
        // Update sprite to run right
        QPixmap frame = spriteRunRight.copy(currentFrame * spriteRunRight.width() / 30, 0, spriteRunRight.width() / 30, spriteRunRight.height());
        setPixmap(frame.scaled(193.076, 225.9));
    } else if (movingLeft) {
        // Update sprite to run left
        QPixmap frame = spriteRunLeft.copy(currentFrame * spriteRunLeft.width() / 30, 0, spriteRunLeft.width() / 30, spriteRunLeft.height());
        setPixmap(frame.scaled(193.076, 225.9));
    } else {
        // Update sprite to stand still with animation
        if (isRightDirection) {
            QPixmap frame = spriteStandRight.copy(currentFrame * spriteStandRight.width() / 60, 0, spriteStandRight.width() / 60, spriteStandRight.height());
            setPixmap(frame.scaled(100, 225.9));
        } else {
            QPixmap frame = spriteStandLeft.copy(currentFrame * spriteStandLeft.width() / 60, 0, spriteStandLeft.width() / 60, spriteStandLeft.height());
            setPixmap(frame.scaled(100, 225.9));
        }
    }

    // Update frame for next animation step
    currentFrame = (currentFrame + 1) % 30;
}


void Player::handleHorizon() {
    if (movingRight) {
        if (position.x > sceneWidth / 2) {
            distanceTraveled += MOVE_SPEED;
            emit moveBackgroundLeft(MOVE_SPEED);
        } else {
            position.x += MOVE_SPEED;
            distanceTraveled += MOVE_SPEED;
        }
    }
    if (movingLeft && position.x > 0) {
        position.x -= MOVE_SPEED;
    }

    // Ensure the player stays on the platform during horizontal movement

    if (!movingUp && ( isOnPlatformSmallTall()||isOnPlatform() )) {
        velocity.y = 0;
    }

    updateSprite();
}

