#ifndef DSELECCIONAPELLIDOS_H
#define DSELECCIONAPELLIDOS_H
#include "ui_dseleccionapellidos.h"
#include "bola.h"
#include "dtablaapellidos.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include <QListWidgetItem>

class DSeleccionApellidos : public QDialog, public Ui::DSeleccionApellidos {
Q_OBJECT

public:
	DSeleccionApellidos(QVector<Bola*> *, QStringList, ModeloApellidos *, QWidget *parent = nullptr);
	QVector<Bola*> *bolas;
	QStringList apellidos;
	Bola *bolaSeleccionada;
	ModeloApellidos *modelo;

	void actualizarNombre();

public slots:
	void slotSeleccionarBola(QListWidgetItem *);
	void slotCambiarPrimerApellido();
	void slotCambiarSegundoApellido();

};

#endif 
