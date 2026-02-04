#ifndef _JSON_ASSAYS_
#define _JSON_ASSAYS_
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

class Assays {

public:
    QString assay_chembl_id;
    QString description;

};

class JsonAssays {

public :
    Assay miAssay;
    JsonAssays(QByteArray);

    Assay assay();

};

#endif
