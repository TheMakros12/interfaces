#include "dinformacion.h"
#include <QDebug>
#include <QTimer>

DInformacion::DInformacion(int anchura, int altura, int numBolas, QWidget *parent): bolas(numBolas), QDialog(parent){

	setupUi(this);

	setWindowTitle("Información del Juego");

	QString dimensiones("");
	dimensiones = dimensiones + QString::number(anchura) + " x " + QString::number(altura);

	lblDimensiones->setText(dimensiones);
	lblNumBolas->setText(QString::number(numBolas));

	QTimer *temporizador = new QTimer();
	temporizador->setSingleShot(false);
	temporizador->setInterval(100);

	connect(temporizador, SIGNAL(timeour()),
			this, SLOT(slotEjemplo()));

	temporizador->start();
	
}


void DInformacion::slotEjemplo(){

	lblNumBolas->setText(QString::number(bolas));

}

