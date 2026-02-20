#ifndef DMENUBOLAS_H
#define DMENUBOLAS_H
#include "ui_dmenubolas.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>

class DMenuBolas : public QDialog, public Ui::DMenuBolas {
Q_OBJECT

public:
	DMenuBolas(QString, QWidget *parent = NULL);

public slots:
	void slotEjemplo();

};

#endif 
