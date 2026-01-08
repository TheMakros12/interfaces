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
	
}

void DConfiguracionBola::on_btnPararTodas_clicked() {

	for (int i = 0; i < lasBolas->size(); i++) {
		QWidget *widgetPestanya;
		WidgetDetalleBola *widgetBolaPestanya;

		widgetPestanya = tabWidget->widget(i);
		widgetBolaPestanya = qobject_cast<WidgetDetalleBola*>(widgetPestanya);

		widgetBolaPestanya->on_btnPararBola_clicked();
	}

}


void DConfiguracionBola::on_cbActivarBotones_toggled(bool activo) {

	for (int i = 0; i < lasBolas->size(); i++) {
		qobject_cast<WidgetDetalleBola*>(tabWidget->widget(i)->btnPararBola->setEnabled(activo));
	}

}

