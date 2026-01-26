#ifndef DSELECCIONAPELLIDOS_H
#define DSELECCIONAPELLIDOS_H
#include "ui_dseleccionapellidos.h"
#include "bola.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include <QListWidgetItem>

class DSeleccionApellidos : public QDialog, public Ui::DSeleccionApellidos {
Q_OBJECT

public:
	DSeleccionApellidos(QVector<Bola*> *, QStringList, QWidget *parent = NULL);
	QVector<Bola*> *bolas;
	QStringList apellidos;
	Bola *bolaSeleccionada;

	void actualizarNombre();

public slots:
	void slotSeleccionarBola(QListWidgetItem *);
	void slotCambiarPrimerApellido();
	void slotCambiarSegundoApellido();

};

#endif 
