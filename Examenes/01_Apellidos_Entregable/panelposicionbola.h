#ifndef PANELPOSICIONBOLA_H
#define PANELPOSICIONBOLA_H


#include <QVector>
#include <QWidget>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QTimer>
#include <QPaintEvent>
#include "bola.h"


class PanelPosicionBola : public QWidget {
Q_OBJECT

public:
	PanelPosicionBola(Bola * bPasada, QWidget * parent =NULL);

	Bola * miBola;
	void mousePressEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent * event);
	
public slots:
	void slotTemporizador();

};




#endif








