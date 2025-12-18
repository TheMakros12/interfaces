#ifndef DIALOGO_PRUEBA_H_
#define DIALOGO_PRUEBA_H_

#include <QPushButton>

#include "ui_dialogoprueba.h"
#include "dialogotransferencia.h"

class DialogoPrueba : public QDialog, public Ui::DialogoPrueba {
Q_OBJECT

public:
    DialogoPrueba(QDialog * parent = NULL);
    DialogoTransferencia *dTransferencia;
    QPushButton *btnLanzarTransferencia;

public slots:
    void slotLanzarTransferencia();

};

#endif
