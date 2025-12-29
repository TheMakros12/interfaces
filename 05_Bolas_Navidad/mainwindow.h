#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QVector>
#include <QAction>
#include <QMenu>
#include <QMenuBar>

#include "bola.h"
#include "dinformacion.h"

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

    QVector<Bola*> bolas;

    void crearBolas();
    void crearActions();
    void crearMenu();
    void paintEvent(QPaintEvent *event);

    QAction *actionInformacion;

    DInformacion *dInformacion;

public slots:
    void slotTemporizador();
    void slotDInformacion();

};
#endif
