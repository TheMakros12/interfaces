#include "dprincipal.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStringList>
#include <QDebug>
#include <QListWidgetItem>

DPrincipal::DPrincipal(QWidget *parent) : QDialog(parent) {

    dialogoCreado = false;

    QStringList nombres;

    dSecundario = NULL;

    lineEdit = new QLineEdit();

    btnAnyadir = new QPushButton("Añadir");
    btnQuitar = new QPushButton("Quitar");
    btnQuitar->setEnabled(false);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *upperLayout = new QHBoxLayout();
    QHBoxLayout *lowerLayout = new QHBoxLayout();

    upperLayout->addWidget(lineEdit);
    upperLayout->addStretch();

    lowerLayout->addWidget(btnAnyadir);
    lowerLayout->addWidget(btnQuitar);

    mainLayout->addLayout(upperLayout);
    mainLayout->addLayout(lowerLayout);

    setLayout(mainLayout);

    connect(btnAnyadir, SIGNAL(clicked()),
            this, SLOT(slotLaznzarDialogoSecundario()));

    connect(btnQuitar, SIGNAL(clicked()),
            this, SLOT(slotBorrarNombre()));

}

void DPrincipal::slotLaznzarDialogoSecundario() {

    QString nombre = lineEdit->text();

    if (!dialogoCreado) {
        dSecundario = new DSecundario(nombre);
        dSecundario->show();
        btnQuitar->setEnabled(true);
        dialogoCreado = true;

        connect(dSecundario, SIGNAL(nombreSeleccionado(QString)),
                lineEdit, SLOT(setText(QString)));
    } else {
        if (!nombre.isEmpty()) {
            dSecundario->anyadirNombre(nombre);
            lineEdit->clear();
            dSecundario->actualizarSlider();
        }
    }

}

void  DPrincipal::slotBorrarNombre() {

    QString texto = lineEdit->text();

    if (!texto.isEmpty()) {
        QList<QListWidgetItem*> items = dSecundario->listaNombres->findItems(texto, Qt::MatchExactly);
        if (!items.isEmpty()) {
            delete dSecundario->listaNombres->takeItem(dSecundario->listaNombres->row(items.first()));
            dSecundario->actualizarSlider();
            lineEdit->clear();
        }
    } else {
        int row = dSecundario->listaNombres->currentRow();
        if (row >= 0) {
            delete dSecundario->listaNombres->takeItem(row);
            dSecundario->actualizarSlider();
            lineEdit->clear();
        }
    }

}
