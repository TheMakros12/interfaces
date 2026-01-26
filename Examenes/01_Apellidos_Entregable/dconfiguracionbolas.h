
#ifndef DCONFIGURACIONBOLAS_H
#define DCONFIGURACIONBOLAS_H
#include "ui_dconfiguracionbolas.h"
#include "widgetdetallebola.h"
#include "bola.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>

class DConfiguracionBolas : public QDialog, public Ui::DConfiguracionBolas {
Q_OBJECT

public:
	DConfiguracionBolas(QVector<Bola* > *, QWidget *parent = NULL);
	QVector<Bola*> * lasBolas;
public slots:
	void slotEjemplo();
	void on_bPararTodas_clicked();
	void on_chActivoParar_toggled(bool);

};

#endif 
