#ifndef WIDGETCHOQUE_H
#define WIDGETCHOQUE_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>

#include "bola.h"

class WidgetChoque : public QWidget {
Q_OBJECT

public:
    WidgetChoque(QVector<Bola*> *, QWidget *parent = NULL);
    QVector<Bola*> *bolas;

    void paintEvent(QPaintEvent *event);

public slots:
    void slotTemporizador();

};

#endif
