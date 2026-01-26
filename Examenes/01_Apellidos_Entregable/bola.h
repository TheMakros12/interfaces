#ifndef _BOLA_H_
#define _BOLA_H_
#include <QPainter>
#include <QColor>
#include <QImage>

class Bola {

public:

    Bola();
    Bola(float,float,float,float);
    float posX,posY,velX,velY;
    QColor color;
    QString nombre, apellido_1, apellido_2;

    bool esImagen;
    QImage imagen;
    int vidas;

    float anchuraJuego, alturaJuego;


    int rArriba, rAbajo, rDerecha, rIzquierda;

    static int diametro;
    static int vidasIniciales;

    void mover(float, float);

    void pintar(QPainter&);

    float distancia(Bola * otra);
    bool choca(Bola *);


};


#endif
