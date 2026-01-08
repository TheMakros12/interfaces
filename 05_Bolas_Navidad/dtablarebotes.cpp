#include "dtablarebotes.h"
#include <QDebug>

/************************ModeloTabla***************************/

ModeloBolasRebotes::ModeloBolasRebotes(QVector<Bola*> *bolasPasadas, Bola **bolaEspecial, QObject *parent) : pBolas(bolasPasadas), bolaJugador(bolaEspecial) {

}

int ModeloBolasRebotes::rowCount(const QModelIndex &parent) const {

	int extra = (bolaJugador && *bolaJugador) ? 1 : 0;
	return pBolas->size() + extra;

}

int ModeloBolasRebotes::columnCount(const QModelIndex &parent) const {

	return 4;

}

QVariant ModeloBolasRebotes::headerData(int section, Qt::Orientation orientation, int role) const {

	if ( role == Qt::DisplayRole ){
		if ( orientation == Qt::Horizontal ) {
			switch ( section ) {
				case 0: return "Total Rebotes";
				case 1: return "Rebotes Y";
				case 2: return "Rebotes X";
				case 3: return "Dirección";
			};
		}

		if ( orientation == Qt::Vertical ) {
			if ( bolaJugador && *bolaJugador ) {
				if (section == 0) return "Jugador";
				else return pBolas->at(section - 1)->nombre;
			} else {
				return pBolas->at(section)->nombre;
			}
		}
	}

	if (orientation == Qt::Vertical &&
		(role == Qt::BackgroundRole || role == Qt::ForegroundRole)) {

		Bola *laBola = nullptr;

	if (bolaJugador && *bolaJugador) {
		laBola = (section == 0)
		? *bolaJugador
		: pBolas->at(section - 1);
	} else {
		laBola = pBolas->at(section);
	}

	if (role == Qt::BackgroundRole)
		return QBrush(laBola->color);

		if (role == Qt::ForegroundRole)
			return QBrush(laBola->color.lightness() > 128
			? Qt::black
			: Qt::white);
		}

	return QVariant();

}

QVariant ModeloBolasRebotes::data(const QModelIndex &index, int role) const {

	int fila = index.row();
	int columna = index.column();
	Bola *laBola = nullptr;

	if ( bolaJugador && *bolaJugador ) {
		if ( fila == 0 ) {
			laBola = *bolaJugador;
		} else {
			laBola = pBolas->at(fila - 1);
		}
	} else {
		laBola = pBolas->at(fila);
	}

	int sumaRebotes = laBola->rArriba + laBola->rAbajo + laBola->rIzquierda + laBola->rDerecha;
	int rebVeritcales = laBola->rArriba + laBola->rAbajo;
	int rebHorizontales = laBola->rIzquierda + laBola->rDerecha;

		if ( role == Qt::DisplayRole ){
			switch (columna) {
			case 0:
				return sumaRebotes;
			case 1:
				return rebVeritcales;
			case 2:
				return rebHorizontales;
			case 3:
				if ( laBola->rArriba > laBola->rAbajo &&
					laBola->rArriba > laBola->rDerecha &&
					laBola->rArriba > laBola->rIzquierda )
					return "Arriba";

				if ( laBola->rAbajo > laBola->rDerecha &&
					laBola->rAbajo > laBola->rIzquierda )
					return "Abajo";

				if ( laBola->rIzquierda > laBola->rDerecha )
					return "Izquierda";

				return "Derecha";
				break;
			};

		}

	return QVariant();

}

void ModeloBolasRebotes::update() {

    emit layoutChanged();

}

/************************ModeloTabla***************************/

DTablaRebotes::DTablaRebotes(QVector<Bola*> *bolasPasadas, Bola **bolaEspecial, QWidget *parent): QDialog(parent), pBolas(bolasPasadas) {

	setupUi(this);

	this->setWindowTitle("Tabla de los Rebotes");

	modeloRebotes = new ModeloBolasRebotes(pBolas, bolaEspecial);
	tablaRebotes->setModel(modeloRebotes);
	tablaRebotes->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	tablaRebotes->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	temporizador = new QTimer();
	temporizador->setInterval(10);
	temporizador->setSingleShot(false);

	connect(temporizador, SIGNAL(timeout()),
			this, SLOT(slotTemporizador()));

	temporizador->start();

	connect(btnRestablecerRebotes, SIGNAL(clicked()),
			this, SLOT(slotRestablecerRebotes()));

}

void DTablaRebotes::slotTemporizador(){

	modeloRebotes->update();

	tablaRebotes->resizeRowsToContents();
	tablaRebotes->resizeColumnsToContents();

	int ancho = tablaRebotes->verticalHeader()->width();
	for (int i = 0; i <  modeloRebotes->columnCount(); i++) {
		ancho += tablaRebotes->columnWidth(i);
	}
	ancho += 2 * tablaRebotes->frameWidth() + 20;
	tablaRebotes->setMinimumWidth(ancho);

	int largo = tablaRebotes->horizontalHeader()->height();
	for (int j = 0; j <  modeloRebotes->rowCount(); j++) {
		largo += tablaRebotes->rowHeight(j);
	}
	largo += 2 * tablaRebotes->frameWidth();
	tablaRebotes->setMinimumHeight(largo);

	tablaRebotes->setMinimumSize(ancho, largo);

	adjustSize();

}

void DTablaRebotes::slotRestablecerRebotes(){

	for (Bola *bola : *modeloRebotes->pBolas) {
		bola->rArriba = 0;
		bola->rAbajo = 0;
		bola->rIzquierda = 0;
		bola->rDerecha = 0;
	}

	modeloRebotes->update();

}
