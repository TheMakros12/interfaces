
#ifndef DTABLAREBOTES_H
#define DTABLAREBOTES_H
#include "ui_dtablarebotes.h"
#include "bola.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include <QAbstractTableModel>
#include <QModelIndex>
#include <QTimer>

class ModeloBolasRebotes : public QAbstractTableModel {

public:
	ModeloBolasRebotes(QVector<Bola*> *);
	QVector<Bola*> *pBolas;

	int	rowCount(const QModelIndex &parent = QModelIndex()) const;

	int	columnCount(const QModelIndex &parent = QModelIndex()) const;

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

	void update();

};

class DTablaRebotes : public QDialog, public Ui::DTablaRebotes {
Q_OBJECT

public:
	ModeloBolasRebotes *modeloRebotes;
	DTablaRebotes(QVector<Bola*> *,QWidget *parent = NULL);

    QTimer *temporizador;

public slots:
	void slotTemporizador();
	void slotRestablecerRebotes();

};

#endif 
