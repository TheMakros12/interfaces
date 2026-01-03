#include "dinfobolas.h"

#include <QDebug>
#include <QTimer>

DInfoBolas::DInfoBolas(QVector<Bola*> *lasBolas, QWidget *parent): bolasInfo(lasBolas), QDialog(parent){

		setupUi(this);

		setWindowTitle("Lista de las Bolas");

		QTimer *temporizador = new QTimer();
		temporizador->setSingleShot(false);
		temporizador->setInterval(40);
		temporizador->start();

		connect(temporizador, SIGNAL(timeout()),
				this, SLOT(slotTemporizador()));
	
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

	listaBolas->clear();

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

		if (luminance(bolasInfo->at(i)->color) < 0.5)
			item->setForeground(QColor("white"));

		listaBolas->addItem(item);

	}

}

void DInfoBolas::slotTemporizador(){

	actualizar();

}
