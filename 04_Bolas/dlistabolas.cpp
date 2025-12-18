#include "dlistabolas.h"

#include <QDebug>
#include <QListWidgetItem>
#include <QTimer>
#include <math.h>

DListaBolas::DListaBolas(QVector <Bola*> *lasBolas, QWidget *parent): QDialog(parent) {

    pBolas = lasBolas;

    setupUi(this);

    this->setWindowTitle("Tabla de las Bolas");

    QTimer *temporizador = new QTimer();
    temporizador->setInterval(500);
    temporizador->setSingleShot(false);

    connect(temporizador, SIGNAL(timeout()),
            this, SLOT(slotActualizar()));

    temporizador->start();

}

void DListaBolas::slotEjemplo() {

}

double luminance(const QColor& c)
{
    auto channel = [](double v) {
        v /= 255.0;
        return (v <= 0.03928) ? v / 12.92 : powf((v + 0.055) / 1.055, 2.4);
    };

    double r = channel(c.red());
    double g = channel(c.green());
    double b = channel(c.blue());

    return 0.2126 * r + 0.7152 * g + 0.0722 * b;
}

void DListaBolas::slotActualizar() {

    listaBolas->clear();

    for (int i = 0; i < pBolas->length(); i++) {

        QString cadena("Bola: " + pBolas->at(i)->nombre);
        cadena = cadena + QString(" PosX = " + QString::number(pBolas->at(i)->posX));
        cadena = cadena + QString(" PosY = " + QString::number(pBolas->at(i)->posY));
        cadena = cadena + QString(" VelX = " + QString::number(pBolas->at(i)->velX));
        cadena = cadena + QString(" VelY = " + QString::number(pBolas->at(i)->velY));

        QListWidgetItem *item = new QListWidgetItem(cadena);
        item->setBackground(pBolas->at(i)->color);

        if (luminance(pBolas->at(i)->color) < 0.5)
            item->setForeground(QColor("white"));

        listaBolas->addItem(item);

    }

}
