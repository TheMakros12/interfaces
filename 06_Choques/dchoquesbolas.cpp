
#include "dchoquesbolas.h"
#include <QDebug>

ModeloChoques::ModeloChoques(QVector<Bola*> *lasBolas): bolas(lasBolas) {

}

int	ModeloChoques::rowCount(const QModelIndex &parent) const {
	return bolas->size();
}

int	ModeloChoques::columnCount(const QModelIndex &parent) const {
	return bolas->size();
}

QVariant ModeloChoques::headerData(int section, Qt::Orientation orientation, int role) const {

	if ( role == Qt::DisplayRole ) {
		if ( orientation == Qt::Horizontal ) {
			return bolas->at(section)->nombre;
		}

		if ( orientation == Qt::Vertical ) {
			return bolas->at(section)->nombre;
		}
	}

	if ( role == Qt::BackgroundRole && orientation == Qt::Vertical ) {
		Bola *bola = bolas->at(section);
		return QBrush(bola->color);
	}

	if ( role == Qt::ForegroundRole && orientation == Qt::Vertical ) {
		QColor fondo = bolas->at(section)->color;
		if ( fondo.lightness() > 128 )
			return QBrush(Qt::black);

		return QBrush(Qt::white);
	}

	if ( role == Qt::BackgroundRole && orientation == Qt::Horizontal ) {
		Bola *bola = bolas->at(section);
		return QBrush(bola->color);
	}

	if ( role == Qt::ForegroundRole && orientation == Qt::Horizontal ) {
		QColor fondo = bolas->at(section)->color;
		if ( fondo.lightness() > 128 )
			return QBrush(Qt::black);

		return QBrush(Qt::white);
	}

	return QVariant();

}

QVariant ModeloChoques::data(const QModelIndex &index, int role) const {
	return QVariant();
}

DChoquesBolas::DChoquesBolas(QVector<Bola*> *lasBolas, QWidget *parent): QDialog(parent), bolas(lasBolas) {

	setupUi(this);

	setWindowTitle("Choques de las Bolas");

	modeloChoques = new ModeloChoques(bolas);
	tablaChoques->setModel(modeloChoques);
	
}

void DChoquesBolas::slotTemporizador(){

}

