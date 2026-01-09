#include "dcontrolbolas.h"
#include <QDebug>

DControlBolas::DControlBolas(QVector<Bola*> *bolasPasadas, QWidget *parent): QDialog(parent), bolas(bolasPasadas){

	setupUi(this);

	setWindowTitle("Control de las Bolas");

	tabBolas->clear();
	cbTamanyoBolas->setCurrentIndex(1);

	connect(btnPararTodas, SIGNAL(clicked()),
			this, SLOT(slotPararTodas()));

	connect(btnMoverTodas, SIGNAL(clicked()),
			this, SLOT(slotMoverTodas()));

	connect(cbTamanyoBolas, SIGNAL(activated(int)),
			this, SLOT(slotCambiarTamanyoBolas(int)));

	temporizador = new QTimer(this);
	temporizador->setInterval(100);
	temporizador->setSingleShot(false);
	connect(temporizador, SIGNAL(timeout()),
			this, SLOT(slotActualizarTabs()));
	temporizador->start();

	slotActualizarTabs();

	adjustSize();
	
}

void DControlBolas::slotPararTodas(){

	for (int i = 0; i < tabBolas->count(); i++)
		qobject_cast<WidgetBola*>(tabBolas->widget(i))->slotPararBola();

}

void DControlBolas::slotMoverTodas(){

	for (int i = 0; i < tabBolas->count(); i++)
		qobject_cast<WidgetBola*>(tabBolas->widget(i))->slotMoverBola();

}

void DControlBolas::slotActualizarTabs(){
	for (int i = tabBolas->count() - 1; i >= 0; --i) {
		WidgetBola *w = qobject_cast<WidgetBola*>(tabBolas->widget(i));
		if (!w || !w->bola()) {
			QWidget *pagina = tabBolas->widget(i);
			tabBolas->removeTab(i);
			delete pagina;
		}
	}

	for (int idx = 0; idx < bolas->size(); ++idx) {
		Bola *b = bolas->at(idx);
		bool existe = false;

		for (int i = 0; i < tabBolas->count(); ++i) {
			WidgetBola *w = qobject_cast<WidgetBola*>(tabBolas->widget(i));
			if (w && w->bola() == b) {
				w->setVidas(w->bola()->vidas);
				existe = true;
				break;
			}
		}

		if (!existe) {
			QString nombre = QString("Bola %1 ").arg(idx);
			tabBolas->addTab(new WidgetBola(b), nombre);
		}
	}
}

void DControlBolas::slotCambiarTamanyoBolas(int indice) {

	for (int i = 0; i < bolas->size(); i++)
		bolas->at(i)->diametro = indice * 10 + 30;

}
