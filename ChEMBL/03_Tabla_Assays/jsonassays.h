#ifndef _JSON_ASSAYS_
#define _JSON_ASSAYS_

#include "jsonassay.h"

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

class JsonAssays {

public :
    QVector<Assay> misAssays;
    JsonAssays(QByteArray);

    QVector<Assay> assays();

};

#endif
