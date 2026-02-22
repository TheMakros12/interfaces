#ifndef WIDGETBOLA_H
#define WIDGETBOLA_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>

#include "bola.h"

class WidgetBola : public QWidget {
Q_OBJECT

public:
    WidgetBola(Bola *, QWidget *parent = NULL);
    Bola *bola;

    void paintEvent(QPaintEvent *event);

public slots:
    void slotTemporizador();

};

#endif
