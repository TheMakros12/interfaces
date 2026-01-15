#ifndef DTABLABOLAS_H
#define DTABLABOLAS_H
#include "ui_dtablabolas.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include <QAbstractTableModel>
#include <QModelIndex>
#include <QTimer>

#include "bola.h"

class ModeloBolas : public QAbstractTableModel {

public:
	ModeloBolas(QVector<Bola*> *);
	QVector<Bola*> *pBolas;

	int	rowCount(const QModelIndex &parent = QModelIndex()) const;

	int	columnCount(const QModelIndex &parent = QModelIndex()) const;

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

	Qt::ItemFlags flags(const QModelIndex &index) const;

	void update();

};

class DTablaBolas : public QDialog, public Ui::DTablaBolas {
Q_OBJECT

public:
	DTablaBolas(QVector<Bola*> *, QWidget *parent = NULL);

	ModeloBolas *modeloBolas;
	QTimer *temporizador;

	void ajustarTamano();

public slots:
	void slotTemporizador();

};

#endif 
