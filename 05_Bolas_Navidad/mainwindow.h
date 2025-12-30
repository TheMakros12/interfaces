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

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

    QVector<Bola*> bolas;
    Bola *bolaJugador;

    void crearBolas();
    void crearActions();
    void crearMenu();
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);

    QAction *actionDInformacion;
    QAction *actionDInfoBolas;

    DInformacion *dInformacion;
    DInfoBolas *dInfoBolas;

public slots:
    void slotTemporizador();
    void slotDInformacion();
    void slotDInfoBolas();

};
#endif
