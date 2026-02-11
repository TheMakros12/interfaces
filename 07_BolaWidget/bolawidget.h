#ifndef _BOLAWIDGET_H
#define _BOLAWIDGET_H

#include "bola.h"
#include "panelposicionbola.h"

class BolaWidget : public Bola, public PanelPosicionBola {
Q_OBJECT

public:
    BolaWidget(float posX, float posY, float velX, float velY, QWidget *parent = NULL);


};

#endif
