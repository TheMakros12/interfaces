#ifndef _JSON_ASSAY
#define _JSON_ASSAY

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QVector>

class Assay {

public:
    QString assay_chembl_id;
    QString description;
    QString document_chembl_id;

};

class JsonAssay {

public:
    Assay miAssay;
    JsonAssay(QByteArray);
    QStringList claves;
    QJsonObject objeto;

    Assay assay(QJsonObject objeto);


};

#endif
