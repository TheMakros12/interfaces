
#ifndef WPOSICIONBOLA_H
#define WPOSICIONBOLA_H
#include "ui_wposicionbola.h"

#include <QVector>
#include <QWidget>
#include <QHBoxLayout>
#include "bola.h"

class WPosicionBola : public QWidget, public Ui::WPosicionBola {
Q_OBJECT

public:
	WPosicionBola(Bola*,QWidget *parent = NULL);

public slots:
	void slotEjemplo();

};

#endif 
