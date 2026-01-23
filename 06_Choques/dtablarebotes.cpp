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

	if ( role == Qt::TextAlignmentRole )
		return Qt::AlignCenter;

	if ( role == Qt::FontRole ) {
		QFont font;
		font.setBold(true);
		return font;
	}

	if ( role == Qt::DisplayRole ) {

		if ( orientation == Qt::Horizontal ) {
			switch (section) {
				case 0: return "Total Rebotes";
				case 1: return "Rebotes Y";
				case 2: return "Rebotes X";
				case 3: return "Dirección";
			}
		}

		if ( orientation == Qt::Vertical ) {
			return pBolas->at(section)->nombre;
		}
	}

	if ( role == Qt::BackgroundRole && orientation == Qt::Vertical ) {
		Bola *bola = pBolas->at(section);
		return QBrush(bola->color);
	}

	if ( role == Qt::ForegroundRole && orientation == Qt::Vertical ) {
		QColor fondo = pBolas->at(section)->color;
		if (fondo.lightness() > 128) {
			return QBrush(Qt::black);
		} else {
			return QBrush(Qt::white);
		}
	}

	return QVariant();

}

QVariant ModeloBolasRebotes::data(const QModelIndex &index, int role) const {

	if ( role == Qt::TextAlignmentRole )
		return Qt::AlignCenter;

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

	temporizador = new QTimer();
    temporizador->setInterval(500);
    temporizador->setSingleShot(false);

    connect(temporizador, SIGNAL(timeout()),
            this, SLOT(slotTemporizador()));

    temporizador->start();

	slotRestablecerRebotes();

	connect(btnRestablecerRebotes, SIGNAL(clicked()),
			this, SLOT(slotRestablecerRebotes()));
	
}


void DTablaRebotes::slotTemporizador(){

	modeloRebotes->update();

}

void DTablaRebotes::slotRestablecerRebotes() {

	for (Bola *bola : *modeloRebotes->pBolas)
		bola->restablecerRebotes();

	modeloRebotes->update();

}
