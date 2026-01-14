#ifndef PANELPOSICIONBOLA_H
#define PANELPOSICIONBOLA_H
#include "bola.h"

#include <QWidget>
#include <QTimer>
#include <QMouseEvent>

class PanelPosicionBola : public QWidget {
Q_OBJECT

public:
    PanelPosicionBola(Bola *, QWidget *parent = NULL);
    Bola *laBola;

    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

public slots:
    void slotTemporizador();

};

#endif
