
#include "ventanaprincipal.h"
#include <QDebug>

#include "assayapiclient.h"
#include "jsonassay.h"

VentanaPrincipal::VentanaPrincipal(QWidget *parent): QMainWindow(parent){
		setupUi(this);

		//AssayApiClient *assayApiClient = new AssayApiClient("CHEMBL615117");

		connect(assayApiClient, SIGNAL(senyalDatosRecibidos(QByteArray)),
				this, SLOT(slotDatosRecibidos(QByteArray)));
}


void VentanaPrincipal::slotDatosRecibidos(QByteArray datosRecibidos){

	JsonAssay parser(datosRecibidos);

	// Assay unAssay = parser.assay(parser.objeto);
 //
	// DialogoAssay *dialogo = new DialogoAssay(unAssay);
	// dialogo->show();

}

