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

    return assay;

}

QVector<Assay> JsonAssay::assays(QJsonObject objeto) {

    QVector<Assay> assays;

    for (int i = 0; i < objeto.count(); i++) {
        Assay assay = objeto["assay"];

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

        assays.append(assay);
    }


    return assays;

}
