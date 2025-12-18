#include "dacercade.h"
#include <QDialog>
#include <QLabel>
#include <QIcon>
#include <QVBoxLayout>

DAcercaDe::DAcercaDe(QDialog *parent): QDialog(parent) {

    setWindowIcon(QIcon("./img/informacion.png"));
    setWindowTitle("Acerca De");

    lblAcercaDe = new QLabel("Dialgo creado por Marcos");

    layoutPrincipal = new QVBoxLayout();
    layoutPrincipal->addWidget(lblAcercaDe);

    setLayout(layoutPrincipal);

}
