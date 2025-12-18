#include "dprincipal.h"
#include "dsecundario.h"

DPrincipal::DPrincipal(QWidget *parent): QDialog(parent) {

    setupUi(this);

    connect(btnAnyadir, SIGNAL(clicked()),
            this, SLOT(slotLanarDialogo()));

}

void DPrincipal::slotLanarDialogo() {

    DSecundario *dSecundario = new DSecundario();
    dSecundario->show();

}
