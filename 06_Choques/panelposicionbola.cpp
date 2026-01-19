#include "panelposicionbola.h"

#include <QDebug>

PanelPosicionBola::PanelPosicionBola(Bola * bolaPasada, QWidget *parent) : QWidget(parent), laBola(bolaPasada) {

    QTimer *temporizador = new QTimer();
    temporizador->setSingleShot(false);
    temporizador->setInterval(40);

    connect(temporizador, SIGNAL(timeout()),
            this, SLOT(slotTemporizador()));

    temporizador->start();


}

void PanelPosicionBola::paintEvent(QPaintEvent *event) {

    QPainter pintor(this);
    QBrush brush(laBola->color, Qt::Dense4Pattern);
    pintor.setBrush(brush);

    float posicionX = (laBola->posX * width()) / laBola->anchuraJuego;
    float posicionY = (laBola->posY * height()) / laBola->alturaJuego;

    pintor.drawRect(posicionX,
                    0,
                    12,
                    height());

    pintor.drawRect(0,
                    posicionY,
                    width(),
                    12);

}

void PanelPosicionBola::mousePressEvent(QMouseEvent *event) {

    float posicionX = (event->x() * laBola->anchuraJuego) / width();
    float posicionY = (event->y() * laBola->alturaJuego) / height();

    laBola->posX = posicionX;
    laBola->posY = posicionY;

}

void PanelPosicionBola::slotTemporizador() {

    update();

}
