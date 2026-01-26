
#include "dposicionbolas.h"
#include "wposicionbola.h"
#include <QDebug>

DPosicionBolas::DPosicionBolas(QVector<Bola*> *bPasadas, QWidget *parent): QDialog(parent){
		setupUi(this);

		tabBolas->clear();
		
		for (int i = 0 ; i < bPasadas->size() ; i++){
			
			WPosicionBola *w = new WPosicionBola( bPasadas->at(i) );
			tabBolas->addTab(w, bPasadas->at(i)->nombre);
		}
}


void DPosicionBolas::slotEjemplo(){

}

