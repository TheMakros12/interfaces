#include "mainwindow.h"

#include <QTimer>
#include <QDebug>
#include <stdlib.h>

bool MainWindow::bolasDesaparecen = false;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    bolaJugador = NULL;
    dInformacion = NULL;
    dInfoBolas = NULL;
    dTablaBolas = NULL;
    dTablaRebotes = NULL;
    dControlBolas = NULL;

    QTimer *temporizador = new QTimer();
    temporizador->setSingleShot(false);
    temporizador->setInterval(10);
    temporizador->start();

    connect(temporizador, SIGNAL(timeout()),
            this, SLOT(slotTemporizador()));

    resize(800,600);

    crearActions();
    crearMenu();
    crearBolas();

}

void MainWindow::crearBolas() {

    QStringList nombres = {"marcos", "lucia", "juan","david","alex","paula","aroa","alba","diego","modest","perico","andres"};

    int anchura = width();
    int altura = height();

    for (int i = 0; i < 10; i++) {
        int posIniX = (random() % anchura) - 20;
        int posIniY = (random() % altura) - 20;

        float velIniX = (float)(random() % 100) / 50 - 1;
        float velIniY = (float)(random() % 100) / 50 - 1;

        Bola *nueva = new Bola(posIniX, posIniY, velIniX, velIniY, this);

        nueva->color = QColor( rand() % 255, rand() % 255, rand() % 255 );
        nueva->nombre = nombres.at( i % nombres.size() );

        bolas.append(nueva);
    }

    bolaJugador = new Bola(200, 300, 0, 0, this);
    bolaJugador->color = QColor(255, 0, 0);
    bolaJugador->especial = true;

}

void MainWindow::crearActions() {

    actionDInformacion = new QAction("Información");
    actionDInformacion->setShortcut(QKeySequence::WhatsThis);
    connect(actionDInformacion, SIGNAL(triggered()),
            this, SLOT(slotDInformacion()));

    actionGuardarPartida = new QAction("Guardar Partida", this);
    actionGuardarPartida->setShortcut(QKeySequence::Save);
    connect(actionGuardarPartida, SIGNAL(triggered()),
            this, SLOT(slotGuardarPartida()));

    actionCargarPartida = new QAction("Cargar Partida", this);
    actionCargarPartida->setShortcut(QKeySequence::Open);
    connect(actionCargarPartida, SIGNAL(triggered()),
            this, SLOT(slotCargarPartida()));

    actionSalir = new QAction("Salir", this);
    actionSalir->setShortcut(QKeySequence::Quit);
    connect(actionSalir, SIGNAL(triggered()),
            this, SLOT(close()));

    actionDInfoBolas = new QAction("Info Bolas");
    connect(actionDInfoBolas, SIGNAL(triggered()),
            this, SLOT(slotDInfoBolas()));

    actionDTablaBolas = new QAction("Tabla Bolas");
    connect(actionDTablaBolas, SIGNAL(triggered()),
            this, SLOT(slotDTablaBolas()));

    actionDTablaRebotes = new QAction("Tabla Rebotes");
    connect(actionDTablaRebotes, SIGNAL(triggered()),
            this, SLOT(slotDTablaRebotes()));

    actionDControlBolas = new QAction("Control Bolas");
    connect(actionDControlBolas, SIGNAL(triggered()),
            this, SLOT(slotDControlBolas()));

}

void MainWindow::crearMenu() {

    QMenuBar *barraMenu = this->menuBar();

    QMenu *menuPartida = barraMenu->addMenu("Partida");
    menuPartida->addAction(actionDInformacion);
    menuPartida->addAction(actionGuardarPartida);
    menuPartida->addAction(actionCargarPartida);
    menuPartida->addAction(actionSalir);

    QMenu *menuDialogos = barraMenu->addMenu("Diálogos");
    menuDialogos->addAction(actionDInfoBolas);
    menuDialogos->addAction(actionDTablaBolas);
    menuDialogos->addAction(actionDTablaRebotes);
    menuDialogos->addAction(actionDControlBolas);

}

void MainWindow::paintEvent(QPaintEvent *event) {

    QPainter pintor(this);

    for (int i = 0; i < bolas.size(); i++) {
        bolas[i]->pintar(pintor);
    }

    if ( bolaJugador )
        bolaJugador->pintar(pintor);

}

void MainWindow::keyPressEvent(QKeyEvent *event) {

    if ( !bolaJugador )
        return;

    switch( event->key() ) {
        case Qt::Key_Up:
            bolaJugador->velY = bolaJugador->velY - 0.1; break;
        case Qt::Key_Down:
            bolaJugador->velY = bolaJugador->velY + 0.1; break;
        case Qt::Key_Right:
            bolaJugador->velX = bolaJugador->velX + 0.1; break;
        case Qt::Key_Left:
            bolaJugador->velX = bolaJugador->velX - 0.1; break;
    }

}

void MainWindow::showEvent(QShowEvent *event) {

    qDebug() << "";
    qDebug() << "|========================|";
    qDebug() << "|  Has abierto el juego  |";
    qDebug() << "|========================|";
    qDebug() << "";

}

void MainWindow::closeEvent(QCloseEvent *event) {

    qDebug() << "";
    qDebug() << "|========================|";
    qDebug() << "|  Has cerrado el juego  |";
    qDebug() << "|========================|";
    qDebug() << "";

    event->accept();
}


bool MainWindow::crearBolaJson(QJsonValue &elemento) {

    if ( !elemento.isObject() ) {
        qDebug() << "ERROR! No hay objeto en Array de bolas";
        return false;
    }

    QJsonObject objetoBola = elemento.toObject();

    if ( !objetoBola.contains("posX") ) {
        qDebug() << "ERROR! La Bola no tiene PosX";
        return false;
    }

    QJsonValue valorPosX = objetoBola["posX"];
    if ( !valorPosX.isDouble() ) {
        qDebug() << "ERROR! posX no es un número";
        return false;
    }

    double posX = valorPosX.toDouble();

    if ( !objetoBola.contains("posY") ) {
        qDebug() << "ERROR! La Bola no tiene posY";
        return false;
    }

    QJsonValue valorPosY = objetoBola["posY"];
    if ( !valorPosY.isDouble() ) {
        qDebug() << "ERROR! posY no es un número";
        return false;
    }

    double posY = valorPosY.toDouble();

    if ( !objetoBola.contains("velX") ) {
        qDebug() << "ERROR! La Bola no tiene velX";
        return false;
    }

    QJsonValue valorVelX = objetoBola["velX"];
    if ( !valorVelX.isDouble() ) {
        qDebug() << "ERROR! velX no es un número";
        return false;
    }

    double velX = valorVelX.toDouble();

    if ( !objetoBola.contains("velY") ) {
        qDebug() << "ERROR! La Bola no tiene velY";
        return false;
    }

    QJsonValue valorVelY = objetoBola["velY"];
    if ( !valorVelY.isDouble() ) {
        qDebug() << "ERROR! velY no es un número";
        return false;
    }

    double velY = valorVelY.toDouble();

    if ( !objetoBola.contains("nombre") ) {
        qDebug() << "ERROR! La Bola no tiene nombre";
        return false;
    }

    QJsonValue valorNombre = objetoBola["nombre"];
    if ( !valorNombre.isString() ) {
        qDebug() << "ERROR! nombre no es un String";
        return false;
    }

    QString nombre = valorNombre.toString();

    int rojo, verde, azul;
    if ( !objetoBola.contains("color") ) {
        qDebug() << "ERROR! La Bola no tiene color";
        return false;
    }

    QJsonValue valorColores = objetoBola["color"];
    if ( !valorColores.isArray() ) {
        qDebug() << "ERROR! color no está bien";
        return false;
    }

    QJsonArray arrayColores = valorColores.toArray();
    rojo = arrayColores[0].toDouble();
    verde = arrayColores[1].toDouble();
    azul = arrayColores[2].toDouble();

    Bola *nuevaBola = new Bola(posX, posY, velX, velY);
    nuevaBola->nombre = nombre;
    nuevaBola->color = QColor(rojo, verde, azul);

    bolas.append(nuevaBola);

    return true;

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
                if ( bolas[i]->choca(bolas[j]) ) {
                    bolas.at(i)->vidas--;
                    bolas.at(j)->vidas--;

                }
        }
    }

    if ( bolaJugador ) {
        bolaJugador->mover(anchuraV, alturaV, alturaMenuBar);
        for (int i = 0; i < bolas.size(); i++) {
            if ( bolaJugador->choca(bolas[i]) ) {
                bolas[i]->vidas--;
                bolaJugador->vidas--;
            }
        }
    }

    for (int i = 0; i < bolas.length() && bolasDesaparecen; i++) {
        if ( bolas.at(i)->vidas <= 0 ) {
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

    if ( dInformacion == NULL )
        dInformacion = new DInformacion(width(), height(), bolas.size());

    dInformacion->show();

}

void MainWindow::slotDInfoBolas() {

    if ( dInfoBolas == NULL )
        dInfoBolas = new DInfoBolas(&bolas, &bolaJugador);

    dInfoBolas->show();

}

void MainWindow::slotDTablaBolas() {

    if ( dTablaBolas == NULL )
        dTablaBolas = new DTablaBolas(&bolas, &bolaJugador);

    dTablaBolas->show();

}

void MainWindow::slotDTablaRebotes() {

    if ( dTablaRebotes == NULL )
        dTablaRebotes = new DTablaRebotes(&bolas, &bolaJugador);

    dTablaRebotes->show();

}

void MainWindow::slotDControlBolas() {

    if ( dControlBolas == NULL )
        dControlBolas = new DControlBolas(&bolas);

    dControlBolas->show();

}

void MainWindow::slotGuardarPartida() {

    QJsonObject objectoPrincipal;

    QJsonArray arrayBolas;
    for (int i = 0; i < bolas.size(); i++) {
        QJsonObject objetoBola;

        QJsonArray colorsBola;
        colorsBola.append(bolas.at(i)->color.red());
        colorsBola.append(bolas.at(i)->color.green());
        colorsBola.append(bolas.at(i)->color.blue());
        objetoBola["color"] = colorsBola;

        objetoBola["nombre"] = bolas.at(i)->nombre;
        objetoBola["posX"] = bolas.at(i)->posX;
        objetoBola["posY"] = bolas.at(i)->posY;
        objetoBola["velX"] = bolas.at(i)->velX;
        objetoBola["velY"] = bolas.at(i)->velY;

        arrayBolas.append(objetoBola);
    }

    objectoPrincipal["bolas"] = arrayBolas;

    QJsonDocument documento(objectoPrincipal);

    QFile saveFile(QStringLiteral("partida.json"));
    saveFile.open(QIODevice::WriteOnly);

    saveFile.write(documento.toJson());

    qDebug() << "";
    qDebug() << "|===========================|";
    qDebug() << "|  Has guardado la Partida  |";
    qDebug() << "|===========================|";
    qDebug() << "";

}

void MainWindow::slotCargarPartida() {

    QFile loadFile(QStringLiteral("partida.json"));
    if ( !loadFile.open(QIODevice::ReadOnly) )
        return;

    for (int i = 0; i <  bolas.size(); i++)
        delete bolas[i];

    bolas.clear();

    QByteArray datosBrutos = loadFile.readAll();
    QJsonDocument documento(QJsonDocument::fromJson(datosBrutos));

    QJsonObject objectoPrincipal = documento.object();

    QStringList listaClaves = objectoPrincipal.keys();

    if ( !objectoPrincipal.contains("bolas") ) {
        qDebug() << "Error: No hay bolas";
        return;
    }
    QJsonValue valorBolas = objectoPrincipal["bolas"];

    if ( !valorBolas.isArray() ) {
        qDebug() << "Error: las bolas no son un array";
        return;
    }
    QJsonArray arrayBolas = valorBolas.toArray();

    for (int i = 0; i < arrayBolas.size(); i++) {
        QJsonValue elemento = arrayBolas [i];
        if ( !crearBolaJson(elemento) ) {
            qDebug() << "ERROR! No se pudo crear la Bola " << i;
            return;
        }
    }

    qDebug() << "";
    qDebug() << "|==========================|";
    qDebug() << "|  Has cargado la Partida  |";
    qDebug() << "|==========================|";
    qDebug() << "";

}
