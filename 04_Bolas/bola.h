#ifndef BOLA_H_
#define BOLA_H_

#include <QPainter>
#include <QColor>
#include <QImage>

class Bola {

public:
    Bola();
    Bola(float, float, float, float);
    float posX, posY, velX, velY;
    QColor color;
    QString nombre;
    static int diametro;
    static int vidasIniciales;
    bool esImagen;
    QImage img;
    int vidas;
    int rArriba, rAbajo, rDerecha, rIzquierda;

    void mover(float, float, int);
    float distancia(Bola*);
    bool choca(Bola*);
    void pintar(QPainter&);

};

#endif

