
#ifndef DTABLABOLAS_H
#define DTABLABOLAS_H
#include "ui_dtablabolas.h"
#include "bola.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include <QAbstractTableModel>
#include <QModelIndex>


class ModeloBolas : public QAbstractTableModel {

public:
	ModeloBolas(QVector<Bola*> * );
	QVector<Bola * > * pBolas;

int	rowCount(const QModelIndex &parent = QModelIndex()) const;
int	columnCount(const QModelIndex &parent = QModelIndex()) const;
QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const ;


	Qt::ItemFlags flags(const QModelIndex &index) const;


	bool setData(	const QModelIndex &,
					const QVariant &,
					int role = Qt::EditRole )  ;

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const ;

};

class DTablaBolas : public QDialog, public Ui::DTablaBolas {
Q_OBJECT
public:
	DTablaBolas(QVector<Bola*> *, QWidget *parent = NULL);

public slots:
	void slotEjemplo();

};

#endif 
