#ifndef DCONFIGURACIONBOLA_H
#define DCONFIGURACIONBOLA_H
#include "ui_dconfiguracionbola.h"
#include "bola.h"
#include "widgetdetallebola.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include <QTimer>

class DConfiguracionBola : public QDialog, public Ui::DConfiguracionBola {
Q_OBJECT

public:
	DConfiguracionBola(QVector<Bola*> *, QWidget *parent = NULL);
	QVector<Bola*> *lasBolas;
	void actualizarTabs();

public slots:
	void slotTemporizador();
	void on_btnPararTodas_clicked();
	void on_cbActivarBotones_toggled(bool);
	void on_btnMoverTodas_clicked();

};

#endif 
