#ifndef DPOSICIONBOLA_H
#define DPOSICIONBOLA_H
#include "ui_dposicionbola.h"
#include "bola.h"
#include "widgetposicionbola.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>

class DPosicionBola : public QDialog, public Ui::DPosicionBola {
Q_OBJECT

public:
	DPosicionBola(QVector<Bola*> *, QWidget *parent = NULL);
	QVector<Bola*> *lasBolas;

public slots:
	void slotEjemplo();

};

#endif 
