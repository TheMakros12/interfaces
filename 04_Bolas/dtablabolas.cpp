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

	if ( role == Qt::DisplayRole ) {

		if ( orientation == Qt::Horizontal ) {
			switch (section) {
				case 0: return "PosX";
				case 1: return "PosY";
				case 2: return "VelX";
				case 3: return "VelY";
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

bool ModeloBolas::setData(const QModelIndex &index, const QVariant &value, int role) {

	if ( role != Qt::EditRole )
		return false;

	Bola *laBola = pBolas->at(index.row());
	float valor = value.toFloat();

	switch ( index.column() ) {
		case 0: laBola->posX = valor; break;
		case 1: laBola->posY = valor; break;
		case 2: laBola->velX = valor; break;
		case 3: laBola->velY = valor; break;
	};

	emit dataChanged(index, index);

	return true;

}

Qt::ItemFlags ModeloBolas::flags(const QModelIndex &index) const {
	return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
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
	temporizador->setInterval(500);
	temporizador->setSingleShot(false);

	connect(temporizador, SIGNAL(timeout()),
			this, SLOT(slotTemporizador()));

	temporizador->start();
	
}

void DTablaBolas::ajustarTamano()
{
	int ancho =
	vistaBolas->verticalHeader()->width() +
	vistaBolas->frameWidth() * 2;

	for (int c = 0; c < modeloBolas->columnCount(); ++c)
		ancho += vistaBolas->columnWidth(c);

	int alto =
	vistaBolas->horizontalHeader()->height() +
	vistaBolas->frameWidth() * 2;

	for (int r = 0; r < modeloBolas->rowCount(); ++r)
		alto += vistaBolas->rowHeight(r);

	vistaBolas->setFixedSize(ancho, alto);
	setFixedSize(sizeHint());
}

void DTablaBolas::slotTemporizador(){

	ajustarTamano();

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

