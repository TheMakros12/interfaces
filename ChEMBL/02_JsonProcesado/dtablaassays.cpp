#include "dtablaassays.h"
#include <QDebug>

ModeloAssays::ModeloAssays(QVector<Assay> *losAssays) {

	assays = losAssays;

}

int ModeloBolas::rowCount(const QModelIndex &parent) const {

	return pBolas->size();

}


DTablaAssays::DTablaAssays(QWidget *parent): QDialog(parent){
		setupUi(this);

	
}


void DTablaAssays::slotEjemplo(){

}

