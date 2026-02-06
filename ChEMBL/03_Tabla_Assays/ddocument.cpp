#include "ddocument.h"

#include <QDebug>

DDocument::DDocument(QString id, QWidget *parent): QDialog(parent), document_assay_id(id) {

	setupUi(this);

	DocumentApiClient *documentApiClient = new DocumentApiClient(document_assay_id);

	connect(documentApiClient, SIGNAL(senyalDatosRecibidos(QByteArray)),
			this, SLOT(slotDocumentoRecibido(QByteArray)));

}


void DDocument::slotDocumentoRecibido(QByteArray datos) {

	JsonDocument documentJson(datos);
	miDocument = documentJson.document(documentJson.objeto);

	lblDocumentTitle->setText(miDocument.title);
	QString autores;
	for (const QString &autor : miDocument.authors) {
        autores += autor + ", ";
    }
	txtAuthors->setText(autores);
	txtJournalFullTitle->setText(miDocument.journal_full_title);
	txtAbstract->setText(miDocument.abstract);

}


