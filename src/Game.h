#ifndef AMINDOPINGI_GAME_H
#define AMINDOPINGI_GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "view/Background.h"
#include "view/BackgroundHills.h"


class Game : public QGraphicsView {
private:
    QGraphicsScene *scene;
    Background *background;
    BackgroundHills *backgroundHills;

public:
    Game();
};

#endif
