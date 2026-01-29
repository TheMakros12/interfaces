#ifndef _JSON_ASSAY
#define _JSON_ASSAY

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

class Assay {

public:
    QString assay_group;

};

class JsonAssay {

public:
    JsonAssay(QByteArray, Assay*);


};

#endif
