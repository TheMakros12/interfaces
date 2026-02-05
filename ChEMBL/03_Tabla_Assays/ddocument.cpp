#include "ddocument.h"
#include <QDebug>

DDocument::DDocument(QString id, QWidget *parent): QDialog(parent), document_assay_id(id) {

	setupUi(this);

	DocumentApiClient *api = new DocumentApiClient(document_assay_id);

	connect(api, SIGNAL(senyalDatosRecibidos(QByteArray)),
			this, SLOT(slotDocumentoRecibido(QByteArray)));
	
}


void DDocument::slotDocumentoRecibido(QByteArray datos) {

	JsonDocument documentJson(datos);
	Document document = documentJson.document();

}

