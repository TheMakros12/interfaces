#ifndef WIDGETBOLA_H
#define WIDGETBOLA_H
#include "ui_widgetbola.h"
#include "bola.h"

#include <QVector>
#include <QWidget>
#include <QHBoxLayout>
#include <stdlib.h>
#include <QColorDialog>
#include <QPointer>

class WidgetBola : public QWidget, public Ui::WidgetBola {
Q_OBJECT

public:
	explicit WidgetBola(Bola *bola, QWidget *parent = nullptr);

	QPointer<Bola> bola() const { return miBola; }

	void inicializarColores();

private:
	QPointer<Bola> miBola;

public slots:
	void slotPararBola();
	void slotMoverBola();
	void slotColorBola();

};

#endif 
