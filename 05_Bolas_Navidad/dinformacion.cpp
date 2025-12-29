#include "dinformacion.h"
#include <QDebug>

DInformacion::DInformacion(int anchura, int altura, int numBOlas, QWidget *parent): QDialog(parent){

		setupUi(this);

		QString dimensiones("");
		dimensiones = dimensiones + QString::number(anchura) + " x " + QString::number(altura);

		lblDimensiones->setText(dimensiones);
		lblNumBolas->setText(QString::number(numBOlas));

	
}


void DInformacion::slotEjemplo(){

}

