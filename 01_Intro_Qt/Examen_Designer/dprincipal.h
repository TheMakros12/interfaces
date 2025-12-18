#ifndef DPRINCIPAL_H_
#define DPRINCIPAL_H_

#include <QDialog>

#include "ui_dprincipal.h"

class DPrincipal : public QDialog, public Ui::DPrincipal {
Q_OBJECT

public:
    DPrincipal(QWidget *parent = NULL);

public slots:
    void slotLanarDialogo();

};

#endif
