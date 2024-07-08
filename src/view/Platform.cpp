#include "Platform.h"

Platform::Platform(int screenWidth, int screenHeight) {
    platformPixmap = QPixmap(":/images/platform");
    setPixmap(platformPixmap);
}

void Platform::moveLeft(float speed) {
    setPos(x() - speed, y());
}
