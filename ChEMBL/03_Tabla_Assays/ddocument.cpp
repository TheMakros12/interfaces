#include "ddocument.h"
#include <QDebug>

DDocument::DDocument(QString id, QWidget *parent): QDialog(parent), document_assay_id(id) {

	setupUi(this);

	DocumentApiClient *documentApiClient = new DocumentApiClient(document_assay_id);

	connect(documentApiClient, SIGNAL(senyalDatosRecibidos(QByteArray)),
			this, SLOT(slotDocumentoRecibido(QByteArray)));

	lblDocumentTitle->setText(document.title);
	QString autores = "";
	for (int i = 0; i < document.authors.size(); i++) {
		autores += document.authors.at(i) + ", ";
	}
	txtAuthors->setText(autores);
	txtJournalFullTitle->setText(document.journal_full_title);
	txtAbstract->setText(document.abstract);
	
}


void DDocument::slotDocumentoRecibido(QByteArray datos) {

	JsonDocument documentJson(datos);
	document = documentJson.document();

}

