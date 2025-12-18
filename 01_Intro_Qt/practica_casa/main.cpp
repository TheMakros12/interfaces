#include <QApplication>
#include  <QHBoxLayout>
#include  <QVBoxLayout>
#include <QLCDNumber>
#include <QPushButton>
#include <QLabel>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    QWidget *windowBotones = new QWidget;
    QWidget *windowNumeros = new QWidget;
    windowBotones->setWindowTitle("Botones");
    windowNumeros->setWindowTitle("Números");

    QPushButton *btnUpIzquierda = new QPushButton("UP");
    QPushButton *btnDownIzquierda = new QPushButton("DOWN");
    QPushButton *btnUpDerecha = new QPushButton("UP");
    QPushButton *btnDownDerecha = new QPushButton("DOWN");

    QLabel *lblIzquierda = new QLabel("Izquierda");
    QLabel *lblDerecha = new QLabel("Derecha");

    QLCDNumber *numIzquierda = new QLCDNumber;
    QLCDNumber *numDerecha = new QLCDNumber;
    numIzquierda->display(12);
    numDerecha->display(21);

    QObject::connect(btnUpIzquierda, SIGNAL(clicked()), numIzquierda, SLOT(display(numIzquierda->value() + 1)));
    QObject::connect(btnDownIzquierda, SIGNAL(clicked()), numIzquierda, SLOT(display(numIzquierda->value() - 1)));

    QObject::connect(btnUpDerecha, SIGNAL(clicked()), numDerecha, SLOT(display(numDerecha->value() + 1)));
    QObject::connect(btnDownDerecha, SIGNAL(clicked()), numDerecha, SLOT(display(numDerecha->value() - 1)));

    QVBoxLayout *layoutBtnIzquierda = new QVBoxLayout;
    layoutBtnIzquierda->addWidget(btnUpIzquierda);
    layoutBtnIzquierda->addWidget(btnUpDerecha);

    QVBoxLayout *layoutBtnDerecha = new QVBoxLayout;
    layoutBtnDerecha->addWidget(btnUpDerecha);
    layoutBtnDerecha->addWidget(btnDownDerecha);

    QHBoxLayout *layoutBotones = new QHBoxLayout;
    layoutBotones->addLayout(layoutBtnIzquierda);
    layoutBotones->addLayout(layoutBtnDerecha);

    QVBoxLayout *layoutNumIzquierda = new QVBoxLayout;
    layoutNumIzquierda->addWidget(lblIzquierda);
    layoutNumIzquierda->addWidget(numIzquierda);

    QVBoxLayout *layoutNumDerecha = new QVBoxLayout;
    layoutNumDerecha->addWidget(lblDerecha);
    layoutNumDerecha->addWidget(numDerecha);

    QHBoxLayout *layoutNumeros = new QHBoxLayout;
    layoutNumeros->addLayout(layoutNumIzquierda);
    layoutNumDerecha->addLayout(layoutNumDerecha);

    windowBotones->setLayout(layoutBotones);
    windowNumeros->setLayout(layoutNumeros);
    windowBotones->show();
    windowNumeros->show();

    app.exec();

}
