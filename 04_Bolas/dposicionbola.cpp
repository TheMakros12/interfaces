#include "dposicionbola.h"
#include <QDebug>

DPosicionBola::DPosicionBola(QVector<Bola*> *bolasPasadas, QWidget *parent): QDialog(parent), lasBolas(bolasPasadas) {

	setupUi(this);

	setWindowTitle("Posición de la Bola");

	tabPosicion->clear();

	for (int i = 0; i < lasBolas->size(); i++) {
		tabPosicion->addTab(new WidgetPosicionBola(lasBolas->at(i)),
						  lasBolas->at(i)->nombre);
	}
	
}


void DPosicionBola::slotEjemplo(){

}

