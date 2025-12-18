#include "ventanaprincipal.h"
#include "dacercade.h"
#include "dialogoejemplo.h"
#include <QMessageBox>
#include <QComboBox>
#include <QPushButton>
#include <QMenuBar>
#include <QMenu>
#include <QIcon>
#include <QKeySequence>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>	
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QTextBlock>
#include <QTextDocument>
#include <QTextStream>
#include <QStatusBar>
#include <QMessageBox>
#include <QVariant>


VentanaPrincipal::VentanaPrincipal(QWidget *parent) : QMainWindow(parent){

	rutaArchivo = "";

	lblPosicion = new QLabel("Posición");
	nombreDocumento = new QString("Nombre Documento");
	editorCentral = new QTextEdit();
	setCentralWidget(editorCentral);

	setWindowIcon(QIcon("./img/text-format.png"));
	setWindowTitle("03_Editor");

	connect(editorCentral, SIGNAL(cursorPositionChanged()),
			this, SLOT(slotCambioCursor()));

	connect(editorCentral, SIGNAL(textChanged()),
			this, SLOT(slotTextoCambiado()));

	crearAcciones();
	crearMenus();
	crearBarraEstado();
	documentoModificado = false;
	
}

void VentanaPrincipal::crearAcciones() {

	//Action Salir
	actionSalir = new QAction("Salir");
	actionSalir->setShortcut(QKeySequence::Quit);
	actionSalir->setIcon(QIcon("./img/salir.png"));
	actionSalir->setStatusTip("Salir del programa");

	connect(actionSalir, SIGNAL(triggered()),
			this, SLOT(close()));

	//Action AcercaDe
	actionAcercaDe = new QAction("Acerca De");
	actionAcercaDe->setShortcut(QKeySequence::WhatsThis);
	actionAcercaDe->setIcon(QIcon("./img/informacion.png"));
	actionAcercaDe->setStatusTip("Acerca De");

	connect(actionAcercaDe, SIGNAL(triggered()),
			this, SLOT(slotAcercaDe()));

	//Action Guardar
	actionGuardar = new QAction("Guardar");
	actionGuardar->setShortcut(QKeySequence::Save);
	actionGuardar->setIcon(QIcon("./img/disquete.png"));
	actionGuardar->setStatusTip("Guardar");

	connect(actionGuardar, SIGNAL(triggered()),
			this, SLOT(slotGuardar()));

	//Action Guardar Como
	actionGuardarComo = new QAction("Guardar Como");
	actionGuardarComo->setShortcut(QKeySequence::SaveAs);
	actionGuardarComo->setIcon(QIcon("./img/disqueteComo.png"));
	actionGuardarComo->setStatusTip("Guardar Como");

	connect(actionGuardarComo, SIGNAL(triggered()),
			this, SLOT(slotGuardarComo()));

	//Action Abrir
	actionAbrir = new QAction("Abrir");
	actionAbrir->setShortcut(QKeySequence::Open);
	actionAbrir->setIcon(QIcon("./img/abrir.png"));
	actionAbrir->setStatusTip("Abrir");

	connect(actionAbrir, SIGNAL(triggered()),
			this, SLOT(slotAbrir()));

	//Action Dialogo Ejemplo
	accionDialogoEjemplo = new QAction("DialogoEjemplo");
	accionDialogoEjemplo->setIcon(QIcon("./img/informacion.png"));
	accionDialogoEjemplo->setStatusTip("Dialogo Ejemplo");

	connect(accionDialogoEjemplo, SIGNAL(triggered()),
			this, SLOT(slotDialogoEjemplo()));

	//Acciones Archivos Recientes
	for (int i = 0; i < MAX_FICHEROS_RECIENTES; i++) {
		QAction * accion = new QAction("Acción " + QString::number(i + 1));
		accionesRecientes.append(accion);

		connect(accion, SIGNAL(triggered()),
				this, SLOT(slotReciente()));
	}

}

void VentanaPrincipal::crearMenus() {

	QMenuBar *barra = menuBar();

	QMenu *menuFichero = barra->addMenu("Fichero");
	menuFichero->addAction(actionAcercaDe);
	menuFichero->addAction(actionAbrir);
	menuFichero->addAction(actionGuardar);
	menuFichero->addAction(actionGuardarComo);
	menuFichero->addAction(actionSalir);
	menuFichero->addAction(accionDialogoEjemplo);
	menuFichero->addSeparator();
	for (int i = 0; i < MAX_FICHEROS_RECIENTES; i++) {
		menuFichero->addAction(accionesRecientes[i]);
		accionesRecientes[i]->setVisible(false);
	}

}

void VentanaPrincipal::crearBarraEstado() {

	QStatusBar *barraEstado = statusBar();
	lblNombreDoc = new QLabel("Nombre del Archivo");

	barraEstado->addWidget(lblPosicion);
	barraEstado->addWidget(lblNombreDoc);

}

void VentanaPrincipal::actualizarBarraEstado() {

	QString nombreCorto = QFileInfo(rutaArchivo).fileName();
	if (documentoModificado)
		nombreCorto = QString("*") + nombreCorto;

	lblNombreDoc->setText(nombreCorto);

}

void VentanaPrincipal::actualizarArchivosRecientes(QString ruta) {

	ficherosRecientes.removeAll(ruta);
	ficherosRecientes.prepend(ruta);

	for (int i = 0; i < MAX_FICHEROS_RECIENTES && i < ficherosRecientes.length(); i++) {
		QString nombreCorto = QFileInfo(ficherosRecientes.at(i)).fileName();

		accionesRecientes.at(i)->setText(nombreCorto);
		accionesRecientes.at(i)->setVisible(true);

		QVariant dato(ficherosRecientes.at(i));
		accionesRecientes.at(i)->setData(dato);
	}

}

void VentanaPrincipal::closeEvent(QCloseEvent *event) {

	qDebug() << "Cerrando el programa";

	if (!documentoModificado) {
		event->accept();
		return;
	}

	int respuesta;
	respuesta = QMessageBox::question(this, QString("Documento modificado"),
			QString("Guardar y Salir, Cancelar, No Guardar y Salir"),
			QMessageBox::Save | QMessageBox::Cancel | QMessageBox::Close);

	if (respuesta == QMessageBox::Cancel) {
		event->ignore();
	}

	if (respuesta == QMessageBox::Close) {
		event->accept();
	}

	if (respuesta == QMessageBox::Save) {
		slotGuardarComo();
	}

}

void VentanaPrincipal::leerArchivo(QString ruta) {

	QFile fichero(ruta);

	if (!fichero.open(QIODevice::ReadOnly))
		return;

	QTextStream stream(&fichero);

	editorCentral->clear();

	while (!stream.atEnd()) {
		QString texto = stream.readLine();
		editorCentral->append(texto);
	}

	fichero.close();
	rutaArchivo = ruta;

	documentoModificado = false;
	actualizarBarraEstado();
	actualizarArchivosRecientes(ruta);

}

void VentanaPrincipal::escribirArchivo(QString rutaArchivo2) {

	QFile fichero(rutaArchivo2);

	if (!fichero.open(QIODevice::ReadOnly))
		return;

	QTextStream stream(&fichero);
	QTextDocument *documento = editorCentral->document();

	int i = 0;
	while (i < documento->blockCount()) {
		QString texto = documento->findBlockByNumber(i).text();
		qDebug() << "Línea leida" << texto;
		if (!texto.isEmpty())
			stream << texto;

		stream << endl;
		i++;
	}

	rutaArchivo = rutaArchivo2;
	documentoModificado = false;

	fichero.close();
	actualizarBarraEstado();
	actualizarArchivosRecientes(rutaArchivo);

}

void VentanaPrincipal::abrirFichero(QString archivo) {

	editorCentral->document()->clear();

	QFile fichero(archivo);
	if (!fichero.open(QIODevice::ReadOnly))
		return;

	QTextStream stream(&fichero);

	while (!stream.atEnd()) {
		QString texto = stream.readLine();
		editorCentral->append(texto);
	}

	fichero.close();

}

void VentanaPrincipal::nombreDoc(QString archivo) {

	QString nombreArchivo = QFileInfo(archivo).fileName();
	lblNombreDoc->setText(nombreArchivo);

}

void VentanaPrincipal::slotAbrir() {

	QString ruta = QFileDialog::getOpenFileName();

	qDebug() << "Has elegido el fichero " << ruta;

	leerArchivo(ruta);

}

void VentanaPrincipal::slotGuardarComo() {

	QString rutaArchivo = QFileDialog::getSaveFileName();
	qDebug() << "Ruta elegida para guardar " << rutaArchivo;

	escribirArchivo(rutaArchivo);

}

void VentanaPrincipal::slotGuardar() {

	if (rutaArchivo.isEmpty()) {
		slotGuardarComo();
		return;
	}

	escribirArchivo(rutaArchivo);

}

void VentanaPrincipal::slotCambioCursor() {

	int linea, columna;

	linea = editorCentral->textCursor().blockNumber();
	columna = editorCentral->textCursor().positionInBlock();

	QString txt("Posición: ");
	txt = txt + QString::number(linea) + ", " + QString::number(columna);

	lblPosicion->setText(txt);

}

void VentanaPrincipal::slotTextoCambiado() {
	documentoModificado = true;
	actualizarBarraEstado();
}

void VentanaPrincipal::slotReciente() {

	qDebug() << "Amijo, quieres abrir un fihcero";

	QObject *culpable = QObject::sender();
	QAction * accionCulpable = qobject_cast<QAction*>(culpable);
	QString textoAccion = accionCulpable->text();
	qDebug() << "La culpable es la que muestra el texto " << textoAccion;

	leerArchivo(accionCulpable->data().toString());

}

void VentanaPrincipal::slotAcercaDe() {

	DAcercaDe * dAcercaDe = new DAcercaDe();
	dAcercaDe->show();

}

void VentanaPrincipal::abrirFicherosRecientes(QString fileName) {

	abrirFichero(fileName);

}

void VentanaPrincipal::slotDialogoEjemplo() {

	DialogoEjemplo *dialogo = new DialogoEjemplo();
	dialogo->show();

}
