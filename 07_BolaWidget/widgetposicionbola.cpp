#include "widgetposicionbola.h"
#include <QDebug>

WidgetPosicionBola::WidgetPosicionBola(Bola *bolaPasada, QWidget *parent): QWidget(parent), laBola(bolaPasada) {

	setupUi(this);

	//PanelPosicionBola *pPB = new PanelPosicionBola(laBola);
	QHBoxLayout *ly = new QHBoxLayout();
	ly->addWidget(static_cast<BolaWidget*>(laBola));

	framePosicion->setLayout(ly);
	
}


void WidgetPosicionBola::slotEjemplo(){

}

