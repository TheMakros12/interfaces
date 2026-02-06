#include "dtablaassays.h"
#include <QDebug>

ModeloAssays::ModeloAssays(QVector<Assay> losAssays) {

	assays = losAssays;

}

int ModeloAssays::rowCount(const QModelIndex &parent) const {

	return assays.size();

}

int	ModeloAssays::columnCount(const QModelIndex &parent) const {

	return 2;
}

QVariant ModeloAssays::headerData(int section, Qt::Orientation orientation, int role) const {

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
				case 0: return "Assay_Chembl_Id";
				case 1: return "Description";
			}
		}

		if ( orientation == Qt::Vertical ) {
			return assays.at(section).assay_chembl_id;
		}
	}

	return QVariant();

}

QVariant ModeloAssays::data(const QModelIndex &index, int role) const {

	if ( role == Qt::TextAlignmentRole )
		return Qt::AlignCenter;

	if ( role != Qt::DisplayRole )
		return QVariant();

	int fila = index.row();
	int columna = index.column();
	Assay assay= assays.at(fila);

	QString resultado;
	switch (columna) {
		case 0: resultado = QString(assay.assay_chembl_id); break;
		case 1: resultado = QString(assay.description); break;
	};

	return QVariant(resultado);

}

Qt::ItemFlags ModeloAssays::flags(const QModelIndex &index) const {
	return Qt::ItemIsSelectable | QAbstractTableModel::flags(index);
}

DTablaAssays::DTablaAssays(QVector<Assay> losAssays, QWidget *parent): QDialog(parent), assays(losAssays) {

	setupUi(this);

	modeloAssays = new ModeloAssays(assays);
	tablaAssays->setModel(modeloAssays);

	connect(tablaAssays, &QTableView::clicked,
        this, &DTablaAssays::slotDDocuemnt);

}

void DTablaAssays::slotDAssay(const QModelIndex &index) {

	int fila = index.row();

	Assay assay = assays.at(fila);

	DialogoAssay *dAssay = new DialogoAssay(assay, this);
	dAssay->show();

}

void DTablaAssays::slotDDocuemnt(const QModelIndex &index) {

	int fila = index.row();

	Assay assay = assays.at(fila);
	QString id = assay.document_chembl_id;

	DDocument *dDocument = new DDocument(id);
	dDocument->show();

}
