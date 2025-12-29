#include "bola.h"

Bola::Bola(float px, float py, float vx, float vy) :
    posX(px), posY(py), velX(vx), velY(vy)
{

    diametro = 40;

}

Bola::Bola() {

    posX = posY = 400;
    velX = velY = 3.2;
    diametro = 40;

}

void Bola::mover(int anchuraV, int alturaV, int alturaMenuBar) {

    if ( posX >= (anchuraV - diametro) )
        velX = -fabs(velX);
    if ( posX <= 0 )
        velX = fabs(velX);

    if ( posY > (alturaV - diametro))
        velY = -fabs(velY);
    if ( posY <= alturaMenuBar )
        velY = fabs(velY);

    posX += velX;
    posY += velY;

}

void Bola::pintar(QPainter &pintor) {

    pintor.drawEllipse(posX, posY, diametro, diametro);

}
