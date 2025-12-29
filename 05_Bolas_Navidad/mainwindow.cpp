#include "mainwindow.h"

#include <QTimer>
#include <QDebug>
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    dInformacion = NULL;

    QTimer *temporizador = new QTimer();
    temporizador->setSingleShot(false);
    temporizador->setInterval(40);
    temporizador->start();

    connect(temporizador, SIGNAL(timeout()),
            this, SLOT(slotTemporizador()));

    resize(600,400);

    crearActions();
    crearMenu();
    crearBolas();

}

void MainWindow::crearBolas() {

    int anchura = width();
    int altura = height();

    for (int i = 0; i < 10; i++) {
        int posIniX = random() % anchura;
        int posIniY = random() % altura;

        float velIniX = (float)(random() % 100) / 50 - 1;
        float velIniY = (float)(random() % 100) / 50 - 1;

        Bola *nueva = new Bola(posIniX, posIniY, velIniX, velIniY);

        nueva->color = QColor( rand() % 255, rand() % 255, rand() % 255 );

        bolas.append(nueva);
    }

}

void MainWindow::crearActions() {

    actionInformacion = new QAction("Información");
    connect(actionInformacion, SIGNAL(triggered()),
            this, SLOT(slotDInformacion()));

}

void MainWindow::crearMenu() {

    QMenuBar *barraMenu = this->menuBar();
    QMenu *menuArchivo = barraMenu->addMenu("Archivo");
    menuArchivo->addAction(actionInformacion);

}

void MainWindow::paintEvent(QPaintEvent *event) {

    QPainter pintor(this);

    for (int i = 0; i < bolas.size(); i++) {
        bolas[i]->pintar(pintor);
    }

}

void MainWindow::slotTemporizador() {

    int anchuraV = width();
    int alturaV = height();
    int alturaMenuBar = menuBar()->height();

    for (int i = 0; i < bolas.size(); i++) {
        bolas[i]->mover(anchuraV, alturaV, alturaMenuBar);
    }

    for (int i = 0; i < bolas.size(); i++) {
        for (int j = 0; j < bolas.size(); j++) {
            if ( i != j )
                bolas[i]->choca(bolas[j]);
        }
    }

    update();

}

void MainWindow::slotDInformacion() {

    if ( dInformacion == NULL)
        dInformacion = new DInformacion(width(),
                                        height(),
                                        bolas.size());

    dInformacion->show();

}
