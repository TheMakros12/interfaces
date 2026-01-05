#include "dinformacion.h"
#include <QDebug>

DInformacion::DInformacion(int anchura, int altura, int numBolas, QWidget *parent): QDialog(parent){

	setupUi(this);

	setWindowTitle("Información del Juego");

	QString dimensiones("");
	dimensiones = dimensiones + QString::number(anchura) + " x " + QString::number(altura);

	lblDimensiones->setText(dimensiones);
	lblNumBolas->setText(QString::number(numBolas));

	
}


void DInformacion::slotEjemplo(){

}

