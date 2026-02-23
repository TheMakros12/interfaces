#ifndef PANELPOSICIONCHOQUESBOLA_H
#define PANELPOSICIONCHOQUESBOLA_H
#include "bola.h"

#include <QWidget>
#include <QTimer>

class PanelPosicionChoquesBola : public QWidget {
Q_OBJECT

public:
    PanelPosicionChoquesBola(Bola *, QWidget *parent = NULL);
    Bola *laBola;

    void paintEvent(QPaintEvent *event);

public slots:
    void slotTemporizador();

};

#endif
