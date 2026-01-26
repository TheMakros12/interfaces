
#include "wposicionbola.h"
#include "panelposicionbola.h"
#include <QDebug>

WPosicionBola::WPosicionBola(Bola * bPasada, QWidget *parent): QWidget(parent){
		setupUi(this);

		PanelPosicionBola * pPB = new PanelPosicionBola(bPasada);
		QHBoxLayout * ly = new QHBoxLayout();
		ly->addWidget(pPB);

		fPanel->setLayout(ly);
		
}


void WPosicionBola::slotEjemplo(){

}

