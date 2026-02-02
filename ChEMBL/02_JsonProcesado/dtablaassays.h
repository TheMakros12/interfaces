#ifndef DTABLAASSAYS_H
#define DTABLAASSAYS_H
#include "ui_dtablaassays.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include <QAbstractTableModel>

class ModeloAssays : public QAbstractTableModel {

public:
	ModeloAssays(QVector<Assay> *);
	QVector<Assay> *assays;

	int	rowCount(const QModelIndex &parent = QModelIndex()) const;

	int	columnCount(const QModelIndex &parent = QModelIndex()) const;

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

};

class DTablaAssays : public QDialog, public Ui::DTablaAssays {
Q_OBJECT

public:
	DTablaAssays(QWidget *parent = NULL);

public slots:
	void slotEjemplo();

};

#endif 
