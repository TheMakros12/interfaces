#include "bola.h"
#include <stdlib.h>

int Bola::diametro = 40;

Bola::Bola() : Bola(0,0,0,0) {

}

Bola::Bola(float px, float py, float vx, float vy) :
    posX(px), posY(py), velX(vx), velY(vy)
{

    color = QColor("black");

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

float Bola::distancia(Bola *otraBolaBola) {

    float dist;
    dist = sqrtf(
            powf( (posX - otraBolaBola->posX), 2 ) +
            powf( (posY - otraBolaBola->posY), 2 ) );
    return dist;

}

bool Bola::choca(Bola *otraBola) {

    bool hayColision = false;

    if ( this == otraBola )
        return hayColision;

    if ( distancia(otraBola) > diametro )
        return hayColision;

    Bola *derecha;
    Bola *izquierda;

    if ( this->posX > otraBola->posX ) {
        derecha = this;
        izquierda = otraBola;
    } else {
        derecha = otraBola;
        izquierda = this;
    }

    if ( izquierda->velX > derecha->velX ) {
        float aux = izquierda->velX;
        izquierda->velX = derecha->velX;
        derecha->velX = aux;
        hayColision = true;
    }

    Bola * arriba ;
    Bola * abajo ;

    if ( this->posY > otraBola->posY ) {
        abajo = this;
        arriba = otraBola;
    } else {
        abajo = otraBola;
        arriba = this;
    }

    if ( arriba->velY > abajo->velY ) {
        float aux = arriba->velY;
        arriba->velY = abajo->velY;
        abajo->velY = aux;
        hayColision = true;
    }

    return hayColision;

}

void Bola::pintar(QPainter &pintor) {

    pintor.setBrush(color);
    pintor.drawEllipse(posX, posY, diametro, diametro);

}
