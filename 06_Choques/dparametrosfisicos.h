#ifndef DPARAMETROSFISICOS_H
#define DPARAMETROSFISICOS_H
#include "ui_dparametrosfisicos.h"
#include "bola.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>

class DParametrosFisicos : public QDialog, public Ui::DParametrosFisicos {
Q_OBJECT

public:
	DParametrosFisicos(QWidget *parent = NULL);

public slots:
	void slotEjemplo();

};

#endif 
