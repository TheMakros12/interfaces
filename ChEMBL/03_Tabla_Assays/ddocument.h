#ifndef DDOCUMENT_H
#define DDOCUMENT_H
#include "ui_ddocument.h"
#include "jsondocument.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>

class DDocument : public QDialog, public Ui::DDocument {
Q_OBJECT

public:
	DDocument(QString, QWidget *parent = NULL);
	QString document_assay_id;
	Document document;

public slots:
	void slotDocumentoRecibido(QByteArray);

};

#endif 
