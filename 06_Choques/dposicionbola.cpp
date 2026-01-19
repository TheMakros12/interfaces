#include "dposicionbola.h"
#include <QDebug>

DPosicionBola::DPosicionBola(QVector<Bola*> *bolasPasadas, QWidget *parent): QDialog(parent), lasBolas(bolasPasadas) {

	setupUi(this);

	setWindowTitle("Posición de la Bola");

	tabPosicion->clear();

	QTimer *temporizador = new QTimer(this);
	temporizador->setInterval(100);
	temporizador->setSingleShot(false);
	connect(temporizador, SIGNAL(timeout()),
			this, SLOT(slotTemporizador()));
	temporizador->start();

	actualizarTabs();
	
}

void DPosicionBola::actualizarTabs() {

	for (int i = tabPosicion->count() - 1; i >= 0; --i) {
		WidgetPosicionBola *w =
		qobject_cast<WidgetPosicionBola*>(tabPosicion->widget(i));

		if (!w || !w->laBola || w->laBola->vidas <= 0) {

			if (w && w->laBola) {
				lasBolas->removeOne(w->laBola);
			}

			QWidget *pagina = tabPosicion->widget(i);
			tabPosicion->removeTab(i);
			delete pagina;
		}
	}

	for (int idx = 0; idx < lasBolas->size(); idx++) {
		Bola *b = lasBolas->at(idx);
		bool existe = false;

		for (int i = 0; i < tabPosicion->count(); i++) {
			WidgetPosicionBola *w =
			qobject_cast<WidgetPosicionBola*>(tabPosicion->widget(i));

			if (w && w->laBola == b) {
				existe = true;
				break;
			}
		}
		if (!existe) {
			tabPosicion->addTab(new WidgetPosicionBola(b), b->nombre);
		}
	}

}


void DPosicionBola::slotTemporizador() {

	actualizarTabs();

}

