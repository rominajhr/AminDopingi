#ifndef AMINDOPINGI_PLATFORMSMALLTALL_H
#define AMINDOPINGI_PLATFORMSMALLTALL_H


#include <QGraphicsPixmapItem>
#include <QPixmap>

class PlatformSmallTall : public QGraphicsPixmapItem {
public:

    PlatformSmallTall(int screenWidth, int screenHeight);
    void moveLeft(float speed);

private:
    QPixmap platformPixmap;
};

#endif
