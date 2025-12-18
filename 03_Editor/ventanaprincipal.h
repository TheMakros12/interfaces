#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H
#include <QMainWindow>
#include <QAction>
#include <QTextEdit>
#include <QCloseEvent>
#include <QVector>
#include <QStringList>
#include <QLabel>
#include <QTextEdit>

#define MAX_FICHEROS_RECIENTES 5 

class VentanaPrincipal : public QMainWindow {
Q_OBJECT

public:

	VentanaPrincipal(QWidget *parent = NULL);
	void crearAcciones();
	void crearMenus();
	void crearBarraEstado();
	void abrirFichero(QString);
	void nombreDoc(QString);
	void actualizarBarraEstado();
	void escribirArchivo(QString);
	void leerArchivo(QString);
	void actualizarArchivosRecientes(QString);
	void abrirFicherosRecientes(QString);

	void closeEvent(QCloseEvent *event);

	QAction *actionSalir,
	*actionAcercaDe,
	*actionGuardar,
	*actionGuardarComo,
	*actionAbrir,
	*accionDialogoEjemplo;

	QTextEdit *editorCentral;
	QLabel *lblPosicion,
	*lblNombreDoc;
	QString *nombreDocumento;
	QString rutaArchivo;
	QStringList ficherosRecientes;
	QVector<QAction*> accionesRecientes;

	bool documentoModificado;

public slots:

	void slotAcercaDe();
	void slotGuardar();
	void slotGuardarComo();
	void slotAbrir();
	void slotCambioCursor();
	void slotTextoCambiado();
	void slotReciente();
	void slotDialogoEjemplo();

};

#endif
