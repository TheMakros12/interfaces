#ifndef VENTANAPRINCIPAL_H_
#define VENTANAPRINCIPAL_H_

#include <QMainWindow>
#include <QPaintEvent>
#include <QVector>
#include <QImage>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QFile>
#include <QStringLiteral>
#include <QIODevice>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QByteArray>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QKeyEvent>
#include <QMimeData>

#include "bola.h"
#include "dinformacion.h"
#include "dlistabolas.h"
#include "dtablabolas.h"
#include "dtablarebotes.h"
#include "ddetallebola.h"
#include "dconfiguracionbola.h"
#include "dposicionbola.h"

class VentanaPrincipal : public QMainWindow {
Q_OBJECT

public:
    VentanaPrincipal(QWidget *parent = NULL);

    static bool bolasDesaparecen;
    QVector<Bola *> bolas;
    Bola *bolaJugador;
    Bola *nuevaBola;

    float anchuraV;
    float alturaV;
    float alturaMenuBar;

    float posIniX;
    float posIniY;

    float actuacionJugador;

    DInformacion *dInformacion;
    DListaBolas *dListaBolas;
    DTablaBolas *dTablaBolas;
    DTablaRebotes *dTablaRebotes;
    DDetalleBola *dDetalleBola;
    DConfiguracionBola *dConfiguracionBola;
    DPosicionBola *dPosicionBola;

    QTimer *temporizador;

    QAction *actionDInformacion;
    QAction *actionDListaBolas;
    QAction *actionDTablaBolas;
    QAction *actionDTablaRebotes;
    QAction *actionGuardarPartida;
    QAction *actionCargarPartida;
    QAction *actionSalir;
    QAction *actionDDetalleBola;
    QAction *actionDConfiguracionBola;
    QAction *actionDPosicionBola;

    void crearActions();
    void crearMenus();
    void inicializarBolas();
    void showEvent(QShowEvent *event);
    void paintEvent(QPaintEvent *event);
    bool crearBolaJson(QJsonValue &);
    void closeEvent(QCloseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void keyPressEvent(QKeyEvent *event);

public slots:
    void slotTemporizador();
    void slotDInformacion();
    void slotDListaBolas();
    void slotDTablaBolas();
    void slotDTablaRebotes();
    void slotGuardarPartida();
    void slotDDConfiguracionBola();
    void slotCargarPartida();
    void slotDDetalleBola();
    void slotDPosicionBola();

};
#endif
