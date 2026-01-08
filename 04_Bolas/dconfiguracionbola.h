#ifndef DCONFIGURACIONBOLA_H
#define DCONFIGURACIONBOLA_H
#include "ui_dconfiguracionbola.h"
#include "bola.h"
#include "widgetdetallebola.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>

class DConfiguracionBola : public QDialog, public Ui::DConfiguracionBola {
Q_OBJECT

public:
	DConfiguracionBola(QVector<Bola*> *, QWidget *parent = NULL);
	QVector<Bola*> *lasBolas;

public slots:
	void on_btnPararTodas_clicked();
	void on_cbActivarBotones_toggled(bool);

};

#endif 
