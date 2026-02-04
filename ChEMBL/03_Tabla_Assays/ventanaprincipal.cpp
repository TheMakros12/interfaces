
#include "ventanaprincipal.h"
#include <QDebug>

#include "assaysapiclient.h"
#include "jsonassay.h"
#include "jsonassays.h"
#include "dtablaassays.h"

VentanaPrincipal::VentanaPrincipal(QWidget *parent): QMainWindow(parent){
		setupUi(this);

		//AssayApiClient *assayApiClient = new AssayApiClient("CHEMBL615117");

		AssaysApiClient *assaysApiClient = new AssaysApiClient();

		connect(assaysApiClient, SIGNAL(senyalDatosRecibidos(QByteArray)),
				this, SLOT(slotAssaysRecibidos(QByteArray)));
}


void VentanaPrincipal::slotDatosRecibidos(QByteArray datosRecibidos){

	// JsonAssay parser(datosRecibidos);
 //
	// Assay unAssay = parser.assay(parser.objeto);
	// DialogoAssay *dialogo = new DialogoAssay(unAssay);
	// dialogo->show();

}

void VentanaPrincipal::slotAssaysRecibidos(QByteArray datosRecibidos) {

	JsonAssays parser(datosRecibidos);
	QVector<Assay> assays = parser.assays();

	DTablaAssays *dTablaAssays = new DTablaAssays(assays);
	dTablaAssays->show();

}
