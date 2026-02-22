#ifndef DMENUBOLAS_H
#define DMENUBOLAS_H
#include "ui_dmenubolas.h"
#include "bola.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>

class DMenuBolas : public QDialog, public Ui::DMenuBolas {
Q_OBJECT

public:
	DMenuBolas(Bola *, QWidget *parent = NULL);
	Bola *bola;

public slots:
	void slotEjemplo();

};

#endif 
