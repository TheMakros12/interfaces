#include "dchoquesbolas.h"
#include <QDebug>
#include <QTimer>

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

	if (!index.isValid())
        return QVariant();

	int i = index.row();
	int j = index.column();

	if ( role == Qt::TextAlignmentRole )
		return Qt::AlignCenter;

	if (i == j) {
        if (role == Qt::DisplayRole)
            return "-";
        return QVariant();
    }

    if (role == Qt::DisplayRole)
        return bolas->at(i)->acumuladoChoques[j];

	if (role == Qt::BackgroundRole) {

		int choques = bolas->at(i)->acumuladoChoques[j];

		if (choques == 0)
			return QBrush(Qt::white);

		// Buscar el máximo global de choques
		int maxChoques = 0;
		for (int x = 0; x < bolas->size(); ++x) {
			const QVector<int> &v = bolas->at(x)->acumuladoChoques;
			for (int y = 0; y < v.size(); ++y) {
				if (x == y) continue;
				maxChoques = std::max(maxChoques, v[y]);
			}
    }

		if (maxChoques == 0)
			return QBrush(Qt::white);

		//Aquí calculamos las tonanilades de rojo de manera más suave

		double ratio = static_cast<double>(choques) / maxChoques;

		int rojo  = 255;
		int verde = static_cast<int>(255 * (1.0 - ratio));
		int azul  = static_cast<int>(255 * (1.0 - ratio));

		return QBrush(QColor(rojo, verde, azul));

	}

    return QVariant();

}

void ModeloChoques::update() {
	emit dataChanged(
        index(0,0),
        index(rowCount()-1, columnCount()-1)
    );
}

DChoquesBolas::DChoquesBolas(QVector<Bola*> *lasBolas, QWidget *parent): QDialog(parent), bolas(lasBolas) {

	setupUi(this);

	setWindowTitle("Choques de las Bolas");

	QTimer *temporizador = new QTimer();
	temporizador->setSingleShot(false);
	temporizador->setInterval(200);
	connect(temporizador, SIGNAL(timeout()),
			this, SLOT(slotTemporizador()));
	temporizador->start();

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
	modeloChoques->update();
}

