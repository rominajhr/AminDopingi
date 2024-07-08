#ifndef AMINDOPINGI_GAME_H
#define AMINDOPINGI_GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "view/Background.h"


class Game : public QGraphicsView {
private:
    QGraphicsScene *scene;
    Background *background;

public:
    Game();
};

#endif
