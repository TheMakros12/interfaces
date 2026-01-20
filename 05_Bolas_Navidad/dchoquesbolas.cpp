#include "dchoquesbolas.h"
#include <QDebug>

DChoquesBolas::DChoquesBolas(QVector<Bola*> *bolas, QWidget *parent): QDialog(parent), bolas(bolas) {

	setupUi(this);

	setWindowTitle("Choques de las Bolas");

	tabChoques->clear();

	QTimer *temporizador = new QTimer();
	temporizador->setSingleShot(false);
	temporizador->setInterval(200);
	connect(temporizador, SIGNAL(timeout()),
			this, SLOT(slotTemporizador()));
	temporizador->start();
}

void DChoquesBolas::slotTemporizador(){

	// --- Eliminar pestañas inválidas ---
    for (int i = tabChoques->count() - 1; i >= 0; i--) {
        WidgetChoque *w =
            qobject_cast<WidgetChoque*>(tabChoques->widget(i));

        if (!w || !w->bola || w->bola->vidas <= 0) {

            QWidget *pag = tabChoques->widget(i);
            tabChoques->removeTab(i);
            delete pag;
        }
    }

    // --- Añadir pestañas nuevas ---
    for (Bola *b : *bolas) {
        if (!b || b->vidas <= 0)
            continue;

        bool existe = false;

        for (int i = 0; i < tabChoques->count(); i++) {
            WidgetChoque *w =
                qobject_cast<WidgetChoque*>(tabChoques->widget(i));
            if (w && w->bola == b) {
                existe = true;
                break;
            }
        }

        if (!existe) {
            tabChoques->addTab(new WidgetChoque(b), b->nombre);
        }
    }

    // --- Repintar widgets ---
    for (int i = 0; i < tabChoques->count(); i++) {
        if (auto *w = qobject_cast<WidgetChoque*>(tabChoques->widget(i))) {
            w->update();
        }
    }

}
