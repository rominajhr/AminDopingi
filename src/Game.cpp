#include "Game.h"


Game::Game() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    showFullScreen();
      scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());

    background = new Background(width(), height());
    scene->addItem(background);
    backgroundHills = new BackgroundHills(width(), height());
    scene->addItem(backgroundHills);

    
    setScene(scene);
}
