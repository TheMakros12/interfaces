#include <QApplication>
#include "dialogoviernes.h"

int main (int argc, char *argv[]) {

    QApplication app(argc, argv);
    DialogoViernes * dViernes = new DialogoViernes();
    dViernes->show();

    return app.exec();

}
