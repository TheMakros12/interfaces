#include "widgetchoque.h"

#include <QDebug>
#include <QTimer>

WidgetChoque::WidgetChoque(Bola *laBola, QWidget *parent): QWidget(parent), bola(laBola) {

    setWindowTitle("Choques de las Bolas");

    resize(400,300);

    QTimer *temporizador = new QTimer();
    temporizador->setSingleShot(false);
    temporizador->setInterval(200);
    connect(temporizador, SIGNAL(timeout()),
            this, SLOT(slotTemporizador()));
    temporizador->start();

}

void WidgetChoque::paintEvent(QPaintEvent *event) {

    QPainter pintor(this);

    for (const Choque &c : bola->posicionesChoques) {
        float posicionX = (c.x * (float)width()) / (float)bola->anchuraJuego;
        float posicionY = (c.y * (float)height()) / (float)bola->alturaJuego;
        pintor.setBrush(c.pBola->color);
        pintor.drawEllipse(posicionX, posicionY, 8, 8);
    }

}

void WidgetChoque::slotTemporizador() {
    repaint();
}
