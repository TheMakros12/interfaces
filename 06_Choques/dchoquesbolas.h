
#ifndef DCHOQUESBOLAS_H
#define DCHOQUESBOLAS_H
#include "ui_dchoquesbolas.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>

class DChoquesBolas : public QDialog, public Ui::DChoquesBolas {
Q_OBJECT

public:
	DChoquesBolas(QWidget *parent = NULL);

public slots:
	void slotEjemplo();

};

#endif 
