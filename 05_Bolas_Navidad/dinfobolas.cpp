#include "dinfobolas.h"

#include <QDebug>
#include <QTimer>

DInfoBolas::DInfoBolas(QVector<Bola*> *lasBolas, Bola **bolaEspecial, QWidget *parent): bolasInfo(lasBolas), bolaJugador(bolaEspecial), QDialog(parent){

	setupUi(this);

	setWindowTitle("Lista de las Bolas");

	QTimer *temporizador = new QTimer();
	temporizador->setSingleShot(false);
	temporizador->setInterval(40);
	temporizador->start();

	connect(temporizador, SIGNAL(timeout()),
			this, SLOT(slotTemporizador()));

	listaBolas->setUniformItemSizes(true);
	listaBolas->setStyleSheet("QListWidget::item { height: 28px; }");
	listaBolas->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	listaBolas->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	
}

double luminance(const QColor& c) {

	auto channel = [](double v) {
		v /= 255.0;
		return (v <= 0.03928) ? v / 12.92 : powf((v + 0.055) / 1.055, 2.4);
	};

	double r = channel(c.red());
	double g = channel(c.green());
	double b = channel(c.blue());

	return 0.2126 * r + 0.7152 * g + 0.0722 * b;

}

void DInfoBolas::actualizar() {

	//Limpiamos el QListWidget
	listaBolas->clear();

	//Recogemos los datos de la Bola Especial para crear el QListWidgetItem
	if ( bolaJugador && *bolaJugador ) {

		Bola *jugador = *bolaJugador;

		QString cadenaEspecial("Jugador: ");
		cadenaEspecial += jugador->nombre +
		" PosX: " + QString::number(jugador->posX) +
		" PosY: " + QString::number(jugador->posY) +
		" VelX: " + QString::number(jugador->velX) +
		" VelY: " + QString::number(jugador->velY);

		QListWidgetItem *itemEspecial = new QListWidgetItem(cadenaEspecial);
		itemEspecial->setBackground(jugador->color);

		if ( luminance(jugador->color) < 0.5 )
			itemEspecial->setForeground(Qt::white);

		listaBolas->addItem(itemEspecial);
	}

	//Hacemos lo mismo para todo el Vector de Bolas
	for (int i = 0; i < bolasInfo->size(); i++) {

		int px = bolasInfo->at(i)->posX;
		int py = bolasInfo->at(i)->posY;
		float vx = bolasInfo->at(i)->velX;
		float vy = bolasInfo->at(i)->velY;

		QString cadena("Nombre: ");
		cadena += bolasInfo->at(i)->nombre +
		" PosX: " + QString::number(px) +
		" PosY: " + QString::number(py) +
		" VelX: " + QString::number(vx) +
		" VelY: " + QString::number(vy);

		QListWidgetItem *item = new QListWidgetItem(cadena);
		item->setBackground(bolasInfo->at(i)->color);

		if ( luminance(bolasInfo->at(i)->color) < 0.5 )
			item->setForeground(QColor("white"));

		listaBolas->addItem(item);

	}

	listaBolas->doItemsLayout();

	int totalHeight = 0;
	for (int i = 0; i < listaBolas->count(); ++i)
		totalHeight += listaBolas->sizeHintForRow(i);

	totalHeight += 2 * listaBolas->frameWidth();

	listaBolas->setFixedHeight(totalHeight);

	QFontMetrics fm(listaBolas->font());
	int maxWidth = 0;

	for (int i = 0; i < listaBolas->count(); ++i) {
		int w = fm.horizontalAdvance(listaBolas->item(i)->text());
		maxWidth = qMax(maxWidth, w);
	}

	maxWidth += 40; // márgenes
	listaBolas->setFixedWidth(maxWidth);

	adjustSize();

}

void DInfoBolas::slotTemporizador(){

	actualizar();

}
