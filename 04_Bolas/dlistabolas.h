#ifndef _DLISTABOLAS_H_
#define _DLISTABOLAS_H_
#include "ui_dlistabolas.h"
#include "bola.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>

class DListaBolas : public QDialog, public Ui::DListaBolas {
Q_OBJECT

public:
    DListaBolas(QVector<Bola*>*, QWidget *parent = NULL);
    QVector<Bola*> *pBolas;

public slots:
    void slotEjemplo();
    void slotActualizar();

};

#endif
