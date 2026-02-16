#include "bola.h"

#include <math.h>

int Bola::diametro = 40;
int Bola::vidasIniciales = 10;
float Bola::rozamiento = 0.9999;
float Bola::elasticidad = 1.2;
float Bola::gravitacion = 50;

Bola::Bola() : Bola(0,0,0,0) {

}

Bola::Bola(float x, float y, float vx, float vy) : posX(x), posY(y), velX(vx), velY(vy),
                                                    vidas(vidasIniciales), color(Qt::black),
                                                    rArriba(0), rAbajo(0), rIzquierda(0), rDerecha(0) {


}

void Bola::mover(float anchura, float altura, int alturaMenuBar) {

    if ( vidas < 0 )
        vidas = 0;

    if ( (posX + diametro) > anchura ) {
        velX = - fabs(velX);
        rDerecha++;
    }

    if ( posX <= 0 ) {
        velX = fabs(velX);
        rIzquierda++;
    }

    if ( (posY + diametro) > altura ) {
        velY = - fabs(velY);
        rAbajo++;
    }

    if ( posY <= alturaMenuBar ) {
        velY = fabs(velY);
        rArriba++;
    }

    posX += velX;
    posY += velY;

    velX = velX * rozamiento;
    velY = velY * rozamiento;

}

float Bola::distancia(Bola *otra) {

    float dist;
    dist = sqrtf(powf(this->posX - otra->posX,2) +
    powf(this->posY - otra->posY,2));

    return dist;
}

bool Bola::choca(Bola *otra) {

    bool hayChoque = false;

    if ( this == otra )
        return hayChoque;

    if ( distancia(otra) > diametro )
        return hayChoque;

    Bola *derecha;
    Bola *izquierda;

    if ( this->posX > otra->posX ) {
        derecha = this;
        izquierda = otra;
    } else {
        derecha = otra;
        izquierda = this;
    }

    if ( izquierda->velX > derecha->velX ) {
        float aux = izquierda->velX;
        izquierda->velX = derecha->velX;
        derecha->velX = aux;
        hayChoque = true;
    }

    Bola * arriba ;
    Bola * abajo ;

    if ( this->posY > otra->posY ) {
        abajo = this;
        arriba = otra;
    } else {
        abajo = otra;
        arriba = this;
    }

    if ( arriba->velY > abajo->velY ) {
        float aux = arriba->velY;
        arriba->velY = abajo->velY;
        abajo->velY = aux;
        hayChoque = true;
    }

    if ( hayChoque ) {
        this->velX = this->velX * elasticidad;
        this->velY = this->velY * elasticidad;
        otra->velX = otra->velX * elasticidad;
        otra->velY = otra->velY * elasticidad;
    }

    return hayChoque;

}

void Bola::pintar(QPainter &pintor) {

    pintor.setBrush(color);
    pintor.drawEllipse(posX, posY, diametro, diametro);
    pintor.drawText(posX - 7, posY + diametro + 15, nombre);

    if (esImagen) {
        pintor.drawImage(posX, posY, img);
    }

    pintor.setBrush(QColor("Green"));

    int anchoBarra = Bola::diametro;
    float division = (float) vidas / (float) Bola::vidasIniciales;

    anchoBarra = anchoBarra * division;
    pintor.drawRect(posX,posY - 20,
                    anchoBarra,5);
    float acabaVerda = posX  + anchoBarra ;


    int mortes = Bola::vidasIniciales  -  vidas;
    division = (float)mortes / (float)Bola::vidasIniciales ;
    anchoBarra = Bola::diametro * division;

    pintor.setBrush(QColor("red"));
    pintor.drawRect(acabaVerda,
                    posY - 20,
                    anchoBarra,
                    5);

    pintor.drawText((posX+diametro/2)-5, (posY+diametro/2)+4, QString::number(vidas));

}

void Bola::restablecerRebotes() {

    rArriba = rAbajo = rIzquierda = rDerecha = 0;

}

void Bola::anotarChoque(int idBola, Bola *pBola) {

    Choque unChoque;
    unChoque.x = posX;
    unChoque.y = posY;
    unChoque.idOtraBola = idBola;
    unChoque.pBola = pBola;

    posicionesChoques.append( unChoque );

}

void Bola::atraer(Bola *pBola) {

    float dist = distancia(pBola);
    dist = dist < diametro * 2 ? diametro * 2: dist;

    float F = gravitacion * 1.1 / powf(dist, 2);
    float dx = pBola->posX - posX;
    float px = dx / dist;

    float dy = pBola->posY - posY;
    float py = dy / dist;

    float Fx = px * F;
    float Fy = py * F;

    velX = velX + Fx;
    velY = velY + Fy;

}

void Bola::atraer(Bola *pBola, float gravedad) {

    float dist = distancia(pBola);
    dist = dist < diametro * 2 ? diametro * 2: dist;

    float F = gravitacion * 1.1 / powf(dist, 2);
    float dx = pBola->posX - posX;
    float px = dx / dist;

    float dy = pBola->posY - posY;
    float py = dy / dist;

    float Fx = px * F;
    float Fy = py * F;

    velX = velX + Fx;
    velY = velY + Fy;

}
