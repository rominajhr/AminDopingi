#ifndef AMINDOPINGI_GAME_H
#define AMINDOPINGI_GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "view/Player.h"
#include "view/Background.h"
#include "view/BackgroundHills.h"
#include "view/Platform.h"
#include "view/PlatformSmallTall.h"
#include <vector>


class Game : public QGraphicsView {
Q_OBJECT

private:
    QGraphicsScene *scene;
    Player *player;
    std::vector<Platform*> platforms;
    std::vector<PlatformSmallTall*> platformSmallTalls;
    Background *background;
    BackgroundHills *backgroundHills;

    int amountDistance; 

    void handleGameOver(); // New method
    void handleVictory(); // New method

public:
    Game();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private slots:
    void moveBackgroundLeft(float speed);
    void checkGameState(); // New slot

};

#endif
