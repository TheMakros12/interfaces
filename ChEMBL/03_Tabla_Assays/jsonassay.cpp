#include "jsonassay.h"

#include <QDebug>

JsonAssay::JsonAssay(QByteArray bytes) {

    QJsonDocument documento(QJsonDocument::fromJson(bytes));

    qDebug().noquote() << documento.toJson(QJsonDocument::Indented);

    objeto = documento.object();

    claves = objeto.keys();
    qDebug() << "=================== Claves: ===================";
    qDebug() << claves;

}

Assay JsonAssay::assay(QJsonObject objeto) {

    Assay assay;

    QString assayChemblId;
    if ( claves.contains(QString("assay_chembl_id")) ) {
        QJsonValue valor_id = objeto["assay_chembl_id"];
        if ( valor_id.isString() ) {
            assayChemblId = valor_id.toString();
        }
    }
    assay.assay_chembl_id = assayChemblId;

    QString cadenaDescription;
    if ( claves.contains("description") ) {
        QJsonValue description = objeto["description"];
        if ( description.isString() ) {
            cadenaDescription = description.toString();
        }
    }
    assay.description = cadenaDescription;

    QString documentChemblId;
    if ( claves.contains(QString("document_chembl_id")) ) {
        QJsonValue valor_document_id = objeto["document_chembl_id"];
        qDebug() << valor_document_id;
        if ( valor_document_id.isString() ) {
            documentChemblId = valor_document_id.toString();
        }
    }
    assay.document_chembl_id = documentChemblId;

    qDebug() << "====================================================";
    qDebug() << documentChemblId;
    qDebug() << "====================================================";

    return assay;

}
