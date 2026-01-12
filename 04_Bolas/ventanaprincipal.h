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

#include "bola.h"
#include "dinformacion.h"
#include "dlistabolas.h"
#include "dtablabolas.h"
#include "dtablarebotes.h"
#include "ddetallebola.h"
#include "dconfiguracionbola.h"

class VentanaPrincipal : public QMainWindow {
Q_OBJECT

public:
    VentanaPrincipal(QWidget *parent = NULL);

    static bool bolasDesaparecen;
    QVector<Bola *> bolas;

    DInformacion *dInformacion;
    DListaBolas *dListaBolas;
    DTablaBolas *dTablaBolas;
    DTablaRebotes *dTablaRebotes;
    DDetalleBola *dDetalleBola;
    DConfiguracionBola *dConfiguracionBola;

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

    void crearActions();
    void crearMenus();
    void inicializarBolas();
    void showEvent(QShowEvent *event);
    void paintEvent(QPaintEvent *event);
    bool crearBolaJson(QJsonValue &);
    void closeEvent(QCloseEvent *event);

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

};
#endif
