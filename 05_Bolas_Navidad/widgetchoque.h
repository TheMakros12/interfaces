#ifndef WIDGETCHOQUE_H
#define WIDGETCHOQUE_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>

#include "bola.h"

class WidgetChoque : public QWidget {
Q_OBJECT

public:
    WidgetChoque(Bola *, QWidget *parent = NULL);
    Bola *bola;

    void paintEvent(QPaintEvent *event);

public slots:

};

#endif
