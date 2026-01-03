#include "mainwindow.h"

#include <QTimer>
#include <QDebug>
#include <stdlib.h>

bool MainWindow::bolasDesaparecen = true;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    bolaJugador = NULL;
    dInformacion = NULL;
    dInfoBolas = NULL;
    dTablaBolas = NULL;
    dTablaRebotes = NULL;

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

    QStringList nombres = {"marcos", "lucia", "juan","david","alex","paula","aroa","alba","diego","modest","perico","andres"
    };

    int anchura = width();
    int altura = height();

    for (int i = 0; i < 10; i++) {
        int posIniX = random() % anchura;
        int posIniY = random() % altura;

        float velIniX = (float)(random() % 100) / 50 - 1;
        float velIniY = (float)(random() % 100) / 50 - 1;

        Bola *nueva = new Bola(posIniX, posIniY, velIniX, velIniY);

        nueva->color = QColor( rand() % 255, rand() % 255, rand() % 255 );
        nueva->nombre = nombres.at(i % nombres.size());

        bolas.append(nueva);
    }

    bolaJugador = new Bola(200, 300, 0, 0);
    bolaJugador->color = QColor(255, 0, 0);
    bolaJugador->especial = true;

}

void MainWindow::crearActions() {

    actionDInformacion = new QAction("Información");
    connect(actionDInformacion, SIGNAL(triggered()),
            this, SLOT(slotDInformacion()));

    actionDInfoBolas = new QAction("Info Bolas");
    connect(actionDInfoBolas, SIGNAL(triggered()),
            this, SLOT(slotDInfoBolas()));

    actionDTablaBolas = new QAction("Tabla Bolas");
    connect(actionDTablaBolas, SIGNAL(triggered()),
            this, SLOT(slotDTablaBolas()));

    actionDTablaRebotes = new QAction("Tabla Rebotes");
    connect(actionDTablaRebotes, SIGNAL(triggered()),
            this, SLOT(slotDTablaRebotes()));

}

void MainWindow::crearMenu() {

    QMenuBar *barraMenu = this->menuBar();
    QMenu *menuArchivo = barraMenu->addMenu("Archivo");
    menuArchivo->addAction(actionDInformacion);
    menuArchivo->addAction(actionDInfoBolas);
    menuArchivo->addAction(actionDTablaBolas);
    menuArchivo->addAction(actionDTablaRebotes);

}

void MainWindow::keyPressEvent(QKeyEvent *event) {

    if ( !bolaJugador )
        return;

    switch( event->key() ) {
        case Qt::Key_Up:
            bolaJugador->velY = bolaJugador->velY - 0.1;
            break;
        case Qt::Key_Down:
            bolaJugador->velY = bolaJugador->velY + 0.1;
            break;
        case Qt::Key_Right:
            bolaJugador->velX = bolaJugador->velX + 0.1;
            break;
        case Qt::Key_Left:
            bolaJugador->velX = bolaJugador->velX - 0.1;
            break;
    }

}

void MainWindow::paintEvent(QPaintEvent *event) {

    QPainter pintor(this);

    for (int i = 0; i < bolas.size(); i++) {
        bolas[i]->pintar(pintor);
    }

    if (bolaJugador)
        bolaJugador->pintar(pintor);

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
                if (bolas[i]->choca(bolas[j])) {
                    bolas.at(i)->vidas--;
                    bolas.at(j)->vidas--;

                }
        }
    }

    if ( bolaJugador ) {
        bolaJugador->mover(anchuraV, alturaV, alturaMenuBar);

        for (int i = 0; i < bolas.size(); i++) {
            if (bolaJugador->choca(bolas[i])) {
                bolas[i]->vidas--;
                bolaJugador->vidas--;
            }
        }
    }


    for (int i = 0; i < bolas.length() && bolasDesaparecen; i++) {
        if (bolas.at(i)->vidas <= 0) {
            delete bolas.at(i);
            bolas.removeAt(i);
            break;
        }
    }

    if ( bolaJugador && bolaJugador->vidas <= 0 && bolasDesaparecen ) {
        delete bolaJugador;
        bolaJugador = nullptr;
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


void MainWindow::slotDInfoBolas() {

    if ( dInfoBolas == NULL )
        dInfoBolas = new DInfoBolas(&bolas);

    dInfoBolas->show();

}

void MainWindow::slotDTablaBolas() {

    if ( dTablaBolas == NULL )
        dTablaBolas = new DTablaBolas(&bolas);

    dTablaBolas->show();

}

void MainWindow::slotDTablaRebotes() {

    if ( dTablaRebotes == NULL )
        dTablaRebotes = new DTablaRebotes(&bolas);

    dTablaRebotes->show();

}
