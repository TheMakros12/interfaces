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

    actionSalir = new QAction("Salir", this);
	actionSalir->setShortcut(QKeySequence::Quit);
    connect(actionSalir, SIGNAL(triggered()),
			this, SLOT(close()));

}

void VentanaPrincipal::crearMenus() {

    QMenuBar *barraMenu = this->menuBar();
    QMenu *menuArchivo = barraMenu->addMenu("Archivo");

    menuArchivo->addAction(actionDListaBolas);
    menuArchivo->addAction(actionDTablaBolas);
    menuArchivo->addAction(actionDTablaRebotes);
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
