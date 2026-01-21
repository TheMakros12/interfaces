
#ifndef DCHOQUESBOLAS_H
#define DCHOQUESBOLAS_H
#include "ui_dchoquesbolas.h"
#include "bola.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include <QAbstractTableModel>
#include <QModelIndex>
#include <QTimer>

class ModeloChoques : public QAbstractTableModel {

public:
	ModeloChoques(QVector<Bola*> *);
	QVector<Bola*> *bolas;

	int	rowCount(const QModelIndex &parent = QModelIndex()) const;

	int	columnCount(const QModelIndex &parent = QModelIndex()) const;

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

};

class DChoquesBolas : public QDialog, public Ui::DChoquesBolas {
Q_OBJECT

public:
	DChoquesBolas(QVector<Bola*> *, QWidget *parent = NULL);

	ModeloChoques *modeloChoques;
	QVector<Bola*> *bolas;
	QTimer *temporizador;

public slots:
	void slotTemporizador();

};

#endif 
