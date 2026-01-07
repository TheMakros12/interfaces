#include "ddetallebola.h"
#include <QDebug>

DDetalleBola::DDetalleBola(QVector<Bola*> *bolas, QWidget *parent): QDialog(parent), lasBolas(bolas), numBola(0) {
	setupUi(this);

	setWindowTitle("Detalle de las Bolas");

	lblNombreBola->setText(lasBolas->at(numBola)->nombre);
	lblNumBola->setText(QString::number(numBola));

	slRojo->setRange(0,255);
	slVerde->setRange(0,255);
	slAzul->setRange(0,255);

	inicializarColores();

	btnAnterior->setEnabled(false);

	connect(slRojo, SIGNAL(valueChanged(int)),
			this, SLOT(slotCambiarRojo(int)));

	connect(slVerde, SIGNAL(valueChanged(int)),
			this, SLOT(slotCambiarVerde(int)));

	connect(slAzul, SIGNAL(valueChanged(int)),
			this, SLOT(slotCambiarAzul(int)));

	connect(btnAnterior, SIGNAL(clicked()),
			this, SLOT(slotAnterior()));

	connect(btnSiguiente, SIGNAL(clicked()),
			this, SLOT(slotSiguiente()));
	
}

void DDetalleBola::inicializarColores() {

	slRojo->setValue(lasBolas->at(numBola)->color.red());
	slVerde->setValue(lasBolas->at(numBola)->color.green());
	slAzul->setValue(lasBolas->at(numBola)->color.blue());

	lblIntRojo->setText(QString::number(lasBolas->at(numBola)->color.red()));
	lblIntVerde->setText(QString::number(lasBolas->at(numBola)->color.green()));
	lblIntAzul->setText(QString::number(lasBolas->at(numBola)->color.blue()));

}

void DDetalleBola::slotCambiarRojo(int valorRojo){

	lasBolas->at(numBola)->color.setRed(valorRojo);
}

void DDetalleBola::slotCambiarVerde(int valorVerde){

	lasBolas->at(numBola)->color.setGreen(valorVerde);

}

void DDetalleBola::slotCambiarAzul(int valorAzul){

	lasBolas->at(numBola)->color.setBlue(valorAzul);

}

void DDetalleBola::slotAnterior() {

	btnSiguiente->setEnabled(true);

	if (numBola == 1)
		btnAnterior->setEnabled(false);

	numBola--;

	lblNombreBola->setText(lasBolas->at(numBola)->nombre);
	lblNumBola->setText(QString::number(numBola));
	inicializarColores();

}

void DDetalleBola::slotSiguiente() {

	btnAnterior->setEnabled(true);

	numBola++;

	if (numBola == 9)
		btnSiguiente->setEnabled(false);

	lblNombreBola->setText(lasBolas->at(numBola)->nombre);
	lblNumBola->setText(QString::number(numBola));
	inicializarColores();

}
