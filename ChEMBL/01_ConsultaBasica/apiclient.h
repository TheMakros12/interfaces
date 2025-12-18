#ifndef _API_CLIENT_
#define _API_CLIENT_

#include <QNetworkAccessManager>
#include <QNetworkReply>

class ApiClient : public QObject {
Q_OBJECT
public:
	ApiClient(QObject *parent = NULL);

	QNetworkAccessManager *manager;

	void fetch();

public slots:
	void slotRespuestaFinalizada(QNetworkReply *respuesta);

signals:
	void senyalDatosRecibidos(QString);
	void senyalErrorPeticion(QString);

};





#endif
