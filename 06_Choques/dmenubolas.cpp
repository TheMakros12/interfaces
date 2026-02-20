#include "dmenubolas.h"
#include <QDebug>

DMenuBolas::DMenuBolas(QString nombreBola, QWidget *parent): QDialog(parent){
		setupUi(this);

		lblNombreBola->setText(nombreBola);
	
}


void DMenuBolas::slotEjemplo(){

}

