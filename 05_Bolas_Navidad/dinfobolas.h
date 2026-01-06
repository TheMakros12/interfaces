#ifndef DINFOBOLAS_H
#define DINFOBOLAS_H
#include "ui_dinfobolas.h"
#include "bola.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>

class DInfoBolas : public QDialog, public Ui::DInfoBolas {
Q_OBJECT

public:
	DInfoBolas(QVector<Bola*> *lasBolas, Bola **bolaEspecial, QWidget *parent = NULL);

	QVector<Bola*> *bolasInfo;
	Bola **bolaJugador;

	void actualizar();

public slots:
	void slotTemporizador();

};

#endif 
