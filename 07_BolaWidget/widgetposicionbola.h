
#ifndef WIDGETPOSICIONBOLA_H
#define WIDGETPOSICIONBOLA_H
#include "ui_widgetposicionbola.h"
#include "bola.h"
#include "panelposicionbola.h"

#include <QVector>
#include <QWidget>
#include <QHBoxLayout>

class WidgetPosicionBola : public QWidget, public Ui::WidgetPosicionBola {
Q_OBJECT

public:
	WidgetPosicionBola(Bola *, QWidget *parent = NULL);
	Bola *laBola;

public slots:
	void slotEjemplo();

};

#endif 
