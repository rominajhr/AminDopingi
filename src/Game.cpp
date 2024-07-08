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
    
    int platformSpacing = 400;
    int initialX = 0;
    Platform *platform;
    for (int k = 0; k < 4; ++k) {
        
        platform = new Platform(width(), height());
        platform->setPos(initialX, height() - platform->pixmap().height());
        platforms.push_back(platform);
        scene->addItem(platform);
        initialX += platform->pixmap().width() + platformSpacing;


        //another platform with space
        platform = new Platform(width(), height());
        platform->setPos(initialX, height() - platform->pixmap().height());
        platforms.push_back(platform);
        scene->addItem(platform);
        initialX += platform->pixmap().width();


        //a platform right next to the last platform
        platform = new Platform(width(), height());
        platform->setPos(initialX, height() - platform->pixmap().height());
        platforms.push_back(platform);
        scene->addItem(platform);

        //add another platform
        platform = new Platform(width(), height());
        platform->setPos(initialX, height() - platform->pixmap().height());
        platforms.push_back(platform);
        scene->addItem(platform);
        initialX += platform->pixmap().width() + platformSpacing;
    }
    
    setScene(scene);
}
