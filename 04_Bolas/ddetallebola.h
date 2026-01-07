#ifndef DDETALLEBOLA_H
#define DDETALLEBOLA_H
#include "ui_ddetallebola.h"
#include "bola.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>

class DDetalleBola : public QDialog, public Ui::DDetalleBola {
Q_OBJECT

public:
	DDetalleBola(QVector<Bola*> *, QWidget *parent = NULL);
	QVector<Bola*> *lasBolas;
	int numBola;

	void inicializarColores();

public slots:
	void slotCambiarRojo(int);
	void slotCambiarVerde(int);
	void slotCambiarAzul(int);
	void slotAnterior();
	void slotSiguiente();

};

#endif 
