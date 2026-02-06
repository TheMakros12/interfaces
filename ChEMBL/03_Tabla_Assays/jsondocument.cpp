#include "jsondocument.h"

#include <QDebug>

JsonDocument::JsonDocument(QByteArray bytes) {

    QJsonDocument documento(QJsonDocument::fromJson(bytes));
    objeto = documento.object();
    claves = objeto.keys();

}

Document JsonDocument::document(QJsonObject objeto) {

    Document document;

    QString documentTitle;
    if ( claves.contains(QString("title")) ) {
        QJsonValue valorTitle = objeto["title"];

        if ( valorTitle.isString() ) {
            documentTitle = valorTitle.toString();
        }
    }
    document.title = documentTitle;

    QStringList documentAuthors;
    if ( claves.contains(QString("authors")) ) {
        QJsonValue valorAuthors = objeto["authors"];

        if ( valorAuthors.isNull() ) {
            documentAuthors.clear();
        }

        if ( valorAuthors.isString() ) {
            documentAuthors.append(valorAuthors.toString());
        }

        if ( valorAuthors.isArray() ) {
            QJsonArray arrayAuthors = valorAuthors.toArray();

            for (int i = 0; i < arrayAuthors.size(); i++) {
                documentAuthors.append(arrayAuthors.at(i).toString());
            }
        }

    }
    document.authors = documentAuthors;

    QString documentJournalFullTitle;
    if ( claves.contains(QString("journal_full_title")) ) {
        QJsonValue valorJournalFullTitle = objeto["journal_full_title"];

        if ( valorJournalFullTitle.isString() ) {
            documentJournalFullTitle = valorJournalFullTitle.toString();
        }
    }
    document.journal_full_title = documentJournalFullTitle;

    QString documentAbstract;
    if ( claves.contains(QString("abstract")) ) {
        QJsonValue valorAbstract = objeto["abstract"];

        if ( valorAbstract.isString() ) {
            documentAbstract = valorAbstract.toString();
        }
    }
    document.abstract = documentAbstract;

    return document;

}
