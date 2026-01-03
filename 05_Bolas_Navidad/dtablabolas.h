#ifndef TABLABOLAS_H
#define TABLABOLAS_H
#include "ui_dtablabolas.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include <QAbstractTableModel>
#include <QModelIndex>
#include <QTimer>
#include <QDoubleSpinBox>
#include <QStyledItemDelegate>
#include <QStyleOptionViewItem>
#include <QObject>

#include "bola.h"

class ModeloTabla : public QAbstractTableModel {

public:
	ModeloTabla(QVector<Bola*> *, QObject *parent = nullptr);
	QVector<Bola*> *lasBolas;

	int	rowCount(const QModelIndex &parent = QModelIndex()) const;
	int	columnCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
	Qt::ItemFlags flags(const QModelIndex &index) const;

	void actualizarDatos();

};

class SpinBoxDelegate : public QStyledItemDelegate {
Q_OBJECT

public:
	SpinBoxDelegate(QObject *parent = 0);

	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

	void setEditorData(QWidget *editor, const QModelIndex &index) const override;

	void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

	void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;


};

class DTablaBolas : public QDialog, public Ui::DTablaBolas {
Q_OBJECT

public:
	DTablaBolas(QVector<Bola*> *, QWidget *parent = NULL);
	QVector<Bola*> *lasBolas;
	ModeloTabla *modelo;

public slots:
	void slotTemporizador();

};

#endif 
