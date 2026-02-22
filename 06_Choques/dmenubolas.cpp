#include "dmenubolas.h"
#include <QDebug>

DMenuBolas::DMenuBolas(Bola *laBola, QWidget *parent): QDialog(parent){
		setupUi(this);

		lblNombreBola->setText(laBola->nombre);
	
}


void DMenuBolas::slotEjemplo(){

}

