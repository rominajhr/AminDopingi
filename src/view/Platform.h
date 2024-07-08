#ifndef AMINDOPINGI_PLATFORM_H
#define AMINDOPINGI_PLATFORM_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Platform : public QGraphicsPixmapItem {
public:

    Platform(int screenWidth, int screenHeight);
    void moveLeft(float speed);

private:
    QPixmap platformPixmap;
};

#endif
