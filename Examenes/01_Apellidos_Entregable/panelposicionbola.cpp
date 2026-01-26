#include "panelposicionbola.h"
#include <QBrush>

PanelPosicionBola::PanelPosicionBola(Bola * bPasada, QWidget *){
	
	miBola = bPasada;
	
	QTimer *temporizador = new QTimer();
	temporizador->setInterval(40);
	temporizador->setSingleShot(false);
	temporizador->start();
	
	connect(temporizador,SIGNAL(timeout()),
				this,SLOT(slotTemporizador()));
	
	
	resize(400,400);	
}

void PanelPosicionBola::mousePressEvent(QMouseEvent *event){

	int clickX = event->x();
	int clickY = event->y();
	
	int posFinX = clickX * miBola->anchuraJuego  / width();
	int posFinY = clickY * miBola->alturaJuego  / height();	
	
	miBola->velX = miBola->velY = 0;	
	
	miBola->posX = posFinX;
	miBola->posY = posFinY;
	
	}
	
	
void PanelPosicionBola::slotTemporizador(){

	update();
}



void PanelPosicionBola::paintEvent(QPaintEvent * event){
	
	QPainter pintor(this);
	QBrush brush(miBola->color,Qt::Dense4Pattern);

	
	float posicionX = miBola->posX * width() / miBola->anchuraJuego;
	float posicionY = miBola->posY * height() / miBola->alturaJuego;
			
	pintor.fillRect( posicionX-3,0,6,height(),brush);
	pintor.fillRect( 0,posicionY-3,width(),6,brush);

	
	
	
}


	
	
	
	
	
	
