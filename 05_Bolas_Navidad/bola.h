#ifndef BOLA_H
#define BOLA_H

#include <math.h>
#include <QPainter>

class Bola {

public:
    Bola();
    Bola(float px, float py, float vx, float vy);

    int diametro;
    float posX, posY;
    float velX, velY;

    void mover(int, int, int);
    void pintar(QPainter &pintor);

};
#endif
