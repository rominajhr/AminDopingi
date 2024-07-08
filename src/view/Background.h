#ifndef AMINDOPINGI_BACKGROUND_H
#define AMINDOPINGI_BACKGROUND_H

#include <QTimer>
#include <QGraphicsPixmapItem>

class Background : public QObject, public QGraphicsPixmapItem {
Q_OBJECT

private:
    int currentX;
    QPixmap *scaledImage;

public slots:

    void moveLeft(float speed);

public:
    Background(int screenWidth, int screenHeight, QGraphicsItem *parent = nullptr);
};

#endif
