#ifndef AMINDOPINGI_BACKGROUNDHILLS_H
#define AMINDOPINGI_BACKGROUNDHILLS_H

#include <QTimer>
#include <QGraphicsPixmapItem>

class BackgroundHills : public QObject, public QGraphicsPixmapItem {
Q_OBJECT

private:
    int currentX;
    QPixmap *scaledImage;

public slots:

    void moveLeft(float speed);

public:
    BackgroundHills(int screenWidth, int screenHeight, QGraphicsItem *parent = nullptr);
};

#endif
