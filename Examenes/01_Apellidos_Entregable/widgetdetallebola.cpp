
#include "widgetdetallebola.h"
#include <QDebug>

WidgetDetalleBola::WidgetDetalleBola(Bola * bolaPasada, QWidget *parent): QWidget(parent),laBola(bolaPasada){
		setupUi(this);

		slRojo->setMaximum(255);

		connect(slRojo,&QSlider::valueChanged,
				this,&WidgetDetalleBola::slotCambioRojo);
}


void WidgetDetalleBola::slotEjemplo(){

}

void WidgetDetalleBola::on_bParar_clicked(){

	laBola->velX = laBola->velY = 0.0;

}

void WidgetDetalleBola::slotCambioRojo(int rojo){

	laBola->color.setRed(rojo);

}
