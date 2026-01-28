#include "dtablaapellidos.h"
#include <QDebug>

ModeloApellidos::ModeloApellidos(QVector<Bola*> *bolasPasadas, QStringList apellidosPasados): bolas(bolasPasadas), apellidos(apellidosPasados) {

}

int ModeloApellidos::rowCount(const QModelIndex &parent) const {

        return bolas->size();
}

int ModeloApellidos::columnCount(const QModelIndex &parent) const {

        return apellidos.length();

}

QVariant ModeloApellidos::headerData(int section, Qt::Orientation orientation, int role) const {

        if ( role == Qt::TextAlignmentRole )
                return Qt::AlignCenter;

        if ( role == Qt::FontRole ) {
                QFont font;
                font.setBold(true);
                return font;
        }

        if ( role == Qt::DisplayRole ) {

                if ( orientation == Qt::Horizontal ) {
					return apellidos.at(section);
                }

                if ( orientation == Qt::Vertical ) {
                        return bolas->at(section)->nombre;
                }
        }

        return QVariant();

}

QVariant ModeloApellidos::data(const QModelIndex &index, int role) const {

	if ( role == Qt::TextAlignmentRole )
		return Qt::AlignCenter;

	if ( role != Qt::DisplayRole )
		return QVariant();

	int fila = index.row();
	int columna = index.column();
	Bola *bola = bolas->at(fila);
    QString apellidoColumna = apellidos.at(columna);

    if (apellidoColumna == bola->apellido_1)
            return QString("1");

    if (apellidoColumna == bola->apellido_2)
        return QString("2");

	return QVariant();

}

void ModeloApellidos::refrescarFila(int fila) {
        QModelIndex izquierda = index(fila, 0);
        QModelIndex derecha   = index(fila, columnCount() - 1);
        emit dataChanged(izquierda, derecha);
}

DTablaApellidos::DTablaApellidos(QVector<Bola*> *bolasPasadas, QStringList apellidosPasados, QWidget *parent): QDialog(parent), bolas(bolasPasadas), apellidos(apellidosPasados) {

	setupUi(this);

	setWindowTitle("Tabla Apellidos");

	modeloApellidos = new ModeloApellidos(bolas, apellidos);
	tablaApellidos->setModel(modeloApellidos);
	
}


void DTablaApellidos::slotEjemplo(){

}

