#include "dseleccionapellidos.h"
#include <QDebug>

DSeleccionApellidos::DSeleccionApellidos(QVector<Bola*> *bolasPasadas, QStringList apellidosPasados, QWidget *parent): QDialog(parent), bolas(bolasPasadas), apellidos(apellidosPasados) {

	setupUi(this);

	setWindowTitle("Selección de los Apellidos");

	btnPrimerApellido->setEnabled(false);
	btnSegundoApellido->setEnabled(false);

	for (int i = 0; i < bolas->size(); i++) {
		QListWidgetItem *itemNombre = new QListWidgetItem(bolas->at(i)->nombre);
		listaNombres->addItem(itemNombre);
	}

	for (int j = 0; j < apellidos.length(); j++) {
		QListWidgetItem *itemApellidos = new QListWidgetItem(apellidos.at(j));
		listaApellidos->addItem(itemApellidos);
	}

	connect(listaNombres, SIGNAL(itemClicked(QListWidgetItem *)),
			this, SLOT(slotSeleccionarBola(QListWidgetItem *)));

	connect(btnPrimerApellido, SIGNAL(clicked()),
			this, SLOT(slotCambiarPrimerApellido()));

	connect(btnSegundoApellido, SIGNAL(clicked()),
			this, SLOT(slotCambiarSegundoApellido()));
	
}

void DSeleccionApellidos::actualizarNombre() {

	QString nombreCompleto = "";
	nombreCompleto = bolaSeleccionada->nombre + " " + bolaSeleccionada->apellido_1 + " "  + bolaSeleccionada->apellido_2;

	lblNombreCompleto->setText(nombreCompleto);

}


void DSeleccionApellidos::slotSeleccionarBola(QListWidgetItem *item) {

	QString nombreItem = item->text();
	QString nombreCompleto = "";
	for (int i = 0; i < bolas->size(); i++) {
		if ( bolas->at(i)->nombre == nombreItem ) {
			bolaSeleccionada = bolas->at(i);
			nombreCompleto = nombreItem + " " + bolaSeleccionada->apellido_1 + " "  + bolaSeleccionada->apellido_2;
		}
	}

	btnPrimerApellido->setEnabled(true);
	btnSegundoApellido->setEnabled(true);
	lblNombreCompleto->setText(nombreCompleto);

}

void DSeleccionApellidos::slotCambiarPrimerApellido() {

	QListWidgetItem *itemApellido = listaApellidos->currentItem();

	QString nuevoApellido = itemApellido->text();

	bolaSeleccionada->apellido_1 = nuevoApellido;
	actualizarNombre();

}

void DSeleccionApellidos::slotCambiarSegundoApellido() {

	QListWidgetItem *itemApellido = listaApellidos->currentItem();

	QString nuevoApellido = itemApellido->text();

	bolaSeleccionada->apellido_2 = nuevoApellido;
	actualizarNombre();

}

