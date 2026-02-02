#include "dialogoassay.h"
#include <QDebug>

DialogoAssay::DialogoAssay(Assay assay, QWidget *parent): QDialog(parent), miAssay(assay) {

	setupUi(this);

	lblId->setText(miAssay.assay_chembl_id);
	txtDescription->setText(miAssay.description);
	
}


void DialogoAssay::slotEjemplo(){

}

