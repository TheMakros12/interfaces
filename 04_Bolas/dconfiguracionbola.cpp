#include "dconfiguracionbola.h"
#include <QDebug>

DConfiguracionBola::DConfiguracionBola(QVector<Bola*> *bolasPasadas, QWidget *parent): QDialog(parent), lasBolas(bolasPasadas) {

	setupUi(this);

	setWindowTitle("Detalle de la Bola");

	tabWidget->clear();

	for (int i = 0; i < lasBolas->size(); i++) {
		tabWidget->addTab(new WidgetDetalleBola(lasBolas->at(i)),
						  lasBolas->at(i)->nombre);
	}

	cbActivarBotones->setChecked(true);

	adjustSize();
	
}

void DConfiguracionBola::on_btnPararTodas_clicked() {

	for (int i = 0; i < lasBolas->size(); i++)
		qobject_cast<WidgetDetalleBola*>(tabWidget->widget(i))->btnPararBola->animateClick(100);

}

void DConfiguracionBola::on_cbActivarBotones_toggled(bool activo) {

	for (int i = 0; i < lasBolas->size(); i++)
		qobject_cast<WidgetDetalleBola*>(tabWidget->widget(i))->btnPararBola->setEnabled(activo);

	btnPararTodas->setEnabled(activo);

}

void DConfiguracionBola::on_btnMoverTodas_clicked() {

	for (int i = 0; i < lasBolas->size(); i++)
		qobject_cast<WidgetDetalleBola*>(tabWidget->widget(i))->btnMoverBola->animateClick(100);
}
