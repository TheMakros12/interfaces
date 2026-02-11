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

    posIniX = 0;
    posIniY = 0;
    actuacionJugador = 0.1;

    resize(800,600);

    anchuraV = width();
    alturaV = height();
    alturaMenuBar = menuBar()->height();

    dInformacion = NULL;
    dListaBolas = NULL;
    dTablaBolas = NULL;
    dTablaRebotes = NULL;
    dDetalleBola = NULL;
    dConfiguracionBola = NULL;
    dPosicionBola = NULL;

    crearActions();
    crearMenus();
    inicializarBolas();

    setAcceptDrops(true);

}

void VentanaPrincipal::crearActions() {

    /*Aquí creamos todas las QAction para los diferentes menús*/

    actionDInformacion = new QAction("Información", this);
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

    actionDListaBolas = new QAction("Lista de las Bolas", this);
    connect(actionDListaBolas, SIGNAL(triggered()),
            this, SLOT(slotDListaBolas()));

    actionDTablaBolas = new QAction("Tabla de las Bolas", this);
    connect(actionDTablaBolas, SIGNAL(triggered()),
            this, SLOT(slotDTablaBolas()));

    actionDTablaRebotes = new QAction("Tabla de los Rebotes", this);
    connect(actionDTablaRebotes, SIGNAL(triggered()),
            this, SLOT(slotDTablaRebotes()));

    actionDDetalleBola = new QAction("Detalle de la Bola", this);
    connect(actionDDetalleBola, SIGNAL(triggered()),
			this, SLOT(slotDDetalleBola()));

    actionDConfiguracionBola = new QAction("Configuracion de la Bola", this);
    connect(actionDConfiguracionBola, SIGNAL(triggered()),
			this, SLOT(slotDDConfiguracionBola()));

    actionDPosicionBola = new QAction("Posición de la Bola", this);
    connect(actionDPosicionBola, SIGNAL(triggered()),
			this, SLOT(slotDPosicionBola()));

}

void VentanaPrincipal::crearMenus() {

    /*Creamos un QMenuBar y luego los diferentes menús que vamos a utilizar*/

    QMenuBar *barraMenu = this->menuBar();

    QMenu *menuPartida = barraMenu->addMenu("Partida");
    menuPartida->addAction(actionDInformacion);
    menuPartida->addAction(actionGuardarPartida);
    menuPartida->addAction(actionCargarPartida);
    menuPartida->addAction(actionSalir);

    QMenu *menuDialogos = barraMenu->addMenu("Diálogos");
    menuDialogos->addAction(actionDListaBolas);
    menuDialogos->addAction(actionDTablaBolas);
    menuDialogos->addAction(actionDTablaRebotes);
    menuDialogos->addAction(actionDDetalleBola);
    menuDialogos->addAction(actionDConfiguracionBola);
    menuDialogos->addAction(actionDPosicionBola);

}

void VentanaPrincipal::inicializarBolas() {

    bolaJugador = new Bola(100, 100, 0, 0);
    bolaJugador->nombre = "Jugador";
    bolaJugador->color = QColor("black");
    bolaJugador->esImagen = false;

    /* Este método es el encargado de la creación del QVector<Bola*> con todos sus atributos iniciales */

    QStringList nombres = {"marcos", "lucia", "juan","david","alex","paula","aroa","alba","diego","jose","perico","andres"
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
        nueva->esImagen = true;
        QImage imagen = QImage("./img/smiley_PNG180.png");
        imagen = imagen.scaled(Bola::diametro,Bola::diametro);
        nueva->img = imagen;
#endif

        nueva->anchuraJuego = anchura;
        nueva->alturaJuego = altura;

        bolas.append(nueva);
    }

}

void VentanaPrincipal::showEvent(QShowEvent *event) {

    qDebug() << "";
    qDebug() << "|========================|";
    qDebug() << "|  Has abierto el juego  |";
    qDebug() << "|========================|";
    qDebug() << "";

}

void VentanaPrincipal::paintEvent(QPaintEvent *){

    /* Aquí llamamos al método que tiene la clase Bola, para poder pintarlas */

    QPainter pintor(this);

    bolaJugador->pintar(pintor);

    for (int i= 0 ; i < bolas.length(); i++)
        bolas.at(i)->pintar(pintor);

}

bool VentanaPrincipal::crearBolaJson(QJsonValue &elemento) {

    /* Aquí devolvemos true/false dependiendo de si se ha podido crear un Elemento tipo Json con las Bolas del programa */

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

    if (!objetoBola.contains("velY")) {
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

void VentanaPrincipal::closeEvent(QCloseEvent *event) {

    /* Simplemente sobreescribimos este métedo par que muestre este mensaje por la terminal */

    qDebug() << "";
    qDebug() << "|===========================|";
    qDebug() << "|  Has cerrado el programa  |";
    qDebug() << "|===========================|";
    qDebug() << "";

    event->accept();
}

void VentanaPrincipal::mousePressEvent(QMouseEvent *event) {

    float nuevaPosX = event->x();
    float nuevaPosY = event->y();
    float velX = 0;
    float velY = 0;

    nuevaBola = new Bola();
    nuevaBola->posX = nuevaPosX;
    nuevaBola->posY = nuevaPosY;
    nuevaBola->color = QColor(rand() % 255, rand() % 255, rand() % 255);
    nuevaBola->nombre = "bola " + QString::number(bolas.size());
    nuevaBola->esImagen = false;
    nuevaBola->anchuraJuego = anchuraV;
    nuevaBola->alturaJuego = alturaV;

}

void VentanaPrincipal::mouseReleaseEvent(QMouseEvent * event) {

    float velX = (event->x() - nuevaBola->posX) / 100;
    float velY = (event->y() - nuevaBola->posY) / 100;

    nuevaBola->velX = velX;
    nuevaBola->velY = velY;

    bolas.append(nuevaBola);

    repaint();

}

void VentanaPrincipal::dragEnterEvent(QDragEnterEvent *event) {
    // EL ratón ha entrado en el área de la ventana con algo que está arrastrandp

    event->acceptProposedAction();

    posIniX = event->pos().x();
    posIniY = event->pos().y();

}

void VentanaPrincipal::dropEvent(QDropEvent *event) {

    float posX = event->pos().x();
    float posY = event->pos().y();

    float velX = (posIniX - posX) / 100;
    float velY = (posIniY - posY) / 100;

    if ( ! event->mimeData()->hasText() ) {
        qDebug() << "Lo arrastrado no tiene texto";
        return;
    }

    QString rutaArchivo = event->mimeData()->urls().first().path();

    Bola *newBola = new Bola(posX, posY, velX, velY);

#define IMAGEN_2
#ifdef IMAGEN_2
        QImage img = QImage(rutaArchivo);
        img = img.scaled(Bola::diametro,Bola::diametro);
        newBola->img = img;
#endif

        newBola->anchuraJuego = anchuraV;
        newBola->alturaJuego = alturaV;

        bolas.append(newBola);

}

void VentanaPrincipal::keyPressEvent(QKeyEvent *event) {

    if ( !bolaJugador )
        return;

    switch ( event->key() ) {
        case Qt::Key_Up: bolaJugador->velY = bolaJugador->velY - actuacionJugador; break;
        case Qt::Key_Down: bolaJugador->velY = bolaJugador->velY + actuacionJugador; break;
        case Qt::Key_Right: bolaJugador->velX = bolaJugador->velX + actuacionJugador; break;
        case Qt::Key_Left: bolaJugador->velX = bolaJugador->velX - actuacionJugador ; break;
    }

}

void VentanaPrincipal::slotTemporizador() {

    /* Método que se va a ejectutar repetidamento por el QTimer. Aquí gestionamos el movimiento de las Bolas, los colisiones de las mismas      y la gestión de las vidas. */

    bolaJugador->mover(anchuraV, alturaV, alturaMenuBar);

    for (int i = 0; i < bolas.size(); i++) {
        bolas.at(i)->mover(anchuraV, alturaV, alturaMenuBar);
    }

    for (int i = 0; i < bolas.length(); i++)
        for (int j = 0; j < bolas.length(); j++)
            if ( bolas.at(i)->choca(bolas.at(j)) ) {
                bolas.at(i)->vidas--;
                bolas.at(j)->vidas--;
            }

    for (int i = 0; i < bolas.length() && bolasDesaparecen; i++) {
        if ( bolas.at(i)->vidas <= 0 ) {
            delete bolas.at(i);
            bolas.removeAt(i);
            break;
        }
    }

    repaint();
}

/* A partir de aquí declaramos los diferentes SLOTS para poder ejecutar todos los Diálogos que hayamos implementado */

void VentanaPrincipal::slotDInformacion() {

    if (dInformacion == NULL )
        dInformacion = new DInformacion(width(), height(), bolas.size());

    dInformacion->show();

}

void VentanaPrincipal::slotDListaBolas() {

    if ( dListaBolas == NULL ) {
        dListaBolas = new DListaBolas(&bolas);
    }
    dListaBolas->show();

}

void VentanaPrincipal::slotDTablaBolas() {

    if ( dTablaBolas == NULL )
        dTablaBolas = new DTablaBolas(&bolas);

    dTablaBolas->show();

}

void VentanaPrincipal::slotDTablaRebotes() {

    if ( dTablaRebotes == NULL )
        dTablaRebotes = new DTablaRebotes(&bolas);

    dTablaRebotes->show();

}

void VentanaPrincipal::slotDDetalleBola() {

    if ( dDetalleBola == NULL )
        dDetalleBola = new DDetalleBola(&bolas);

    dDetalleBola->show();

}

void VentanaPrincipal::slotDDConfiguracionBola() {

    if ( dConfiguracionBola == NULL )
        dConfiguracionBola = new DConfiguracionBola(&bolas);

    dConfiguracionBola->show();

}

void VentanaPrincipal::slotDPosicionBola() {

    if (dPosicionBola == NULL)
        dPosicionBola = new DPosicionBola(&bolas);

    dPosicionBola->show();

}

void VentanaPrincipal::slotGuardarPartida() {

    /* En este método guardamos todos los datos que queremos en un documento .json. Este mismo se guarda en la propia carpeta del programa */

    QJsonObject objectoPrincipal;

    QJsonArray arrayVersiones;
    arrayVersiones.append(3);
    arrayVersiones.append(2.3);
    arrayVersiones.append(QString("beta"));

    objectoPrincipal["version"] = arrayVersiones;

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

void VentanaPrincipal::slotCargarPartida() {

    /* Cargamos una partida a partir de un .json que tengamos en la misma carpeta que el proyecto */

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
