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

QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

	void update();

};

class DTablaBolas : public QDialog, public Ui::DTablaBolas {
Q_OBJECT

public:
	DTablaBolas(QVector<Bola*> *, QWidget *parent = NULL);

	ModeloBolas *modeloBolas;
	QTimer *temporizador;

public slots:
	void slotTemporizador();

};

#endif 
