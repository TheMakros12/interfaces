#ifndef DCONTROLBOLAS_H
#define DCONTROLBOLAS_H
#include "ui_dcontrolbolas.h"
#include "bola.h"
#include "widgetbola.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include <QTimer>

class DControlBolas : public QDialog, public Ui::DControlBolas {
Q_OBJECT

public:
	explicit DControlBolas(QVector<Bola*> *bolas, QWidget *parent = nullptr);

private:
	QVector<Bola*> *bolas;
	QTimer *temporizador;

private slots:
	void slotPararTodas();
	void slotMoverTodas();
	void slotActualizarTabs();

};

#endif 
