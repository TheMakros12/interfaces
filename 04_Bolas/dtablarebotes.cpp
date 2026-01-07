
#include "dtablarebotes.h"
#include <QDebug>

ModeloBolasRebotes::ModeloBolasRebotes(QVector<Bola*> *lasBolas) {

	pBolas = lasBolas;

}

int ModeloBolasRebotes::rowCount(const QModelIndex &parent) const {

	return pBolas->size();

}

int ModeloBolasRebotes::columnCount(const QModelIndex &parent) const {

	return 4;

}

QVariant ModeloBolasRebotes::headerData(int section, Qt::Orientation orientation, int role) const {

	if ( role != Qt::DisplayRole )
		return QVariant();

	QString cadena;
	if ( orientation == Qt::Horizontal ) {
		switch(section) {
			case 0: cadena = "Total Rebotes"; break;
			case 1: cadena = "Rebotes Y"; break;
			case 2: cadena = "Rebotes X"; break;
			case 3: cadena = "Dirección"; break;
		}
	}

	if ( orientation == Qt::Vertical ) {
		cadena = pBolas->at(section)->nombre;
	}

	return QVariant(cadena);

}

QVariant ModeloBolasRebotes::data(const QModelIndex &index, int role) const {

	if ( role != Qt::DisplayRole )
		return QVariant();

	int fila = index.row();
	int columna = index.column();
	Bola *bola = pBolas->at(fila);

	int sumaRebotes = bola->rIzquierda + bola->rDerecha + bola->rArriba + bola->rAbajo;
	int rebVeritcales = bola->rArriba + bola->rAbajo;
	int rebHorizontales = bola->rIzquierda + bola->rDerecha;

	QString resultado;
	switch (columna) {
		case 0: resultado = QString::number(sumaRebotes); break;
		case 1: resultado = QString::number(rebVeritcales); break;
		case 2: resultado = QString::number(rebHorizontales); break;
		case 3:
			if ( bola->rArriba > bola->rAbajo &&
				bola->rArriba > bola->rDerecha &&
				bola->rArriba > bola->rIzquierda )
				return QVariant("Arriba");

			if ( bola->rAbajo > bola->rDerecha &&
				bola->rAbajo > bola->rIzquierda )
				return QVariant("Abajo");

			if ( bola->rIzquierda > bola->rDerecha )
				return QVariant("Izquierda");

		return QVariant("Derecha");
			break;
	};

	return QVariant(resultado);

}

void ModeloBolasRebotes::update() {

	beginResetModel();
	emit layoutChanged();
	QModelIndex topLeft = index(0,0);
	QModelIndex bottomRight = index(pBolas->size()-1, 3);
	emit dataChanged(topLeft, bottomRight);



}

DTablaRebotes::DTablaRebotes(QVector<Bola*> *pBolas, QWidget *parent): QDialog(parent){

	setupUi(this);

    this->setWindowTitle("Tabla de los Rebotes");

	modeloRebotes = new ModeloBolasRebotes(pBolas);
	tablaRebotes->setModel(modeloRebotes);
	tablaRebotes->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	tablaRebotes->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	temporizador = new QTimer();
    temporizador->setInterval(10);
    temporizador->setSingleShot(false);

    connect(temporizador, SIGNAL(timeout()),
            this, SLOT(slotTemporizador()));

    temporizador->start();
	
}


void DTablaRebotes::slotTemporizador(){

	tablaRebotes->resizeColumnsToContents();
	tablaRebotes->resizeRowsToContents();

	int ancho = tablaRebotes->verticalHeader()->width();
	for (int i = 0; i <  modeloRebotes->columnCount(); i++) {
		ancho += tablaRebotes->columnWidth(i);
	}

	int largo = tablaRebotes->horizontalHeader()->height();
	for (int j = 0; j <  modeloRebotes->rowCount(); j++) {
		largo += tablaRebotes->rowHeight(j);
	}

	tablaRebotes->setMinimumSize(ancho, largo);
	adjustSize();

	modeloRebotes->update();

}

