#ifndef BOLA_H
#define BOLA_H

#include <math.h>
#include <QPainter>
#include <QColor>

class Bola {

public:
    Bola();
    Bola(float px, float py, float vx, float vy);

    static int diametro;
    float posX, posY;
    float velX, velY;
    QColor color;

    void mover(int, int, int);
    float distancia(Bola *otraBola);
    bool choca(Bola *otraBola);
    void pintar(QPainter &pintor);

};
#endif
