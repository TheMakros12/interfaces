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
    QMenu *menuArchivo = barraMenu->addMenu("Partida");

    menuArchivo->addAction(actionDListaBolas);
    menuArchivo->addAction(actionDTablaBolas);
    menuArchivo->addAction(actionDTablaRebotes);
    menuArchivo->addAction(actionGuardarPartida);
    menuArchivo->addAction(actionCargarPartida);
    menuArchivo->addAction(actionSalir);

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

void VentanaPrincipal::slotGuardarPartida() {

    QJsonObject objectoPrincipal;

    objectoPrincipal["nombre"] = QString("marcos");
    objectoPrincipal["edad"] = 23;
    objectoPrincipal["pausado"] = false;

    QJsonArray arrayVersiones;
    arrayVersiones.append(3);
    arrayVersiones.append(2.3);
    arrayVersiones.append(QString("beta"));

    objectoPrincipal["version"] = arrayVersiones;

    QJsonObject objetoJugador;

    QJsonArray coloresBola;
    coloresBola.append(bolas.at(0)->color.red());
    coloresBola.append(bolas.at(0)->color.green());
    coloresBola.append(bolas.at(0)->color.blue());
    objetoJugador["color"] = coloresBola;

    objetoJugador["posX"] = bolas.at(0)->posX;
    objetoJugador["posY"] = bolas.at(0)->posY;

    objectoPrincipal["bolaJugador"] = objetoJugador;

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

        arrayBolas.append(objetoBola);
    }

    objectoPrincipal["bolas"] = arrayBolas;

    QJsonDocument documento(objectoPrincipal);

    QFile saveFile(QStringLiteral("partida.json"));
    saveFile.open(QIODevice::WriteOnly);

    saveFile.write(documento.toJson());

}

void VentanaPrincipal::slotCargarPartida() {

    qDebug() << "Cargar Partida" << endl;

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
    qDebug() << listaClaves;

    if (listaClaves.contains("nombre")) {
        QJsonValue valorNombre = objectoPrincipal["nombre"];
        QString nombreJugador;
        if (valorNombre.isString())
            nombreJugador = valorNombre.toString();

    qDebug() << "el nombre del jugador es: " << nombreJugador;
    }

    if (!objectoPrincipal.contains("nombre"))
        qDebug() << "error, el fichero no contiene nombre";

    if (objectoPrincipal.contains("bolaJugador")) {
        QJsonValue valorJugador = objectoPrincipal["bolaJugador"];
        if (valorJugador.isObject()) {
            QJsonObject objetoJugador = valorJugador.toObject();

        qDebug() << "============ OBJETO JUGADOR ============";
        qDebug() << objetoJugador;
        }
    }

    if (objectoPrincipal.contains("bolas")) {
        QJsonValue valorBolas = objectoPrincipal["bolas"];
        if (valorBolas.isArray()) {
            QJsonArray arrayInfoBolas = valorBolas.toArray();
            for (int i = 0; i < arrayInfoBolas.size(); i++) {
                Bola *nuevaBola;
                QJsonValue valorElemento = arrayInfoBolas[i];
                if (valorElemento.isObject()) {
                    QJsonObject objetoBola = valorElemento.toObject();
                    if (objetoBola.contains("nombre"))
                        nuevaBola->nombre = objetoBola["nombre"].toString();
//                    ponColor(nuevaBola, objetoBola["colores"])

                bolas.append(nuevaBola);
                }
            }
        }
    }

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
