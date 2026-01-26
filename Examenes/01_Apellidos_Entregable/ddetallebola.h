
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
	QVector<Bola*> * lasBolas;
	int indiceBolaElegida;

public slots:
	void on_bAnterior_clicked();
	void on_bSiguiente_clicked();
	void slotEjemplo();
	void slotCambioRojo(int);

};

#endif 
