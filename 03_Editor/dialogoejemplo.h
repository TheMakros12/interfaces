#ifndef _DIALOEJEMPLO_H
#define _DIALOEJEMPLO_H

#include "ui_dialogoejemplo.h"

class DialogoEjemplo : public QDialog, public Ui::DialogoEjemplo {
Q_OBJECT

public:
    DialogoEjemplo(QWidget *parent = NULL);

};

#endif
