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

	if ( role == Qt::DisplayRole ){
		if ( orientation == Qt::Horizontal ) {
			switch ( section ) {
				case 0: return "Pos X";
				case 1: return "Pos Y";
				case 2: return "Vel X";
				case 3: return "Vel Y";
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
	}

	if (orientation == Qt::Vertical &&
		(role == Qt::BackgroundRole || role == Qt::ForegroundRole)) {

		Bola *laBola = nullptr;

	if (bolaJugador && *bolaJugador) {
		laBola = (section == 0)
		? *bolaJugador
		: lasBolas->at(section - 1);
	} else {
		laBola = lasBolas->at(section);
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

	modelo->actualizarDatos();

	tablaBolas->resizeRowsToContents();
	tablaBolas->resizeColumnsToContents();

	int totalWidth = tablaBolas->verticalHeader()->width();
	for (int c = 0; c < modelo->columnCount(); ++c)
		totalWidth += tablaBolas->columnWidth(c);
	totalWidth += 2 * tablaBolas->frameWidth() + 20;
	tablaBolas->setMinimumWidth(totalWidth);

	int totalHeight = tablaBolas->horizontalHeader()->height();
	for (int r = 0; r < modelo->rowCount(); ++r)
		totalHeight += tablaBolas->rowHeight(r);
	totalHeight += 2 * tablaBolas->frameWidth();
	tablaBolas->setMinimumHeight(totalHeight);

	adjustSize();
}

/*************************DTablaBolas***************************/
