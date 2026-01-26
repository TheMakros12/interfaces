
#ifndef DTABLAREBOTES_H
#define DTABLAREBOTES_H
#include "ui_dtablarebotes.h"
#include "bola.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include <QModelIndex>
#include <QAbstractTableModel>

class ModeloBolasRebotes;

class DTablaRebotes : public QDialog, public Ui::DTablaRebotes {
Q_OBJECT

public:
	DTablaRebotes(QVector<Bola*>*, QWidget *parent = NULL);
	QVector<Bola*> * pBolas;

	ModeloBolasRebotes * modelo;


public slots:
	void slotEjemplo();
	void slotTemporizador();

};


class ModeloBolasRebotes : public QAbstractTableModel {
Q_OBJECT


public:
	ModeloBolasRebotes(QVector<Bola * > *);
	QVector<Bola*> * pBolas;

	QVariant data(const QModelIndex &index, int role ) const ;
	int	rowCount(const QModelIndex &parent) const ;
	int	columnCount(const QModelIndex &parent) const ;

	void actualiza();

};


#endif 
