#include "dialogoviernes.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

DialogoViernes::DialogoViernes(QWidget *parent) : QDialog(parent) {

    btnOk = new QPushButton("OK");
    btnCancel = new QPushButton("Cancel");
    btnUno = new QPushButton("Uno");
    btnDos = new QPushButton("Dos");

    slArriba = new QSlider(Qt::Horizontal);
    slCentro = new QSlider(Qt::Horizontal);
    slAbajo = new QSlider(Qt::Horizontal);

    lcd = new QLCDNumber;

    chArriba = new QCheckBox("Juan");
    chCentro = new QCheckBox("Perico");
    chAbajo = new QCheckBox("Andrés");

    QVBoxLayout *layoutPrincipal = new QVBoxLayout();
    QHBoxLayout *layoutSuperior = new QHBoxLayout();
    QHBoxLayout *layoutInferior = new QHBoxLayout();
    QVBoxLayout *layoutIzquierda = new QVBoxLayout();
    QVBoxLayout *layoutDerecha = new QVBoxLayout();

    QHBoxLayout *layoutSuperiorIzq = new QHBoxLayout();
    layoutSuperiorIzq->addWidget(slArriba);
    layoutSuperiorIzq->addWidget(chArriba);
    QHBoxLayout *layoutCentralIzq = new QHBoxLayout();
    layoutCentralIzq->addWidget(slCentro);
    layoutCentralIzq->addWidget(chCentro);
    QHBoxLayout *layoutInferiorIzq = new QHBoxLayout();
    layoutInferiorIzq->addWidget(slAbajo);
    layoutInferiorIzq->addWidget(chAbajo);

    layoutIzquierda->addLayout(layoutSuperiorIzq);
    layoutIzquierda->addLayout(layoutCentralIzq);
    layoutIzquierda->addLayout(layoutInferiorIzq);

    QHBoxLayout *layoutSuperiorDer = new QHBoxLayout();
    layoutSuperiorDer->addWidget(btnUno);
    layoutSuperiorDer->addWidget(btnDos);
    QHBoxLayout *layoutCentralDer = new QHBoxLayout();
    layoutCentralDer->addWidget(lcd);

    layoutDerecha->addLayout(layoutSuperiorDer);
    layoutDerecha->addLayout(layoutCentralDer);

    layoutSuperior->addLayout(layoutIzquierda);
    layoutSuperior->addLayout(layoutDerecha);

    layoutInferior->addWidget(btnOk);
    layoutInferior->addStretch();
    layoutInferior->addWidget(btnCancel);

    layoutPrincipal->addLayout(layoutSuperior);
    layoutPrincipal->addLayout(layoutInferior);
    setLayout(layoutPrincipal);

    connect(slArriba, SIGNAL(valueChanged(int)),
            this, SLOT(slotEstablecerLCD(int)));

    connect(slCentro, SIGNAL(valueChanged(int)),
            this, SLOT(slotEstablecerLCD(int)));

    connect(slAbajo, SIGNAL(valueChanged(int)),
            this, SLOT(slotEstablecerLCD(int)));

}

void DialogoViernes::slotEstablecerLCD(int cantidad) {

    int suma = slArriba->value() + slCentro->value() + slAbajo->value();
    lcd->display(suma);

}
