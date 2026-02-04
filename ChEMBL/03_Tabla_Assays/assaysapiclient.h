#ifndef _ASSAYS_API_CLIENT_
#define _ASSAYS_API_CLIENT_

#include <QNetworkAccessManager>
#include <QNetworkReply>

class AssaysApiClient : public QObject {
Q_OBJECT
public:
	AssaysApiClient(QObject *parent = NULL);
	QNetworkAccessManager *manager;

	void fetch();

public slots:
	void slotRespuestaFinalizada(QNetworkReply *respuesta);

signals:
	void senyalDatosRecibidos(QByteArray);
	void senyalErrorPeticion(QString);

};





#endif
