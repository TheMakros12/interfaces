#ifndef DTABLAREBOTEBOLAS_H
#define DTABLAREBOTEBOLAS_H
#include "ui_dtablarebotebolas.h"
#include "bola.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include <QAbstractTableModel>
#include <QModelIndex>
#include <QTimer>
#include <QColor>
#include <algorithm>
#include <QFont>

class ModeloRebotes : public QAbstractTableModel {

public:
	ModeloRebotes(QVector<Bola*> *, QVector<QVector<int>> *, QObject *parent = nullptr);
	QVector<Bola*> *pBolas;
	QVector<QVector<int>> *rebotesBolas;

	int	rowCount(const QModelIndex &parent = QModelIndex()) const;

	int	columnCount(const QModelIndex &parent = QModelIndex()) const;

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

	void update();

};

class DTablaReboteBolas : public QDialog, public Ui::DTablaReboteBolas {
Q_OBJECT

public:
	DTablaReboteBolas(QVector<Bola*> *, QVector<QVector<int>> *, QWidget *parent = NULL);
	QVector<Bola*> *pBolas;
	ModeloRebotes *modeloRebotes;
	QVector<QVector<int>> *rebotesBolas;

	QTimer *temporizador;

public slots:
	void slotTemporizador();

};

#endif 
