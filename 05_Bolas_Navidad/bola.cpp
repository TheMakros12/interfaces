#include "bola.h"
#include <stdlib.h>

int Bola::diametro = 40;
int Bola::vidasIniciales = 10;

Bola::Bola(QObject *parent): Bola(0, 0, 0, 0, parent) {
}

Bola::Bola(float px, float py, float vx, float vy, QObject *parent): QObject(parent),
    posX(px), posY(py), velX(vx), velY(vy), color(Qt::black), nombre("Nombre"),
    especial(false), vidas(vidasIniciales), rArriba(0), rAbajo(0), rDerecha(0), rIzquierda(0) {
}

void Bola::mover(int anchuraV, int alturaV, int alturaMenuBar) {

    if ( vidas < 0 )
        vidas = 0;

    if ( posX >= (anchuraV - diametro) ){
        velX = -fabs(velX);
        rDerecha++;
    }
    if ( posX <= 0 ){
        velX = fabs(velX);
        rIzquierda++;
    }

    if ( posY > (alturaV - diametro) ){
        velY = -fabs(velY);
        rAbajo++;
    }
    if ( posY <= alturaMenuBar ){
        velY = fabs(velY);
        rArriba++;
    }

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

    pintor.drawText(posX, posY + diametro + 15, nombre);

    if ( especial ) {
        pintor.setBrush(QColor("White"));
        pintor.drawEllipse(posX+10,
                           posY+10,
                           diametro-20,
                           diametro-20);
    }

    pintor.setBrush(QColor("Green"));

    int anchoBarra = Bola::diametro;
    float division = (float) vidas / (float) Bola::vidasIniciales;

    anchoBarra = anchoBarra * division;
    pintor.drawRect(posX,
                    posY - 20,
                    anchoBarra,
                    5);
    float acabaVerda = posX  + anchoBarra ;


    int mortes = Bola::vidasIniciales  -  vidas;
    division = (float)mortes / (float)Bola::vidasIniciales ;
    anchoBarra = Bola::diametro * division;

    pintor.setBrush(QColor("Red"));
    pintor.drawRect(acabaVerda,
                    posY - 20,
                    anchoBarra,
                    5);

    pintor.drawText(posX+diametro/2, posY+diametro/2, QString::number(vidas));

}

void Bola::restablecerRebotes() {

    rArriba = rAbajo = rIzquierda = rDerecha = 0;

}
