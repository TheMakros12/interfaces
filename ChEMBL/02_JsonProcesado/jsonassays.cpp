#include "jsonassays.h"
#include <QDebug>

JsonAssays::JsonAssays(QByteArray bytes) {

    QJsonDocument documento(QJsonDocument::fromJson(bytes));

    qDebug().noquote() << documento.toJson(QJsonDocument::Indented);

    QJsonObject objeto = documento.object();


    QStringList claves = objeto.keys();
    qDebug()<< "===============claves: =============";
    qDebug()<< claves;
    QJsonValue value_assays = objeto["assays"];

    if (!value_assays.isArray()) {
        qDebug()<< "mal"
        return;
    }

    QJsonArray array_assays = value_assays.toArray();

    for (int i= 0 ; i < array_assays.size(); i++){

        QJsonValue unAssay = array_assays[i];

    }



    QString assay_chembl_id;
    QString cadenaDescripcion;
    if (claves.contains(QString("assay_chembl_id"))){
        QJsonValue valor_id = objeto["assay_chembl_id"];
        if (valor_id.isString())
            assay_chembl_id =valor_id.toString();
    }
    if (claves.contains("description")){
        QJsonValue description = objeto["description"];
        if (description.isString())
            cadenaDescripcion = description.toString();

    }
    qDebug()<< "*************** INFO : =============";

    qDebug() << "Valor clave primaria : " << assay_chembl_id;
    qDebug() << "Descripcion" << cadenaDescripcion;

    miAssay.description = cadenaDescripcion;
    miAssay.assay_chembl_id = assay_chembl_id;

}

Assay JsonAssays::assay(){ return miAssay ;}
