#ifndef DSECUNDARIO_H_
#define DSECUNDARIO_H_

#include <QDialog>
#include <QListWidget>
#include <QSlider>

class DSecundario : public QDialog {
Q_OBJECT

public:
    DSecundario(QString nombre, QWidget *parent = NULL);

    QListWidget *listaNombres;
    QSlider *slider;

    void anyadirNombre(const QString &nombre);
    void actualizarSlider();

signals:
    void nombreSeleccionado(const QString &nombre);

public slots:
    void seleccionarNombre();

};

#endif
