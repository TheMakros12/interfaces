#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QVector>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStringList>
#include <QKeyEvent>
#include <QShowEvent>
#include <QCloseEvent>
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
#include "dinfobolas.h"
#include "dtablabolas.h"
#include "dtablarebotes.h"
#include "dcontrolbolas.h"
#include "dtablarebotebolas.h"

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

    static bool bolasDesaparecen;

    QVector<Bola*> bolas;
    Bola *bolaJugador;
    QVector<QVector<int>> rebotes;

    void crearBolas();
    void crearActions();
    void crearMenu();
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void showEvent(QShowEvent *event);
    void closeEvent(QCloseEvent *event);
    bool crearBolaJson(QJsonValue &);

    QAction *actionDInformacion;
    QAction *actionDInfoBolas;
    QAction *actionDTablaBolas;
    QAction *actionDTablaRebotes;
    QAction *actionDControlBolas;
    QAction *actionGuardarPartida;
    QAction *actionCargarPartida;
    QAction *actionSalir;
    QAction *actionDTablaReboteBolas;

    DInformacion *dInformacion;
    DInfoBolas *dInfoBolas;
    DTablaBolas *dTablaBolas;
    DTablaRebotes *dTablaRebotes;
    DControlBolas *dControlBolas;
    DTablaReboteBolas *dTablaReboteBolas;

public slots:
    void slotTemporizador();
    void slotDInformacion();
    void slotDInfoBolas();
    void slotDTablaBolas();
    void slotDTablaRebotes();
    void slotDControlBolas();
    void slotGuardarPartida();
    void slotCargarPartida();
    void slotDTablaReboteBolas();

};
#endif
