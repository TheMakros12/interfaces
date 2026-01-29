#ifndef DTABLAAPELLIDOS_H
#define DTABLAAPELLIDOS_H
#include "ui_dtablaapellidos.h"
#include "bola.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include <QAbstractTableModel>
#include <QModelIndex>
#include <QStringList>

class ModeloApellidos : public QAbstractTableModel {

public:
	ModeloApellidos(QVector<Bola*> *, QStringList);
	QStringList apellidos;
	QVector<Bola*> *bolas;

	int rowCount(const QModelIndex &parent = QModelIndex()) const;

	int columnCount(const QModelIndex &parent = QModelIndex()) const;

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

};

class DTablaApellidos : public QDialog, public Ui::DTablaApellidos {
Q_OBJECT

public:
	DTablaApellidos(QVector<Bola*> *, QStringList, QWidget *parent = NULL);
	ModeloApellidos *modeloApellidos;
	QVector<Bola*> *bolas;
	QStringList apellidos;

public slots:
	void slotCambioApellido();

};

#endif 
