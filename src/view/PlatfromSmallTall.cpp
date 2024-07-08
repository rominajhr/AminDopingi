#include "PlatformSmallTall.h"

PlatformSmallTall::PlatformSmallTall(int screenWidth, int screenHeight) {
    platformPixmap = QPixmap(":/images/platformSmallTall");
    setPixmap(platformPixmap);
}

void PlatformSmallTall::moveLeft(float speed) {
    setPos(x() - speed, y());
}
