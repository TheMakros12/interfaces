#include "mainwindow.h"

#include <QTimer>
#include <QDebug>
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    dInformacion = NULL;
    dInfoBolas = NULL;
    bolaJugador = NULL;

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

}

void MainWindow::crearMenu() {

    QMenuBar *barraMenu = this->menuBar();
    QMenu *menuArchivo = barraMenu->addMenu("Archivo");
    menuArchivo->addAction(actionDInformacion);
    menuArchivo->addAction(actionDInfoBolas);

}

void MainWindow::keyPressEvent(QKeyEvent *event) {

    int codigo = event->key();
    switch( codigo ) {
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
                bolas[i]->choca(bolas[j]);
        }
    }

    for (int i = 0; i < bolas.size(); i++) {
        bolaJugador->choca(bolas[i]);
    }

    bolaJugador->mover(anchuraV, alturaV, alturaMenuBar);

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
