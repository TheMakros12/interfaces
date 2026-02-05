#ifndef _DOCUMENT_API_CLIENT_
#define _DOCUMENT_API_CLIENT_

#include <QNetworkAccessManager>
#include <QNetworkReply>

class DocumentApiClient : public QObject {

public:
    DocumentApiClient(QString, QObject *parent = NULL);
    QNetworkAccessManager *manager;
	QString document_chembl_id;

    void fetch();

public slots:
    void slotRespuestaFinalizada(QNetworkReply *respuesta);

signals:
    void senyalDatosRecibidos(QByteArray);
    void senyalErrorPeticion(QString);

};
