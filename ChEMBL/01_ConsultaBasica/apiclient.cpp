#include "apiclient.h"
#include <QDebug>
#include <QByteArray>
#include <QNetworkRequest>
#include <QNetworkReply>


ApiClient::ApiClient(QObject * parent): QObject(parent){

    manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply *)),
            this, SLOT(slotRespuestaFinalizada(QNetworkReply *)));

    fetch();

}

void ApiClient::fetch() {

    QNetworkRequest request;

    request.setRawHeader("Accept", "application/json");
    request.setUrl(QUrl("https://www.ebi.ac.uk/chembl/api/data/assay/CHEMBL615117?format=json"));

    manager->get(request);

}

void ApiClient::slotRespuestaFinalizada(QNetworkReply *respuesta) {

    if (respuesta->error() != QNetworkReply::NoError) {
    qDebug() << "Error: " << respuesta->error();
    emit senyalErrorPeticion(respuesta->error().toString());
    return;
    }

    QByteArray datosCrudos = respuesta->readAll();
    QString textoRecibido = QString(datosCrudos);

    emit senyalDatosRecibidos(textoRecibido);

    qDebug() << textoRecibido;

}
