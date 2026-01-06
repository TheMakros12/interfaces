#include "dtablabolas.h"
#include <QDebug>

/************************ModeloTabla***************************/

ModeloTabla::ModeloTabla(QVector<Bola*> *bolasPasadas, Bola **bolaEspecial, QObject *parent) : lasBolas(bolasPasadas), bolaJugador(bolaEspecial) {

}

int	ModeloTabla::rowCount(const QModelIndex &parent) const {

	int extra = (bolaJugador && *bolaJugador) ? 1 : 0;
	return lasBolas->size() + extra;

}

int	ModeloTabla::columnCount(const QModelIndex &parent) const {

	return 4;

}


QVariant ModeloTabla::headerData(int section, Qt::Orientation orientation, int role) const {

	if ( role != Qt::DisplayRole )
			return QVariant();

	QString cadena;
	if ( orientation == Qt::Horizontal ) {
		switch ( section ) {
			case 0: cadena = "Pos X"; break;
			case 1: cadena = "Pos Y"; break;
			case 2: cadena = "Vel X"; break;
			case 3: cadena = "Vel Y"; break;
		};
	}

	if ( orientation == Qt::Vertical ) {
		if ( bolaJugador && *bolaJugador ) {
			if (section == 0) return "Jugador";
			else return lasBolas->at(section - 1)->nombre;
		} else {
			return lasBolas->at(section)->nombre;
		}
	}

	return QVariant(cadena);

}

QVariant ModeloTabla::data(const QModelIndex &index, int role) const {

	int fila = index.row();
	int columna = index.column();
	Bola *laBola = nullptr;

	if ( bolaJugador && *bolaJugador ) {
		if ( fila == 0 ) {
			laBola = *bolaJugador;
		} else {
			laBola = lasBolas->at(fila - 1);
		}
	} else {
		laBola = lasBolas->at(fila);
	}

	if ( role == Qt::DisplayRole ) {
		switch (columna) {
			case 0: return laBola->posX;
			case 1: return laBola->posY;
			case 2: return laBola->velX;
			case 3: return laBola->velY;
		}
	}

	if ( role == Qt::DecorationRole ) {

		if ( columna == 0 || columna == 1 )
			return laBola->color;

		if ( columna == 2 )
			return laBola->velX >= 0 ? QColor(Qt::green) : QColor(Qt::red);

		if ( columna == 3 )
			return laBola->velY >= 0 ? QColor(Qt::green) : QColor(Qt::red);

	}

	return QVariant();

}

bool ModeloTabla::setData(const QModelIndex &index, const QVariant &value, int role) {

	if ( role != Qt::EditRole ) return false;

	Bola *laBola = lasBolas->at(index.row());
	bool ok;
	float valor = value.toString().toFloat(&ok);
	if ( !ok ) return false;

	switch ( index.column() ) {
		case 0: laBola->posX = valor; break;
		case 1: laBola->posY = valor; break;
		case 2: laBola->velX = valor; break;
		case 3: laBola->velY = valor; break;
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

/************************ModeloTabla***************************/


/***********************SpinBoxDelegate*************************/

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

/***********************SpinBoxDelegate*************************/


/*************************DTablaBolas***************************/

DTablaBolas::DTablaBolas(QVector<Bola*> *bolasPasadas, Bola **bolaEspecial, QWidget *parent): QDialog(parent), lasBolas(bolasPasadas) {

	setupUi(this);

	setWindowTitle("Tabla de las Bolas");

	modelo = new ModeloTabla(lasBolas, bolaEspecial);
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

void DTablaBolas::slotTemporizador() {
	// Actualizar los datos del modelo
	modelo->actualizarDatos();

	// Ajustar el tamaño de filas y columnas automáticamente
	tablaBolas->resizeRowsToContents();
	tablaBolas->resizeColumnsToContents();

	// Calcular ancho mínimo: suma de todas las columnas + margen + frame
	int totalWidth = tablaBolas->verticalHeader()->width(); // ancho del header vertical
	for (int c = 0; c < modelo->columnCount(); ++c)
		totalWidth += tablaBolas->columnWidth(c);
	totalWidth += 2 * tablaBolas->frameWidth() + 20; // margen extra
	tablaBolas->setMinimumWidth(totalWidth);

	// Calcular altura mínima: suma de todas las filas + header horizontal + frame
	int totalHeight = tablaBolas->horizontalHeader()->height();
	for (int r = 0; r < modelo->rowCount(); ++r)
		totalHeight += tablaBolas->rowHeight(r);
	totalHeight += 2 * tablaBolas->frameWidth();
	tablaBolas->setMinimumHeight(totalHeight);

	// Ajustar el tamaño del diálogo al contenido de la tabla
	adjustSize();
}

/*************************DTablaBolas***************************/
