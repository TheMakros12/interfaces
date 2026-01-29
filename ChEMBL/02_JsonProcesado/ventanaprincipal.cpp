
#include "ventanaprincipal.h"
#include <QDebug>

#include "apiclient.h"
#include "jsonassay.h"

VentanaPrincipal::VentanaPrincipal(QWidget *parent): QMainWindow(parent){
		setupUi(this);

		ApiClient *apiClient = new ApiClient();

		connect(apiClient, SIGNAL(senyalDatosRecibidos(QByteArray)),
				this, SLOT(slotDatosRecibidos(QByteArray)));
}


void VentanaPrincipal::slotDatosRecibidos(QByteArray datosRecibidos){

	JsonAssay parser(datosRecibidos);

}

