
#include "dconfiguracionbolas.h"
#include <QDebug>
#include <QPushButton>
#include <QLabel>

DConfiguracionBolas::DConfiguracionBolas(QVector<Bola*> * bolasPasadas, QWidget *parent):
	QDialog(parent),lasBolas(bolasPasadas){
		setupUi(this);

		lasBolas = bolasPasadas;

		tabWidget->clear();

		for (int i=0 ; i < lasBolas->length();i++)
			tabWidget->addTab(new WidgetDetalleBola(lasBolas->at(i)),
							  lasBolas->at(i)->nombre);
	
}

void DConfiguracionBolas::on_bPararTodas_clicked(){
	for(int i=0; i < tabWidget->count(); i++){
		QWidget * widget = tabWidget->widget(i);
		WidgetDetalleBola * detalle;
		detalle = qobject_cast<WidgetDetalleBola*>(widget);
		detalle->bParar->animateClick(100);
	}
}

void DConfiguracionBolas::on_chActivoParar_toggled(bool activo ){
	for(int i=0; i < tabWidget->count(); i++)
		qobject_cast<WidgetDetalleBola*>(tabWidget->widget(i))->bParar->setEnabled(activo);



}

void DConfiguracionBolas::slotEjemplo(){




}


