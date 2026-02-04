#ifndef _ASSAYS_API_CLIENT_
#define _ASSAYS_API_CLIENT_

#include <QNetworkAccessManager>
#include <QNetworkReply>

class AssaysApiClient : public QObject {
Q_OBJECT
public:
	AssaysApiClient(QString, QObject *parent = NULL);

	QNetworkAccessManager *manager;
	QString assay_chembl_id;


	void fetch(QString);

public slots:
	void slotRespuestaFinalizada(QNetworkReply *respuesta);

signals:
	void senyalDatosRecibidos(QByteArray);
	void senyalErrorPeticion(QString);

};





#endif
