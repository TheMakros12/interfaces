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
        qDebug()<< "mal";
        return;
    }

    QJsonArray array_assays = value_assays.toArray();

    for (int i= 0 ; i < array_assays.size(); i++){

        QJsonValue unAssay = array_assays[i];
        if (!unAssay.isObject()) {
            qDebug() << "mal";
            return;
        }

        QJsonObject asssayObject = unAssay.toObject();
        Assay assay;
        assay.assay_chembl_id = asssayObject.value("assay_chembl_id").toString();
        assay.description = asssayObject.value("description").toString();
        assay.document_chembl_id = asssayObject.value("document_chembl_id").toString();

        misAssays.append(assay);

    }

}

QVector<Assay> JsonAssays::assays(){ return misAssays ;}
