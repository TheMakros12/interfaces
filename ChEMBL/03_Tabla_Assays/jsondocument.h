#ifndef _JSON_DOCUMENT
#define _JSON_DOCUMENT

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QVector>

class Document {

public:
    QString title;
    QStringList authors;
    QString journal_full_title;
    QString abstract;

};

class JsonDocument {

public:
    Document document;
    JsonDocument(QByteArray);
    QStringList claves;
    QJsonObject objeto;

    Document document(QJsonObject objeto);

};

#endif
