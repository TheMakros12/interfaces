#include "widgetchoque.h"

#include <QDebug>
#include <QTimer>

WidgetChoque::WidgetChoque(Bola *laBola, QWidget *parent): QWidget(parent), bola(laBola) {

    resize(400,300);

}

void WidgetChoque::paintEvent(QPaintEvent *event) {

    QPainter pintor(this);

    for (const Choque &c : bola->posicionesChoque) {
        float posicionX = (c.x * width()) / bola->anchuraJuego;
        float posicionY = (c.y * height()) / bola->alturaJuego;
        pintor.setBrush(bola->color);
        pintor.drawEllipse(posicionX, posicionY, 8, 8);
    }

}
