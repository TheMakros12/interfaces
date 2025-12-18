
#include "ventanaprincipal.h"
#include <QDebug>

#include "apiclient.h"

VentanaPrincipal::VentanaPrincipal(QWidget *parent): QMainWindow(parent){
		setupUi(this);

		new ApiClient;
}


void VentanaPrincipal::slotEjemplo(){

}

