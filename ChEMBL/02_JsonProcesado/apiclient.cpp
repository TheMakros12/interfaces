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
    QString stringUrl = QString("https://www.ebi.ac.uk/chembl/api/data/assay/CHEMBL615117?format=json");

    // stringUrl = QString("https://www.ebi.ac.uk/chembl/api/data/assay/?format=json");

    request.setUrl(QUrl(stringUrl));

    manager->get(request);

}

void ApiClient::slotRespuestaFinalizada(QNetworkReply *respuesta) {

    if (respuesta->error() != QNetworkReply::NoError) {
    qDebug() << "Error: " << respuesta->error();
    emit senyalErrorPeticion(QString::number(respuesta->error()));
    return;
    }

    QByteArray datosCrudos = respuesta->readAll();
    QString textoRecibido = QString(datosCrudos);

    emit senyalDatosRecibidos(datosCrudos);

    //qDebug() << textoRecibido;

}
