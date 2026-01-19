#ifndef DREBOTESENTREBOLAS_H
#define DREBOTESENTREBOLAS_H
#include "ui_drebotesentrebolas.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>

class DRebotesEntreBolas : public QDialog, public Ui::DRebotesEntreBolas {
Q_OBJECT

public:
	DRebotesEntreBolas(QWidget *parent = NULL);

public slots:
	void slotEjemplo();

};

#endif 
