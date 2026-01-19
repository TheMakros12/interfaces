#include "dinformacion.h"
#include <QDebug>

DInformacion::DInformacion(int altura, int anchura, int numBolas, QWidget *parent): QDialog(parent) {

	setupUi(this);

	QString dimensiones;
	dimensiones += QString::number(altura) +
				" x " +
				QString::number(anchura);
	lblDimensiones->setText(dimensiones);

	lblNumBolas->setText(QString::number(numBolas));
	
}


void DInformacion::slotEjemplo(){

}

