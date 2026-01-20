#ifndef DCHOQUESBOLAS_H
#define DCHOQUESBOLAS_H
#include "ui_dchoquesbolas.h"
#include "bola.h"
#include "widgetchoque.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include <QTimer>

class DChoquesBolas : public QDialog, public Ui::DChoquesBolas {
Q_OBJECT

public:
	DChoquesBolas(QVector<Bola*> *,QWidget *parent = NULL);
	QVector<Bola*> *bolas;

public slots:
	void slotTemporizador();

};

#endif 
