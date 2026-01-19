#ifndef DPRINCIPAL_H_
#define DPRINCIPAL_H_

#include "dsecundario.h"

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class DPrincipal : public QDialog {
Q_OBJECT

public:
    DPrincipal(QWidget *parent = NULL);
    DSecundario *dSecundario;

    QLineEdit *lineEdit;
    QPushButton *btnAnyadir, *btnQuitar;
    QStringList nombres;
    bool dialogoCreado;


public slots:
    void slotLaznzarDialogoSecundario();
    void slotBorrarNombre();

};

#endif
