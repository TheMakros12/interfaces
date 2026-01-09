#include "widgetdetallebola.h"
#include <QDebug>

WidgetDetalleBola::WidgetDetalleBola(Bola *bolaPasada, QWidget *parent): QWidget(parent), laBola(bolaPasada) {

	setupUi(this);

	lblNombreBola->setText(laBola->nombre);

	slRojo->setRange(0,255);
	slVerde->setRange(0,255);
	slAzul->setRange(0,255);

	connect(slRojo, SIGNAL(valueChanged(int)),
			this, SLOT(slotCambiarRojo(int)));

	connect(slVerde, SIGNAL(valueChanged(int)),
			this, SLOT(slotCambiarVerde(int)));

	connect(slAzul, SIGNAL(valueChanged(int)),
			this, SLOT(slotCambiarAzul(int)));

	connect(leNuevoNombre, SIGNAL(returnPressed()),
			this, SLOT(slotCambiarNombre()));

	inicializarColores();
	
}

void WidgetDetalleBola::slotCambiarNombre() {

	QString nuevoNombre = leNuevoNombre->text();
	laBola->nombre = nuevoNombre;

}

void WidgetDetalleBola::inicializarColores() {

	slRojo->setValue(laBola->color.red());
	slVerde->setValue(laBola->color.green());
	slAzul->setValue(laBola->color.blue());

	lblIntRojo->setText(QString::number(laBola->color.red()));
	lblIntVerde->setText(QString::number(laBola->color.green()));
	lblIntAzul->setText(QString::number(laBola->color.blue()));

}

void WidgetDetalleBola::slotCambiarRojo(int rojo){

	laBola->color.setRed(rojo);

}

void WidgetDetalleBola::slotCambiarVerde(int verde){

	laBola->color.setGreen(verde);

}

void WidgetDetalleBola::slotCambiarAzul(int azul){

	laBola->color.setBlue(azul);

}

void WidgetDetalleBola::on_btnPararBola_clicked(){

	laBola->velX = 0;
	laBola->velY = 0;

}

void WidgetDetalleBola::on_btnMoverBola_clicked(){

	float velIniX = (float)(random() % 100) / 50 - 1;
	float velIniY = (float)(random() % 100) / 50 - 1;
	laBola->velX = velIniX;
	laBola->velY = velIniY;

}
