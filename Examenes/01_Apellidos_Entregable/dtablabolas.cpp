
#include "dtablabolas.h"
#include <QDebug>

ModeloBolas::ModeloBolas(QVector<Bola*> * lasBolas ){
	pBolas = lasBolas;
}


int	ModeloBolas::rowCount(const QModelIndex &parent) const {
	return pBolas->size() ;
}

int	ModeloBolas::columnCount(const QModelIndex &parent) const {
	return 4;
}

QVariant ModeloBolas::data(const QModelIndex &index, int role ) const {

	if (role != Qt::DisplayRole)
		return QVariant();

	int indice = index.row();
	int columna = index.column();

	Bola *bola = pBolas->at(indice);

	QVariant dato ;

	if ( columna == 0)  // posX
		dato = QVariant(bola->posX);
	if ( columna == 1)  // posX
		dato = QVariant(bola->posY);
	if ( columna == 2)  // posX
		dato = QVariant(bola->velX);
	if ( columna == 3)  // posX
		dato = QVariant(bola->velY);

	return dato;


}

Qt::ItemFlags ModeloBolas::flags(const QModelIndex &index) const {

	Qt::ItemFlags misFlags;

	misFlags = Qt::ItemIsEditable | QAbstractTableModel::flags(index) ;

	return misFlags;

}

QVariant ModeloBolas::headerData(int section, Qt::Orientation orientation, int role ) const {

	QStringList columnNames = {"posicion x", "posiciony", "velX", "velY"};

	if (role == Qt::DisplayRole  && orientation == Qt::Vertical)
		return QVariant(pBolas->at(section)->nombre);

	if (role == Qt::BackgroundRole && orientation == Qt::Vertical)
		return QVariant(pBolas->at(section)->color);

	if (role == Qt::DisplayRole) return QVariant(columnNames.at(section));

	return QVariant();



};


bool ModeloBolas::setData(	const QModelIndex  & indice,
					const QVariant & value,
					int role  )  {

			if (role != Qt::EditRole)
				return false;

			Bola * laBola = pBolas->at(indice.row());

			bool resultado = false;
			float valor = value.toFloat( &resultado);

			if ( ! resultado) return false;

			switch ( indice.column()){
			case 0:
				laBola->posX = valor; break;
			case 1:
				laBola->posY = valor ; break;
			case 2:
				laBola->velX = valor;	break;
			case 3:
				laBola->velY = valor;	break;
	};

	QModelIndex ini = index(0,0);
	QModelIndex fin = index(pBolas->size()- 1 ,3);
	emit dataChanged(ini,fin);

	return true;
}



DTablaBolas::DTablaBolas(QVector<Bola*> *pBolas , QWidget *parent): QDialog(parent){
		setupUi(this);


		ModeloBolas *modelo = new ModeloBolas(pBolas);
		vistaBolas->setModel(modelo);

	
}


void DTablaBolas::slotEjemplo(){

}

