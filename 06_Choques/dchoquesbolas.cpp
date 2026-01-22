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

	if ( role == Qt::TextAlignmentRole )
		return Qt::AlignCenter;

	if ( role == Qt::FontRole ) {
		QFont font;
		font.setBold(true);
		return font;
	}

	if ( role == Qt::DisplayRole ) {
		if ( orientation == Qt::Horizontal ) {
			return section;
		}

		if ( orientation == Qt::Vertical ) {
			return " " + QString::number(section) + " ";
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

	int i = index.row();
	int j = index.column();

	int aux = 0;

	if ( role == Qt::TextAlignmentRole )
		return Qt::AlignCenter;

	if ( role == Qt::DisplayRole ) {

		if ( i < 0 || j < 0 || i >= 10 || j >= 10)
			return QVariant();

		if ( i == j) {
			return QString("-");
		}

		for (int i = 0; i < bolas->at(i)->posicionesChoques.size(); i++) {
			if ()
		}

	}

	return QVariant();

}

DChoquesBolas::DChoquesBolas(QVector<Bola*> *lasBolas, QWidget *parent): QDialog(parent), bolas(lasBolas) {

	setupUi(this);

	setWindowTitle("Choques de las Bolas");

	modeloChoques = new ModeloChoques(bolas);
	tablaChoques->setModel(modeloChoques);

	const int anchoColumna = 55;

	tablaChoques->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	tablaChoques->horizontalHeader()->setStretchLastSection(false);

	for (int i = 0; i < modeloChoques->columnCount(); i++)
		tablaChoques->setColumnWidth(i, anchoColumna);

	const int altoFila = 35;


	tablaChoques->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	tablaChoques->verticalHeader()->setStretchLastSection(false);

	for (int i = 0; i < modeloChoques->rowCount(); i++)
		tablaChoques->setRowHeight(i, altoFila);
	
}

void DChoquesBolas::slotTemporizador(){

}

