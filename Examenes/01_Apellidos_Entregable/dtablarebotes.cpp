
#include "dtablarebotes.h"
#include <QDebug>
#include <QTimer>

DTablaRebotes::DTablaRebotes(QVector<Bola*>* lasBolas, QWidget *parent): QDialog(parent),pBolas(lasBolas){
		setupUi(this);


	modelo = new ModeloBolasRebotes(pBolas);
	vista->setModel(modelo);

	QTimer * temporizador = new QTimer ();
	temporizador->setSingleShot(false);
	temporizador->setInterval(500);
	temporizador->start();

	connect(temporizador,SIGNAL(timeout()),
			this , SLOT(slotTemporizador()));
	
}

void DTablaRebotes::slotTemporizador(){

	modelo->actualiza() ;

}


void ModeloBolasRebotes::actualiza() {

	beginResetModel();
	emit layoutChanged();
	QModelIndex topLeft = index(0,0);
	QModelIndex bottomRight = index(pBolas->size()-1,3);

	emit dataChanged(topLeft, bottomRight);


}


ModeloBolasRebotes::ModeloBolasRebotes(QVector<Bola*>* lasBolas):
pBolas(lasBolas){


}

int	ModeloBolasRebotes::rowCount(const QModelIndex &parent) const {

	return pBolas->size() ;

}


int	ModeloBolasRebotes::columnCount(const QModelIndex &parent) const {

	return 4;

}

QVariant ModeloBolasRebotes::data(const QModelIndex &index, int role ) const {

	if (role != Qt::DisplayRole)
		return QVariant();

	Bola *bola = pBolas->at(index.row());
	switch (index.column() ) {
		case 0:
			return QVariant(bola->rArriba + bola->rAbajo +
					bola->rDerecha + bola->rIzquierda);
		case 1:
			return QVariant(bola->rArriba - bola->rAbajo);
		case 2:
			return QVariant(bola->rDerecha - bola->rIzquierda);
		case 3:
			if (bola->rArriba > bola->rAbajo &&
				bola->rArriba > bola->rDerecha &&
				bola->rArriba > bola->rIzquierda
			) return QVariant("Arriba");
			if (bola->rAbajo > bola->rDerecha &&
					bola->rAbajo > bola->rIzquierda
			) return QVariant("Abajo");
			if (bola->rIzquierda > bola->rDerecha)
				return QVariant("Izquierda");
			return QVariant("Derecha");

	};

	QVariant dato ;



	return dato;


}


void DTablaRebotes::slotEjemplo(){

}
