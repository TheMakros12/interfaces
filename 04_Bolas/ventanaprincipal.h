#ifndef VENTANAPRINCIPAL_H_
#define VENTANAPRINCIPAL_H_

#include <QMainWindow>
#include <QPaintEvent>
#include <QVector>
#include <QImage>
#include <QMenu>
#include <QAction>
#include <QMenuBar>

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
    QAction *actionSalir;

    void paintEvent(QPaintEvent *event);
    void inicializarBolas();
    void crearActions();
    void crearMenus();

public slots:
    void slotTemporizador();
    void slotDListaBolas();
    void slotDTablaBolas();
    void slotDTablaRebotes();

};
#endif
