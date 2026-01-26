#ifndef _VENTANAPRINCIPAL_
#define _VENTANAPRINCIPAL_

#include <QMainWindow>
#include <QPaintEvent>
#include <QVector>
#include <QMenu>
#include <QAction>
#include <QMouseEvent>
#include <QMenuBar>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>


#include "bola.h"
#include "dlistabolas.h"
#include "dtablabolas.h"
#include "dtablarebotes.h"
#include "ddetallebola.h"
#include "dconfiguracionbolas.h"
#include "dposicionbolas.h"
#include "dseleccionapellidos.h"
#include "dtablaapellidos.h"




class VentanaPrincipal : public QMainWindow {
Q_OBJECT

public:

	
    static bool bolasDesaparecen ;
    VentanaPrincipal(QWidget *parent =NULL);

    float xAnterior,yAnterior;

 void paintEvent(QPaintEvent *event);

    DListaBolas *dListaBolas;
    DTablaBolas *dTablaBolas;
    DTablaRebotes *dTablaRebotes;
    DDetalleBola * dDetalleBola;
    DConfiguracionBolas * dConfiguracionBolas;
    DPosicionBolas * dPosicionBolas;
    DSeleccionApellidos *dSeleccionApellidos;
    DTablaApellidos *dTablaApellidos;


    float clickXAnterior, clickYAnterior;
    bool clicado;

    QVector<Bola * > bolas;
    Bola bola;

    QStringList todosApellidos;
    QStringList apellidosUsados;

    QAction *accionDListaBolas;
    QAction *accionDTablaBolas;
    QAction *accionDTablaRebotes;
    QAction *accionGuardarPartida;
    QAction *accionCargarPartida;
    QAction *accionDDetalleBola;
    QAction *accionDConfiguracionBolas;
    QAction *accionDPosicionBolas;
    QAction *accionDSeleccionApellidos;
    QAction *accionDTablaApellidos;


    void inicializarBolas();

    void crearActions();
    void crearMenus();

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent * event);

public slots:
    void slotTemporizador();
    void slotDListaBolas();
    void slotDTablaBolas();
    void slotDTablaRebotes();
    void slotGuardarPartida();
    void slotCargarPartida();
    void slotDDetalleBola();
    void slotDConfiguracionBolas();
    void slotDPosicionBolas();
    void slotDSeleccionApellidos();
    void slotDTablaApellidos();
 

};




#endif
