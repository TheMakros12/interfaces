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

/************************ModeloTabla***************************/

class ModeloBolasRebotes : public QAbstractTableModel {

public:
	ModeloBolasRebotes(QVector<Bola*> *,  Bola **bolaJugador = nullptr, QObject *parent = nullptr);
	QVector<Bola*> *pBolas;
	Bola **bolaJugador = nullptr;

	int	rowCount(const QModelIndex &parent = QModelIndex()) const;

	int	columnCount(const QModelIndex &parent = QModelIndex()) const;

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

	void update();

};

/************************ModeloTabla***************************/

/************************DTablaRebotes***************************/

class DTablaRebotes : public QDialog, public Ui::DTablaRebotes {
	Q_OBJECT

public:
	DTablaRebotes(QVector<Bola*> *, Bola **bolaEspecial = nullptr, QWidget *parent = NULL);
	QVector<Bola*> *pBolas;
	ModeloBolasRebotes *modeloRebotes;

	QTimer *temporizador;

public slots:
	void slotTemporizador();
	void slotRestablecerRebotes();

};

/************************DTablaRebotes***************************/

#endif
