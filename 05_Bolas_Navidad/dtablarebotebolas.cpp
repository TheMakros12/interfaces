#include "dtablarebotebolas.h"
#include <QDebug>

ModeloRebotes::ModeloRebotes(QVector<Bola*> *bolasPasadas, QVector<QVector<int>> *rebotesPasados, QObject *parent) : QAbstractTableModel(parent), pBolas(bolasPasadas), rebotesBolas(rebotesPasados) {



}

int ModeloRebotes::rowCount(const QModelIndex &parent) const {

	return pBolas->size();

}

int ModeloRebotes::columnCount(const QModelIndex &parent) const {

	return pBolas->size();

}

QVariant ModeloRebotes::headerData(int section, Qt::Orientation orientation, int role) const {

	if ( role == Qt::DisplayRole ) {
		if ( orientation == Qt::Horizontal ) {
			return pBolas->at(section)->nombre;
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
		if ( fondo.lightness() > 128 )
			return QBrush(Qt::black);

		return QBrush(Qt::white);
	}

	if ( role == Qt::BackgroundRole && orientation == Qt::Horizontal ) {
		Bola *bola = pBolas->at(section);
		return QBrush(bola->color);
	}

	if ( role == Qt::ForegroundRole && orientation == Qt::Horizontal ) {
		QColor fondo = pBolas->at(section)->color;
		if ( fondo.lightness() > 128 )
			return QBrush(Qt::black);

		return QBrush(Qt::white);
	}

	return QVariant();

}

QVariant ModeloRebotes::data(const QModelIndex &index, int role) const {

	int i = index.row();
	int j = index.column();

	if ( role == Qt::TextAlignmentRole )
		return Qt::AlignCenter;

	if ( role == Qt::FontRole ) {
		QFont font;
		font.setBold(true);
		return font;
	}

	if ( role == Qt::ForegroundRole ) {
		if ( i == j || i >= rebotesBolas->size() || j >= rebotesBolas->at(i).size() )
			return QVariant();

		int valorActual = rebotesBolas->at(i).at(j);

		int valorMaximo = 1;
		for ( const auto& fila : *rebotesBolas ) {
			for (int v : fila) {
				if ( v > valorMaximo )
					valorMaximo = v;
			}
		}

		double ratio = static_cast<double>(valorActual) / valorMaximo;

		int rojo = static_cast<int>(255 * ratio);
		return QColor(rojo, 0, 0);
	}

	if ( role == Qt::DisplayRole ) {
		if (i < 0 || j < 0 || i >= rebotesBolas->size() || j >= rebotesBolas->at(i).size())
			return QVariant();

		if (i == j)
			return QString("-");

		return rebotesBolas->at(i).at(j);
	}

	return QVariant();

}

void ModeloRebotes::update() {
	emit layoutChanged();
}



DTablaReboteBolas::DTablaReboteBolas(QVector<Bola*> *bolasPasadas, QVector<QVector<int>> * rebotesPasados, QWidget *parent): QDialog(parent), pBolas(bolasPasadas), rebotesBolas(rebotesPasados) {

	setupUi(this);

	setWindowTitle("Rebote de las Bolas");

	modeloRebotes = new ModeloRebotes(pBolas, rebotesPasados);
	tablaReboteBolas->setModel(modeloRebotes);

	const int anchoColumna = 55;

	tablaReboteBolas->horizontalHeader()
	->setSectionResizeMode(QHeaderView::Fixed);
	tablaReboteBolas->horizontalHeader()
	->setStretchLastSection(false);

	for (int i = 0; i < modeloRebotes->columnCount(); ++i)
		tablaReboteBolas->setColumnWidth(i, anchoColumna);

	tablaReboteBolas->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	tablaReboteBolas->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	temporizador = new QTimer();
	temporizador->setInterval(10);
	temporizador->setSingleShot(false);

	connect(temporizador, SIGNAL(timeout()),
			this, SLOT(slotTemporizador()));

	temporizador->start();
	
}

void DTablaReboteBolas::slotTemporizador(){

	modeloRebotes->update();

}

