#ifndef DIALOGOVIERNES_H
#define DIALOGOVIERNES_H

#include <QDialog>

#include <QPushButton>
#include <QSlider>
#include <QLCDNumber>
#include <QCheckBox>

class DialogoViernes : public QDialog {
Q_OBJECT

public:
    DialogoViernes(QWidget *parent = NULL);

    QPushButton *btnOk, *btnCancel, *btnUno, *btnDos;
    QSlider *slArriba, *slCentro, *slAbajo;
    QLCDNumber *lcd;
    QCheckBox *chArriba, *chCentro, *chAbajo;

public slots:
    void slotEstablecerLCD(int);

};

#endif
