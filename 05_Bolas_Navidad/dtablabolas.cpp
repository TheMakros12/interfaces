#include "dtablabolas.h"
#include <QDebug>

ModeloTabla::ModeloTabla(QVector<Bola*> *bolasPasadas, QObject *parent) {

	lasBolas = bolasPasadas;

}

int	ModeloTabla::rowCount(const QModelIndex &parent) const {

	return lasBolas->size();

}

int	ModeloTabla::columnCount(const QModelIndex &parent) const {

	return 4;

}


QVariant ModeloTabla::headerData(int section, Qt::Orientation orientation, int role) const {

	if ( role != Qt::DisplayRole )
			return QVariant();

	QString cadena;
	if ( orientation == Qt::Horizontal ) {
		switch (section) {
			case 0: cadena = "Pos X"; break;
			case 1: cadena = "Pos Y"; break;
			case 2: cadena = "Vel X"; break;
			case 3: cadena = "Vel Y";break;
		}
	}

	if ( orientation == Qt::Vertical )
		cadena = lasBolas->at(section)->nombre;

	return QVariant(cadena);

}

QVariant ModeloTabla::data(const QModelIndex &index, int role) const {

	if ( role != Qt::DisplayRole )
		return QVariant();

	int fila = index.row();
	int columna = index.column();
	Bola *laBola = lasBolas->at(fila);

	QString cadena;

	switch ( columna ) {
		case 0:
			cadena = QString::number(laBola->posX);
			break;
		case 1:
			cadena = QString::number(laBola->posY);
			break;
		case 2:
			cadena = QString::number(laBola->velX);
			break;
		case 3:
			cadena = QString::number(laBola->velY);
			break;
	};

	return QVariant(cadena);

}

bool ModeloTabla::setData(const QModelIndex &index, const QVariant &value, int role) {

	if ( role != Qt::EditRole ) return false;

	Bola *laBola = lasBolas->at(index.row());
	bool ok;
	float valor = value.toString().toFloat(&ok);
	if ( !ok ) return false;

	switch ( index.column() ) {
		case 0:
			laBola->posX = valor; break;
		case 1:
			laBola->posY = valor; break;
		case 2:
			laBola->velX = valor; break;
		case 3:
			laBola->velY = valor; break;
	};

	emit dataChanged(index, index);
	return true;

}

Qt::ItemFlags ModeloTabla::flags(const QModelIndex &index) const {

	return Qt::ItemIsEditable | QAbstractTableModel::flags(index);

}

void ModeloTabla::actualizarDatos() {

	emit layoutChanged();

}

SpinBoxDelegate::SpinBoxDelegate(QObject *parent) : QStyledItemDelegate(parent) {

}

QWidget *SpinBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const {

	QDoubleSpinBox *editor = new QDoubleSpinBox(parent);
	editor->setMinimum(-10);
	editor->setMaximum(1024);
	return editor;

}

void SpinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {

	float valor = index.model()->data(index, Qt::DisplayRole).toFloat();

	QDoubleSpinBox *spinBox = qobject_cast<QDoubleSpinBox*>(editor);
	spinBox->setValue(valor);

}

void SpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {

	QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
	spinBox->interpretText();
	float valor = spinBox->value();

	model->setData(index, QVariant(valor), Qt::EditRole);

}

void SpinBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const {

	editor->setGeometry(option.rect);

}

DTablaBolas::DTablaBolas(QVector<Bola*> *bolasPasadas, QWidget *parent): QDialog(parent), lasBolas(bolasPasadas) {

	setupUi(this);

	setWindowTitle("Tabla de las Bolas");

	modelo = new ModeloTabla(lasBolas);
	tablaBolas->setModel(modelo);
	tablaBolas->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	tablaBolas->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	tablaBolas->setItemDelegate(new SpinBoxDelegate());

	QTimer *temporizaddor = new QTimer();
	temporizaddor->setInterval(10);
	temporizaddor->setSingleShot(false);
	temporizaddor->start();

	connect(temporizaddor, SIGNAL(timeout()),
			this, SLOT(slotTemporizador()));
	
}

void DTablaBolas::slotTemporizador(){

	modelo->actualizarDatos();

}

