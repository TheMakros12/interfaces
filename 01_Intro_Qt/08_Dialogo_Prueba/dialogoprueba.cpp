#include <QDialog>
#include <QWidget>
#include <QDebug>

#include "dialogoprueba.h"
#include "dialogotransferencia.h"

DialogoPrueba::DialogoPrueba(QDialog *parent) : QDialog(parent) {

    setupUi(this);

    dTransferencia = NULL;
    btnLanzarTransferencia = new QPushButton();

    connect(btnLanzarTransferencia, SIGNAL(clicked()),
            this, SLOT(slotLanzarTransferencia()));

}

void DialogoPrueba::slotLanzarTransferencia() {

    qDebug() << "Lanzando SLOT";

    if (dTransferencia == NULL) {
        dTransferencia = new DialogoTransferencia();
    }
    dTransferencia->show();

}
