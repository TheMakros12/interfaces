#ifndef DIALOGOASSAY_H
#define DIALOGOASSAY_H
#include "ui_dialogoassay.h"
#include "jsonassay.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>

class DialogoAssay : public QDialog, public Ui::DialogoAssay {
Q_OBJECT

public:
	DialogoAssay(Assay, QWidget *parent = NULL);
	Assay miAssay;

public slots:
	void slotEjemplo();

};

#endif 
