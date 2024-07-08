#include "BackgroundHills.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <cmath> // Include cmath for fmod

BackgroundHills::BackgroundHills(int screenWidth, int screenHeight, QGraphicsItem* parent)
        : QGraphicsPixmapItem(parent), currentX(0) {
    QPixmap background(":/images/hills");
    background = background.scaled(background.width(), screenHeight, Qt::KeepAspectRatioByExpanding);
    scaledImage = new QPixmap(background);
    background = background.copy(0, 0, background.width(), screenHeight);
    setPixmap(background);
    setPos(0, 0);

}

void BackgroundHills::moveLeft(float speed) {
    currentX = fmod(currentX + speed, scaledImage->width());
    QPixmap croppedImage = scaledImage->copy(currentX, 0, scaledImage->width(), scaledImage->height());
    setPixmap(croppedImage);
}
