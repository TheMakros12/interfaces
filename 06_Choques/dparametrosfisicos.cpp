#include "dparametrosfisicos.h"
#include <QDebug>

DParametrosFisicos::DParametrosFisicos(QWidget *parent): QDialog(parent){

	setupUi(this);

	spinnerRozamiento->setRange(0, 100);
	spinnerElasticidad->setRange(0, 100);
	spinnerGravitacion->setRange(0, 100);
	spinnerJugador->setRange(0, 100);

	connect(spinnerRozamiento, SIGNAL(valueChanged(int)),
			this, SLOT(slotCambiarRozamiento(int)));

	connect(spinnerElasticidad, SIGNAL(valueChanged(int)),
			this, SLOT(slotCambiarElasticidad(int)));

	connect(spinnerGravitacion, SIGNAL(valueChanged(int)),
			this, SLOT(slotCambiarGravitacion(int)));

	connect(spinnerJugador, SIGNAL(valueChanged(int)),
			this, SLOT(slotCambiarJugador(int)));
	
}

void DParametrosFisicos::slotCambiarRozamiento(int valor){

}

void DParametrosFisicos::slotCambiarElasticidad(int valor){

}

void DParametrosFisicos::slotCambiarGravitacion(int valor){

}

void DParametrosFisicos::slotCambiarJugador(int valor){

}
