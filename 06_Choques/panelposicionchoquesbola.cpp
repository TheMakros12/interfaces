#include "panelposicionchoquesbola.h"

#include <QDebug>

PanelPosicionChoquesBola::PanelPosicionChoquesBola(Bola *bolaPasada, QWidget *parent) : QWidget(parent), laBola(bolaPasada) {

    resize(400,300);

    setWindowTitle(laBola->nombre);

    QTimer *temporizador = new QTimer();
    temporizador->setSingleShot(false);
    temporizador->setInterval(40);

    connect(temporizador, SIGNAL(timeout()),
            this, SLOT(slotTemporizador()));

    temporizador->start();

}

void PanelPosicionChoquesBola::paintEvent(QPaintEvent *event) {

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

    for (const Choque &c : laBola->posicionesChoques) {
        float posicionX = (c.x * (float)width()) / (float)laBola->anchuraJuego;
        float posicionY = (c.y * (float)height()) / (float)laBola->alturaJuego;
        pintor.setBrush(c.pBola->color);
        pintor.drawEllipse(posicionX, posicionY, 8, 8);
    }

}

void PanelPosicionChoquesBola::slotTemporizador() {
    update();
}
