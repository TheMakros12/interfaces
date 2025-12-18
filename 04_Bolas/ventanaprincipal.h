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
#include "dlistabolas.h"
#include "dtablabolas.h"
#include "dtablarebotes.h"

class VentanaPrincipal : public QMainWindow {
Q_OBJECT

public:
    VentanaPrincipal(QWidget *parent = NULL);

    static bool bolasDesaparecen;
    QVector<Bola *> bolas;
    Bola bola;
    DListaBolas *dListaBolas;
    DTablaBolas *dTablaBolas;
    DTablaRebotes *dTablaRebotes;

    QTimer *temporizador;

    QAction *actionDListaBolas;
    QAction *actionDTablaBolas;
    QAction *actionDTablaRebotes;
    QAction *actionGuardarPartida;
    QAction *actionCargarPartida;
    QAction *actionSalir;

    void paintEvent(QPaintEvent *event);
    void closeEvent(QCloseEvent *event);
    void inicializarBolas();
    void crearActions();
    void crearMenus();
    bool crearBolaJson(QJsonValue &);

public slots:
    void slotTemporizador();
    void slotDListaBolas();
    void slotDTablaBolas();
    void slotDTablaRebotes();
    void slotGuardarPartida();
    void slotCargarPartida();

};
#endif
