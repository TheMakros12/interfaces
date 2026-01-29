#include "ventanaprincipal.h"
#include <QPainter>
#include <math.h>
#include <QDebug>
#include <QTimer>
#include <QImage>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QJsonArray>
#include <QByteArray>
#include <QJsonValue>

bool VentanaPrincipal::bolasDesaparecen = true;

VentanaPrincipal::VentanaPrincipal(QWidget * parent ) : QMainWindow(parent){

    QTimer *temporizador = new QTimer();
    temporizador->setInterval(10);
    temporizador->setSingleShot(false);

    connect(temporizador,SIGNAL(timeout()),
            this,SLOT(slotTemporizador()));

    temporizador->start();

    bola.posX = 500;
    bola.posY = 200;

    bola.velX = 0.4;
    bola.velY = 2;

    clicado = false;
    resize(800,600);



    qDebug() << "las bolas tienen un diámetro de " << Bola::diametro;

    dListaBolas = NULL; // me quedo tranquil
    dTablaBolas = NULL;
    dTablaRebotes = NULL;
    dDetalleBola = NULL;
    dConfiguracionBolas = NULL;
    dPosicionBolas = NULL;
    dSeleccionApellidos = NULL;
    dTablaApellidos = NULL;

    crearActions();
    crearMenus();

    inicializarBolas();

    setAcceptDrops(true);

}

void VentanaPrincipal::crearActions(){

    accionDListaBolas = new QAction("Ver bolas",this);
    connect(accionDListaBolas,&QAction::triggered,
            this,&VentanaPrincipal::slotDListaBolas);
            
            
   accionDTablaBolas = new QAction("Ver Tabla",this);
    connect(accionDTablaBolas,&QAction::triggered,
            this,&VentanaPrincipal::slotDTablaBolas);

    accionDTablaRebotes = new QAction("Ver Rebotes",this);
    connect(accionDTablaRebotes,&QAction::triggered,
            [this](){
                if (dTablaRebotes == NULL)
                    dTablaRebotes = new DTablaRebotes(&bolas);
                dTablaRebotes->show();
            });

     accionGuardarPartida = new QAction("Guardar Partida",this);
    connect(accionGuardarPartida,&QAction::triggered,
            this,&VentanaPrincipal::slotGuardarPartida);
    accionCargarPartida = new QAction("Cargar Partida",this);
    connect(accionCargarPartida,&QAction::triggered,
            this,&VentanaPrincipal::slotCargarPartida);
    /* connect(accionDTablaRebotes,SIGNAL(triggered()),
                this,SLOT(slotDTablaRebotes()));*/

    accionDDetalleBola = new QAction("Ver Detalle de cada Bola",this);
    connect(accionDDetalleBola,SIGNAL(triggered()),
            this,SLOT(slotDDetalleBola()));

     accionDConfiguracionBolas = new QAction("Configuracion de Bolas",this);
    connect(accionDConfiguracionBolas,SIGNAL(triggered()),
            this,SLOT(slotDConfiguracionBolas()));

    accionDPosicionBolas = new QAction("Posicion de las Bolas",this);
    connect(accionDPosicionBolas,SIGNAL(triggered()),
            this,SLOT(slotDPosicionBolas()));

    accionDSeleccionApellidos = new QAction("Seleccionar Apellidos",this);
    connect(accionDSeleccionApellidos,SIGNAL(triggered()),
            this,SLOT(slotDSeleccionApellidos()));

    accionDTablaApellidos = new QAction("Tabla Apellidos",this);
    connect(accionDTablaApellidos,SIGNAL(triggered()),
            this,SLOT(slotDTablaApellidos()));
            
             


}

void VentanaPrincipal::crearMenus(){

    QMenuBar * barra = this->menuBar();

    QMenu *menuArchivo = barra->addMenu("archivo");
    menuArchivo->addAction(accionDListaBolas);
    menuArchivo->addAction(accionDTablaBolas);
    menuArchivo->addAction(accionDTablaRebotes);
    menuArchivo->addAction(accionGuardarPartida);

    QMenu * menuConfiguracion = barra->addMenu("Configuraciones");

    menuConfiguracion->addAction(accionCargarPartida);
    menuConfiguracion->addAction(accionDDetalleBola);
    menuConfiguracion->addAction(accionDConfiguracionBolas);
    menuConfiguracion->addAction(accionDPosicionBolas);

    QMenu * menuExamen = barra->addMenu("Exámen");
    menuExamen->addAction(accionDSeleccionApellidos);
    menuExamen->addAction(accionDTablaApellidos);

}


void VentanaPrincipal::inicializarBolas(){

    QStringList nombres = {"Juan","perico","andres","Jordi","Denis","Daniel","Jose",
        "Pedro,Pedro,Pedro","Hanjel", " Donald", "Ampersand",
        "Avelino","Mercedes","Pepica","Tere","Malieta","Enrique"
    };
    
    QStringList apellidos = {"García","Fernández","González","Rodríguez","López","Martínez",
    "Sánchez","Pérez","Gómez","Martín","Jiménez","Ruiz","Hernández","Díaz","Moreno","Muñoz","Álvarez",
    "Romero","Alonso","Gutiérrez"};

	todosApellidos = apellidos;

    int anchura = width();
    int altura = height();

    for (int i = 0; i < 10 ; i++ ) {
        int posIniX = random() % anchura;
        int posIniY = random() % altura;

        float velX = (float)(random()%100) / 50 - 1;
        float velY = (float)(random()%100) / 50 - 1;
        Bola *nueva = new Bola(posIniX,posIniY,velX,velY);

        nueva->color = QColor(random()%255,
                              random()%255,
                              random()%255);

        nueva->nombre = nombres.at( i % nombres.size() );
        nueva->apellido_1 = apellidos.at(random() % apellidos.size());
        if (!apellidosUsados.contains(nueva->apellido_1))
            apellidosUsados.append(nueva->apellido_1);
        nueva->apellido_2 = apellidos.at(random() % apellidos.size());
        if (!apellidosUsados.contains(nueva->apellido_2))
            apellidosUsados.append(nueva->apellido_2);
        nueva->esImagen = true;
#define IMAGEN
#ifdef IMAGEN
        //nueva->esImagen = true;
       QImage imagenNueva = QImage("./imagenes/smiley_PNG180.png") ;
    imagenNueva = imagenNueva.scaled(Bola::diametro,Bola::diametro);
       nueva->imagen = imagenNueva;
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


void VentanaPrincipal::mousePressEvent(QMouseEvent *event){

    qDebug()<< "Mouse press event";
    clickXAnterior = event->x();
    clickYAnterior = event->y();

    clicado = true;


}
void VentanaPrincipal::mouseReleaseEvent(QMouseEvent *event){

    qDebug()<< "Mouse release event";


    if ( ! clicado ) return;

    float xFin = event->x() ;
    float yFin = event->y() ;

    float velX = (float)(xFin - clickXAnterior) /  300.1;
    float velY = (float)(yFin - clickYAnterior) /  300.1;

    Bola * nueva = new Bola(clickXAnterior,clickYAnterior,velX,velY);

    bolas.append(nueva);

    clicado = false;
}

void VentanaPrincipal::dragEnterEvent(QDragEnterEvent *event){
    // El puntero ha entrado en el área de la ventana con algo
    // que está arrastrando

    // tocaría mirar qué info contiene event y decidir sí o no

    event->acceptProposedAction();

    xAnterior =event->pos().x();
    yAnterior =event->pos().y();

    qDebug()<< "entrando por x=" << xAnterior << " y="<< yAnterior;

}


void VentanaPrincipal::dropEvent(QDropEvent * event){

    if ( ! event->mimeData()->hasText() ) {
        qDebug() << " Lo arrastrado no tiene texto";
        return;
    }

    QString rutaArchivo = event->mimeData()->urls().first().path();


     QImage imagen = QImage(rutaArchivo);
     if (imagen.isNull() ) {
		qDebug() << "Panico: La imagen no sirve " ;
        return;
    }


 	 Bola *nueva = new Bola();
   	 nueva->posX = event->pos().x();
   	 nueva->posY = event->pos().y();


   	 nueva->nombre = QString("lolailo");

   	 nueva->velX = (float)( xAnterior - nueva->posX ) / 1000.002;
   	 nueva->velY = (float)( yAnterior - nueva->posY ) /1000.1;
    qDebug()<< "soltando por x=" << nueva->posX <<
                " y="<< nueva->posY;

	imagen = imagen.scaled(nueva->diametro,nueva->diametro);
	 nueva->esImagen = true;

     nueva->imagen = imagen;

   	 bolas.append(nueva);


}


void VentanaPrincipal::slotTemporizador(){

    for (int i= 0 ; i < bolas.length(); i++)
        bolas.at(i)->mover(width(),height());

//    bola.mover(width(),height());

    for (int i = 0 ; i< bolas.length();i++)
        for (int j = 0; j < bolas.length(); j++)
            if ( bolas.at(i)->choca(bolas.at(j)) ) {
                bolas.at(i)->vidas-- ;
                bolas.at(j)->vidas-- ;
            }

/*
    for (int i = 0; i< bolas.length() && bolasDesaparecen; i++)
        if (bolas.at(i)->vidas <= 0 ) {
            delete bolas.at(i);
            bolas.removeAt(i);
            break;
        }
*/

    repaint();

}


void VentanaPrincipal::slotGuardarPartida(){

    QJsonObject objetoPrincipal;

    objetoPrincipal["nombre"] = QString("nacho");
    objetoPrincipal["edad"] = 52 ;
    objetoPrincipal["pausado"] = false;

    QJsonArray arrayVersiones;
    arrayVersiones.append(3) ;
    arrayVersiones.append(2.3);
    arrayVersiones.append(QString("beta"));

    objetoPrincipal["version"] = arrayVersiones;

    /* Voy con el jugador. Es un objeto completo y
     por ello me voy a crear un nuevo QJsonObject*/
    QJsonObject objetoJugador;

    /*voy metiendoi clave-valor en elobjeto creado*/
    objetoJugador["posX"] = bolas.at(0)->posX;
    objetoJugador["posY"] = bolas.at(0)->posY;

    /* para meter los colores necesito un array*/
    QJsonArray arrayColores;

    /* meto en el array, en orden */
    arrayColores.append(bolas.at(0)->color.red());
    arrayColores.append(bolas.at(0)->color.green());
    arrayColores.append(bolas.at(0)->color.blue());

    //ya esta el array completo. lo meto en el jugador
    objetoJugador["color"] = arrayColores;

    // ya está el jugador completo, lo meto en el json principal
    objetoPrincipal["bolaJugador"] = objetoJugador;


    QJsonArray arrayBolas;

    for (int i=0; i < bolas.size();i++ ) {
        QJsonObject objetoBola;

        objetoBola["nombre"] = bolas.at(i)->nombre;
        /*voy metiendoi clave-valor en elobjeto creado*/
        objetoBola["posX"] = bolas.at(i)->posX;
        objetoBola["posY"] = bolas.at(i)->posY;

        /* para meter los colores necesito un array*/
        QJsonArray arrayColoresBola;

        /* meto en el array, en orden */
        arrayColoresBola.append(bolas.at(i)->color.red());
        arrayColoresBola.append(bolas.at(i)->color.green());
        arrayColoresBola.append(bolas.at(i)->color.blue());

        //ya esta el array completo. lo meto en el jugador
        objetoBola["color"] = arrayColoresBola;

        // ya está el jugador completo, lo meto en el json principal
        arrayBolas.append(objetoBola);
    }
    objetoPrincipal["bolas"] = arrayBolas;


    QJsonDocument documento(objetoPrincipal);
    QFile saveFile(QStringLiteral("partida.json"));
   	saveFile.open(QIODevice::WriteOnly);

    saveFile.write(documento.toJson());

}


void VentanaPrincipal::slotCargarPartida() {
    qDebug() << "Cargar partida";

    QFile loadFile(QStringLiteral("partida.json"));
	if (! loadFile.open(QIODevice::ReadOnly))
		return;

	for (int i = 0; i < bolas.size(); i++)
   	 delete bolas[i];

    bolas.clear();

    QByteArray datosBrutos = loadFile.readAll();
    QJsonDocument documento(QJsonDocument::fromJson(datosBrutos));

    QJsonObject objetoPrincipal = documento.object();

    QStringList listaClaves = objetoPrincipal.keys();
    qDebug() << listaClaves;

    if (listaClaves.contains("nombre")) {
        QJsonValue valorNombre = objetoPrincipal["nombre"];
        QString nombreJugador;
        if (valorNombre.isString())
            nombreJugador = valorNombre.toString();

        qDebug()<< "el nombre del jugador es : " << nombreJugador;
    }

    if (! objetoPrincipal.contains("nombre") )
        qDebug() << "Error, el ficheor no incluye nombre";


    if (objetoPrincipal.contains("bolaJugador")){
        QJsonValue valorJugador = objetoPrincipal["bolaJugador"];
        if (valorJugador.isObject()) {
            QJsonObject objetoJugador = valorJugador.toObject();

            qDebug()<< "=========== OBJETO JUGADOR ==========";
            qDebug() << objetoJugador;
        }
    }

    if (objetoPrincipal.contains("bolas")){
        QJsonValue valorBolas = objetoPrincipal["bolas"];
        if (valorBolas.isArray()) {
            QJsonArray arrayBolas = valorBolas.toArray();
            for (int i = 0; i < arrayBolas.size();i++) {

                Bola * nuevaBola = new Bola();

                QJsonValue valorElemento = arrayBolas[i];
                if (valorElemento.isObject()) {
                    QJsonObject objetoBola = valorElemento.toObject();
                    if (objetoBola.contains("nombre"))
                        nuevaBola->nombre= objetoBola["nombre"].toString();
                        //ponColor(nuevaBola, objetoBola["colores"])



                    bolas.append(nuevaBola);




                }//if (valorElemento.isObject())
            }//for (int i = 0; i < arrayBolas.size();i++)

        }//if (valorBolas.isArray())
    }//if (objetoPrincipal.contains("bolas")){


   // qDebug() << objetoPrincipal;

}


void VentanaPrincipal::slotDListaBolas(){

    if (dListaBolas == NULL)
        dListaBolas = new DListaBolas(&bolas);


    dListaBolas->show();

}



void VentanaPrincipal::slotDTablaBolas(){

    if (dTablaBolas == NULL)
        dTablaBolas = new DTablaBolas(&bolas);


    dTablaBolas->show();

}


void VentanaPrincipal::slotDTablaRebotes(){
     if (dTablaRebotes == NULL)
                    dTablaRebotes = new DTablaRebotes(&bolas);
    dTablaRebotes->show();
}


void VentanaPrincipal::slotDDetalleBola(){
     if (dDetalleBola == NULL)
                    dDetalleBola = new DDetalleBola (&bolas);
    dDetalleBola->show();
}

void VentanaPrincipal::slotDConfiguracionBolas(){
     if (dConfiguracionBolas == NULL)
                    dConfiguracionBolas = new DConfiguracionBolas (&bolas);
    dConfiguracionBolas->show();
}


void VentanaPrincipal::slotDPosicionBolas(){
     if (dPosicionBolas == NULL)
                    dPosicionBolas = new DPosicionBolas (&bolas);
    dPosicionBolas->show();
}

void VentanaPrincipal::slotDSeleccionApellidos() {

    if (dSeleccionApellidos == NULL){
        dSeleccionApellidos = new DSeleccionApellidos(&bolas, todosApellidos);

        if ( dTablaApellidos != NULL ){
            connect(dSeleccionApellidos, SIGNAL(senyalApellidoActuzalizado()),
            dTablaApellidos, SLOT(slotCambioApellido()));

        }
    }

    dSeleccionApellidos->show();

}

void VentanaPrincipal::slotDTablaApellidos(){

    if (dTablaApellidos == NULL)
        dTablaApellidos = new DTablaApellidos(&bolas, apellidosUsados);

    if ( dSeleccionApellidos != NULL ){
            connect(dSeleccionApellidos, SIGNAL(senyalApellidoActuzalizado()),
            dTablaApellidos, SLOT(slotCambioApellido()));

        }

    dTablaApellidos->show();

}



