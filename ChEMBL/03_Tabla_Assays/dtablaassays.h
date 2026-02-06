#ifndef DTABLAASSAYS_H
#define DTABLAASSAYS_H
#include "ui_dtablaassays.h"
#include "jsonassays.h"
#include "dialogoassay.h"
#include "ddocument.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include <QAbstractTableModel>
#include <QModelIndex>

class ModeloAssays : public QAbstractTableModel {

public:
	ModeloAssays(QVector<Assay> );
	QVector<Assay> assays;

	int	rowCount(const QModelIndex &parent = QModelIndex()) const;

	int	columnCount(const QModelIndex &parent = QModelIndex()) const;

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

	Qt::ItemFlags flags(const QModelIndex &index) const;

};

class DTablaAssays : public QDialog, public Ui::DTablaAssays {
Q_OBJECT

public:
	DTablaAssays(QVector<Assay>, QWidget *parent = NULL);
	ModeloAssays *modeloAssays;
	QVector<Assay> assays;

public slots:
	void slotDAssay(const QModelIndex &index);
	void slotDDocuemnt(const QModelIndex &index);

};

#endif 
