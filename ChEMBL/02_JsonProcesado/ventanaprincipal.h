
#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H
#include "ui_ventanaprincipal.h"

#include <QVector>
#include <QMainWindow>
#include <QHBoxLayout>

class VentanaPrincipal : public QMainWindow, public Ui::VentanaPrincipal {
Q_OBJECT

public:
	VentanaPrincipal(QWidget *parent = NULL);

public slots:
	void slotDatosRecibidos(QByteArray);

};

#endif 
