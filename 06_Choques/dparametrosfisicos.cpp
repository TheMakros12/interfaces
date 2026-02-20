#include "dparametrosfisicos.h"
#include <QDebug>

DParametrosFisicos::DParametrosFisicos(QWidget *parent): QDialog(parent){

	setupUi(this);

	slElasticidad->setValue(100);
	slGravitacion->setValue(100);
	slJugador->setValue(100);
	slRozamiento->setValue(100);
	
}

void DParametrosFisicos::slotEjemplo(){

}
