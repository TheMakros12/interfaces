#ifndef _ASSAY_API_CLIENT_
#define _ASSAY_API_CLIENT_

#include <QNetworkAccessManager>
#include <QNetworkReply>

class AssayApiClient : public QObject {
Q_OBJECT
public:
	AssayApiClient(QString, QObject *parent = NULL);

	QNetworkAccessManager *manager;
	QString assay_chembl_id;


	void fetch();

public slots:
	void slotRespuestaFinalizada(QNetworkReply *respuesta);

signals:
	void senyalDatosRecibidos(QByteArray);
	void senyalErrorPeticion(QString);

};





#endif
