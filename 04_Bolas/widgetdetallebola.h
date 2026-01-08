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
	WidgetDetalleBola(Bola *, QWidget *parent = NULL);
	Bola *laBola;

	void inicializarColores();

public slots:
	void slotCambiarRojo(int);
	void slotCambiarVerde(int);
	void slotCambiarAzul(int);
	void on_btnPararBola_clicked();

};

#endif 
