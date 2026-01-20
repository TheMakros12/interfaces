#ifndef BOLA_H
#define BOLA_H

#include <math.h>
#include <QPainter>
#include <QColor>
#include <QObject>
#include <QVector>

class Choque {

public:
    Choque(float x = 0.0f, float y = 0.0f);
    float x,y;

};

class Bola : public QObject {
Q_OBJECT

public:
    explicit Bola(QObject *parent = nullptr);
    Bola(float px, float py, float vx, float vy, QObject *parent = nullptr);

    static int diametro;
    static int vidasIniciales;

    float posX, posY;
    float velX, velY;
    QColor color;
    QString nombre;
    int vidas;
    int rArriba, rAbajo, rDerecha, rIzquierda;
    bool especial;
    float anchuraJuego, alturaJuego;

    QVector<Choque> posicionesChoque;

    void mover(int, int, int);
    float distancia(Bola *otraBola);
    bool choca(Bola *otraBola);
    void pintar(QPainter &pintor);
    void restablecerRebotes();

};
#endif
