
#include "ddetallebola.h"
#include <QDebug>

DDetalleBola::DDetalleBola(QVector<Bola*> *bolasPasadas, QWidget *parent): QDialog(parent){
		setupUi(this);

		lasBolas = bolasPasadas;

		indiceBolaElegida = 0;

		lNombre->setText(lasBolas->at(0)->nombre);


		slRojo->setMinimum(0);
		slRojo->setMaximum(255);
		slRojo->setValue(lasBolas->at(0)->color.red());


		connect(slRojo,SIGNAL(valueChanged(int)),
				this,SLOT(slotCambioRojo(int)));
	
}


void DDetalleBola::slotEjemplo(){

}

/* este slot se autoconnecta */
void DDetalleBola::on_bAnterior_clicked(){
	indiceBolaElegida--;
	bSiguiente->setEnabled(true);
	if ( indiceBolaElegida == 0 )
		bAnterior->setEnabled(false);
}

void DDetalleBola::on_bSiguiente_clicked(){
	indiceBolaElegida++;
	bAnterior->setEnabled(true);

	if (indiceBolaElegida ==  (lasBolas->length() - 1 ) )  bSiguiente->setEnabled(false);

}

void DDetalleBola::slotCambioRojo(int rojo){

	lasBolas->at(indiceBolaElegida)->color.setRed(rojo);

}

