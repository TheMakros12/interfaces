#include "bolawidget.h"

BolaWidget::BolaWidget(float posX, float posY, float velX, float velY, QWidget *parent) : Bola(posX, posY, velX, velY), PanelPosicionBola(this, parent) {



}
