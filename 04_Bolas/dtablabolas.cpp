#include "dtablabolas.h"
#include <QDebug>

ModeloBolas::ModeloBolas(QVector<Bola*> *lasBolas) {

	pBolas = lasBolas;

}

int ModeloBolas::rowCount(const QModelIndex &parent) const {

	return pBolas->size();

}

int ModeloBolas::columnCount(const QModelIndex &parent) const {

	return 4;

}

QVariant ModeloBolas::headerData(int section, Qt::Orientation orientation, int role) const {

	if ( role != Qt::DisplayRole )
		return QVariant();

	QString cadena;
	if ( orientation == Qt::Horizontal ) {
		switch(section) {
			case 0: cadena = "PosX"; break;
			case 1: cadena = "PosY"; break;
			case 2: cadena = "VelX"; break;
			case 3: cadena = "VelY"; break;
		}
	}

	if ( orientation == Qt::Vertical ) {
		cadena = pBolas->at(section)->nombre;
	}

	return QVariant(cadena);

}

QVariant ModeloBolas::data(const QModelIndex &index, int role) const {

	if ( role != Qt::DisplayRole )
		return QVariant();

	int fila = index.row();
	int columna = index.column();
	Bola *bola = pBolas->at(fila);

	QString resultado;
	switch (columna) {
		case 0: resultado = QString::number(bola->posX); break;
		case 1: resultado = QString::number(bola->posY); break;
		case 2: resultado = QString::number(bola->velX); break;
		case 3: resultado = QString::number(bola->velY); break;
	};

	return QVariant(resultado);

}

void ModeloBolas::update() {

	beginResetModel();
	emit layoutChanged();
	QModelIndex topLeft = index(0,0);
	QModelIndex bottomRight = index(pBolas->size()-1, 3);
	emit dataChanged(topLeft, bottomRight);


}

DTablaBolas::DTablaBolas(QVector<Bola*> *pBolas, QWidget *parent): QDialog(parent){

	setupUi(this);

    this->setWindowTitle("Tabla de las Bolas");

	modeloBolas = new ModeloBolas(pBolas);
	vistaBolas->setModel(modeloBolas);
	vistaBolas->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	vistaBolas->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	temporizador = new QTimer();
	temporizador->setInterval(10);
	temporizador->setSingleShot(false);

	connect(temporizador, SIGNAL(timeout()),
			this, SLOT(slotTemporizador()));

	temporizador->start();
	
}


void DTablaBolas::slotTemporizador(){

	vistaBolas->resizeColumnsToContents();
	vistaBolas->resizeRowsToContents();

	int ancho = vistaBolas->verticalHeader()->width();
	for (int i = 0; i <  modeloBolas->columnCount(); i++) {
		ancho += vistaBolas->columnWidth(i);
	}

	int largo = vistaBolas->horizontalHeader()->height();
	for (int j = 0; j <  modeloBolas->rowCount(); j++) {
		largo += vistaBolas->rowHeight(j);
	}

	vistaBolas->setMinimumSize(ancho, largo);
	adjustSize();

	modeloBolas->update();
}

