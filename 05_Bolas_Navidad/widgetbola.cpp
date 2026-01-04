#include "widgetbola.h"
#include <QDebug>

WidgetBola::WidgetBola(Bola *bolaPasada, QWidget *parent): QWidget(parent), miBola(bolaPasada) {

	setupUi(this);

	connect(btnParar, SIGNAL(clicked()),
			this, SLOT(slotPararBola()));

	connect(btnMover, SIGNAL(clicked()),
			this, SLOT(slotMoverBola()));

	connect(btnColor, SIGNAL(clicked()),
			this, SLOT(slotColorBola()));
	
}

void WidgetBola::slotPararBola(){

	miBola->velX = 0;
	miBola->velY = 0;

}

void WidgetBola::slotMoverBola(){

	float nuevaVelX = (float)(random() % 100) / 50 - 1;
	float nuevaVelY = (float)(random() % 100) / 50 - 1;

	miBola->velX = nuevaVelX;
	miBola->velY = nuevaVelY;

}

void WidgetBola::slotColorBola(){

	QColor c = QColorDialog::getColor(miBola->color, this);
	if (c.isValid())
		miBola->color = c;

}
