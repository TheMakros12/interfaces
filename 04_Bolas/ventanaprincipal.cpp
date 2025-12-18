#include "ventanaprincipal.h"

#include <QPainter>
#include <QTimer>

bool VentanaPrincipal::bolasDesaparecen = true;

VentanaPrincipal::VentanaPrincipal(QWidget *parent): QMainWindow(parent) {


    temporizador = new QTimer();
    temporizador->setInterval(10);
    temporizador->setSingleShot(false);

    connect(temporizador, SIGNAL(timeout()),
            this, SLOT(slotTemporizador()));

    temporizador->start();

    bola.posX = 500;
    bola.posY = 200;

    bola.velX = 0.4;
    bola.velY = 2;

    resize(800,600);

    dListaBolas = NULL;
    dTablaBolas = NULL;
    dTablaRebotes = NULL;
    crearActions();
    crearMenus();

    inicializarBolas();

}

void VentanaPrincipal::crearActions() {

    actionDListaBolas = new QAction("Lista Bolas", this);
    connect(actionDListaBolas, SIGNAL(triggered()),
            this, SLOT(slotDListaBolas()));

    actionDTablaBolas = new QAction("Tabla Bolas", this);
    connect(actionDTablaBolas, SIGNAL(triggered()),
            this, SLOT(slotDTablaBolas()));

    actionDTablaRebotes = new QAction("Tabla Rebotes", this);
    connect(actionDTablaRebotes, SIGNAL(triggered()),
            this, SLOT(slotDTablaRebotes()));

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

}

void VentanaPrincipal::crearMenus() {

    QMenuBar *barraMenu = this->menuBar();
    QMenu *menuDialogos = barraMenu->addMenu("Diálogos");
    QMenu *menuPartida = barraMenu->addMenu("Partida");

    menuDialogos->addAction(actionDListaBolas);
    menuDialogos->addAction(actionDTablaBolas);
    menuDialogos->addAction(actionDTablaRebotes);
    menuDialogos->addAction(actionSalir);
    menuPartida->addAction(actionGuardarPartida);
    menuPartida->addAction(actionCargarPartida);

}

void VentanaPrincipal::inicializarBolas() {

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

        nueva->color = QColor(rand()%255, rand()%255, rand()%255);
        nueva->nombre = nombres.at(i % nombres.size());
        nueva->esImagen = false;

#define IMAGEN
#ifdef IMAGEN
        //nueva->esImagen = true;
        QImage imagen = QImage("./img/smiley_PNG180.png");
        imagen = imagen.scaled(Bola::diametro,Bola::diametro);
        nueva->img = imagen;
#endif

        bolas.append(nueva);
    }

}

void VentanaPrincipal::paintEvent(QPaintEvent *){
    QPainter pintor(this);

    //pintor.fillRect(20,20,400,anchura,"red");

    for (int i= 0 ; i < bolas.length(); i++)
        bolas.at(i)->pintar(pintor);

}

void VentanaPrincipal::closeEvent(QCloseEvent *event) {

    qDebug() << "=======================";
    qDebug() << "Has cerrado el programa";
    qDebug() << "=======================";

    event->accept();
}

void VentanaPrincipal::slotGuardarPartida() {

    QJsonObject objectoPrincipal;

    QJsonArray arrayVersiones;
    arrayVersiones.append(3);
    arrayVersiones.append(2.3);
    arrayVersiones.append(QString("beta"));

    objectoPrincipal["version"] = arrayVersiones;

    /*QJsonObject objetoJugador;

    QJsonArray coloresBola;
    coloresBola.append(bolas.at(0)->color.red());
    coloresBola.append(bolas.at(0)->color.green());
    coloresBola.append(bolas.at(0)->color.blue());
    objetoJugador["color"] = coloresBola;

    objetoJugador["posX"] = bolas.at(0)->posX;
    objetoJugador["posY"] = bolas.at(0)->posY;

    objectoPrincipal["bolaJugador"] = objetoJugador;*/

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

    qDebug() << "=======================";
    qDebug() << "Has guardado la Partida";
    qDebug() << "=======================";

}

void VentanaPrincipal::slotCargarPartida() {

    QFile loadFile(QStringLiteral("partida.json"));
    if (!loadFile.open(QIODevice::ReadOnly))
        return;

    for (int i = 0; i <  bolas.size(); i++)
        delete bolas[i];

    bolas.clear();

    QByteArray datosBrutos = loadFile.readAll();
    QJsonDocument documento(QJsonDocument::fromJson(datosBrutos));

    QJsonObject objectoPrincipal = documento.object();

    QStringList listaClaves = objectoPrincipal.keys();

    if (!objectoPrincipal.contains("bolas")) {
        qDebug() << "Error: No hay bolas";
        return;
    }
    QJsonValue valorBolas = objectoPrincipal["bolas"];

    if (!valorBolas.isArray()) {
        qDebug() << "Error: las bolas no son un array";
        return;
    }
    QJsonArray arrayBolas = valorBolas.toArray();

    for (int i = 0; i < arrayBolas.size(); i++) {
        QJsonValue elemento = arrayBolas [i];
        if (!crearBolaJson(elemento)) {
            qDebug() << "ERROR! No se pudo crear la Bola " << i;
            return;
        }
    } /*for (int i = 0; i < arrayBolas.size(); i++)*/


    qDebug() << "======================";
    qDebug() << "Has cargado la Partida";
    qDebug() << "======================";

}

bool VentanaPrincipal::crearBolaJson(QJsonValue &elemento) {

    if (!elemento.isObject()) {
        qDebug() << "ERROR! No hay objeto en Array de bolas";
        return false;
    } /* if (!elemento.isObject()) */
    QJsonObject objetoBola = elemento.toObject();

    if (!objetoBola.contains("posX")) {
        qDebug() << "ERROR! La Bola no tiene PosX";
        return false;
    } /* if (!objetoBola.contains("posX")) */
    QJsonValue valorPosX = objetoBola["posX"];
    if (!valorPosX.isDouble()) {
        qDebug() << "ERROR! posX no es un número";
        return false;
    } /* if (!valorPosX.isDouble()) */
    double posX = valorPosX.toDouble();

    if (!objetoBola.contains("posY")) {
        qDebug() << "ERROR! La Bola no tiene posY";
        return false;
    } /* if (!objetoBola.contains("posY")) */
    QJsonValue valorPosY = objetoBola["posY"];
    if (!valorPosY.isDouble()) {
        qDebug() << "ERROR! posY no es un número";
        return false;
    } /* if (!valorPosY.isDouble()) */
    double posY = valorPosY.toDouble();

    if (!objetoBola.contains("velX")) {
        qDebug() << "ERROR! La Bola no tiene velX";
        return false;
    } /* if (!objetoBola.contains("velX")) */
    QJsonValue valorVelX = objetoBola["velX"];
    if (!valorVelX.isDouble()) {
        qDebug() << "ERROR! velX no es un número";
        return false;
    } /* if (!valorVelX.isDouble()) */
    double velX = valorVelX.toDouble();

    if (!objetoBola.contains("velY")) {
        qDebug() << "ERROR! La Bola no tiene velY";
        return false;
    } /* if (!objetoBola.contains("velY")) */
    QJsonValue valorVelY = objetoBola["velY"];
    if (!valorVelY.isDouble()) {
        qDebug() << "ERROR! velY no es un número";
        return false;
    } /* if (!valorVelY.isDouble()) */
    double velY = valorVelY.toDouble();

    if (!objetoBola.contains("nombre")) {
        qDebug() << "ERROR! La Bola no tiene nombre";
        return false;
    } /* if (!objetoBola.contains("nombre")) */
    QJsonValue valorNombre = objetoBola["nombre"];
    if (!valorNombre.isString()) {
        qDebug() << "ERROR! nombre no es un String";
        return false;
    } /* if (!valorNombre.isString()) */
    QString nombre = valorNombre.toString();

    int rojo, verde, azul;
    if (!objetoBola.contains("color")) {
        qDebug() << "ERROR! La Bola no tiene color";
        return false;
    } /* if (!objetoBola.contains("color")) */
    QJsonValue valorColores = objetoBola["color"];
    if (!valorColores.isArray()) {
        qDebug() << "ERROR! color no está bien";
        return false;
    } /* if (!valorColores.isArray()) */
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

void VentanaPrincipal::slotTemporizador() {

    for (int i = 0; i < bolas.size(); i++) {
        bolas.at(i)->mover(width(), height());
    }

    for (int i = 0; i < bolas.length(); i++)
        for (int j = 0; j < bolas.length(); j++)
            if (bolas.at(i)->choca(bolas.at(j))) {
                bolas.at(i)->vidas--;
                bolas.at(j)->vidas--;
            }

    for (int i = 0; i < bolas.length() && bolasDesaparecen; i++) {
        if (bolas.at(i)->vidas <= 0) {
            delete bolas.at(i);
            bolas.removeAt(i);
            break;
        }
    }

    repaint();
}

void VentanaPrincipal::slotDListaBolas() {

    if (dListaBolas == NULL) {
        dListaBolas = new DListaBolas(&bolas);
    }
    dListaBolas->show();

}

void VentanaPrincipal::slotDTablaBolas() {

    if (dTablaBolas == NULL)
        dTablaBolas = new DTablaBolas(&bolas);

    dTablaBolas->show();

}

void VentanaPrincipal::slotDTablaRebotes() {

    if (dTablaRebotes == NULL)
        dTablaRebotes = new DTablaRebotes(&bolas);

    dTablaRebotes->show();

}
