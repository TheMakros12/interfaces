#include <QApplication>
#include "dialogoprueba.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    DialogoPrueba *dPrueba = new DialogoPrueba();
    dPrueba->show();

    return app.exec();

}
