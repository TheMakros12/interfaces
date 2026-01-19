#include "dconfiguracionbola.h"
#include <QDebug>

DConfiguracionBola::DConfiguracionBola(QVector<Bola*> *bolasPasadas, QWidget *parent): QDialog(parent), lasBolas(bolasPasadas) {

	setupUi(this);

	setWindowTitle("Detalle de la Bola");

	tabWidget->clear();

	QTimer *temporizador = new QTimer(this);
	temporizador->setInterval(100);
	temporizador->setSingleShot(false);
	connect(temporizador, SIGNAL(timeout()),
			this, SLOT(slotTemporizador()));
	temporizador->start();

	actualizarTabs();

	cbActivarBotones->setChecked(true);

	adjustSize();
	
}

void DConfiguracionBola::actualizarTabs() {

	for (int i = tabWidget->count() - 1; i >= 0; --i) {
		WidgetDetalleBola *w =
		qobject_cast<WidgetDetalleBola*>(tabWidget->widget(i));

		if (!w || !w->laBola || w->laBola->vidas <= 0) {

			if (w && w->laBola) {
				lasBolas->removeOne(w->laBola);
			}

			QWidget *pagina = tabWidget->widget(i);
			tabWidget->removeTab(i);
			delete pagina;
		}
	}

	// 2. Crear pestañas para bolas nuevas
	for (int idx = 0; idx < lasBolas->size(); ++idx) {
		Bola *b = lasBolas->at(idx);
		bool existe = false;

		for (int i = 0; i < tabWidget->count(); ++i) {
			WidgetDetalleBola *w =
			qobject_cast<WidgetDetalleBola*>(tabWidget->widget(i));

			if (w && w->laBola == b) {
				existe = true;
				break;
			}
		}

		if (!existe) {
			tabWidget->addTab(
				new WidgetDetalleBola(b),
							  b->nombre
			);
		}
	}

}

void DConfiguracionBola::slotTemporizador() {

	actualizarTabs();

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
