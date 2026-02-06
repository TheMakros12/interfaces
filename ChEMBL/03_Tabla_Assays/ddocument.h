#ifndef DDOCUMENT_H
#define DDOCUMENT_H
#include "ui_ddocument.h"
#include "jsondocument.h"
#include "documentapiclient.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>

class DDocument : public QDialog, public Ui::DDocument {
Q_OBJECT

public:
	DDocument(QString, QWidget *parent = NULL);
	QString document_assay_id;
	Document miDocument;

public slots:
	void slotDocumentoRecibido(QByteArray);

};

#endif 
