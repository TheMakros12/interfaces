#include "jsonassay.h"

#include <QDebug>

JsonAssay::JsonAssay(QByteArray bytes) {

    QJsonDocument documento(QJsonDocument::fromJson(bytes));

    qDebug().noquote() << documento.toJson(QJsonDocument::Indented);

    QJsonObject objecto = documento.object();

    QStringList claves = objecto.keys();
    qDebug() << "==================== Claves: ====================";
    qDebug() << claves;

    QString assayChemblId;
    if ( claves.contains(QString("assay_chembl_id")) ) {
        QJsonValue valor_id = objecto["assay_chembl_id"];
        if ( valor_id.isString() ) {
            assayChemblId = valor_id.toString();
        }
    }

    qDebug() << "==================== INFO: ====================";
    qDebug() << "Valor clave primaria: " << assayChemblId;

}
