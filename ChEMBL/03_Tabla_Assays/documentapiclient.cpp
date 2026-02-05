#include "documentapiclient.h"

#include <QDebug>
#include <QByteArray>
#include <QNetworkRequest>
#include <QNetworkReply>

DocumentApiClient::DocumentApiClient(QString id, QObject *parent): QObject(parent), document_chembl_id(id) {

    manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT (slotRespuestaFinalizada(QNetworkReply*)));

    fetch();

}

void DocumentApiClient::fetch() {

    QNetworkRequest request;

    request.setRawHeader("Accept", "application/json");
    QString stringUrl = QString("https://www.ebi.ac.uk/chembl/api/data/document/" + document_chembl_id + "?format=json");

    request.setUrl(QUrl(stringUrl));

    manager->get(request);

}

void DocumentApiClient::slotRespuestaFinalizada(QNetworkReply *respuesta) {

    if ( respuesta->error() != QNetworkReply::NoError ) {
        qDebug() << "Error: " << respuesta->error();
        emit senyalErrorPeticion(QString::number(respuesta->error()));
        return;
    }

    QByteArray datosCrudos = respuesta->readAll();
    QString textoRecibido = QString(datosCrudos);

    emit senyalDatosRecibidos(datosCrudos);

}
