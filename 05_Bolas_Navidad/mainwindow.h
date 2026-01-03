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

#include "bola.h"
#include "dinformacion.h"
#include "dinfobolas.h"
#include "dtablabolas.h"
#include "dtablarebotes.h"

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

    static bool bolasDesaparecen;

    QVector<Bola*> bolas;
    Bola *bolaJugador;

    void crearBolas();
    void crearActions();
    void crearMenu();
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);

    QAction *actionDInformacion;
    QAction *actionDInfoBolas;
    QAction *actionDTablaBolas;
    QAction *actionDTablaRebotes;

    DInformacion *dInformacion;
    DInfoBolas *dInfoBolas;
    DTablaBolas *dTablaBolas;
    DTablaRebotes *dTablaRebotes;

public slots:
    void slotTemporizador();
    void slotDInformacion();
    void slotDInfoBolas();
    void slotDTablaBolas();
    void slotDTablaRebotes();

};
#endif
