#ifndef AMINDOPINGI_GAME_H
#define AMINDOPINGI_GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "view/Background.h"
#include "view/BackgroundHills.h"
#include "view/Platform.h"


class Game : public QGraphicsView {
private:
    QGraphicsScene *scene;
    std::vector<Platform*> platforms;
    Background *background;
    BackgroundHills *backgroundHills;

public:
    Game();
};

#endif
