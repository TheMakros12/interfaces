
#ifndef WIDGETDETALLEBOLA_H
#define WIDGETDETALLEBOLA_H
#include "ui_widgetdetallebola.h"
#include "bola.h"

#include <QVector>
#include <QWidget>
#include <QHBoxLayout>

class WidgetDetalleBola : public QWidget, public Ui::WidgetDetalleBola {
Q_OBJECT

public:
	WidgetDetalleBola(Bola * , QWidget *parent = NULL);
	Bola * laBola;

public slots:
	void slotEjemplo();
	void slotCambioRojo(int);
	void on_bParar_clicked();


};

#endif 
