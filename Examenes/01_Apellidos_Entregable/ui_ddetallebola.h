/********************************************************************************
** Form generated from reading UI file 'ddetallebola.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DDETALLEBOLA_H
#define UI_DDETALLEBOLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_DDetalleBola
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lePosX;
    QLabel *label;
    QLabel *label_2;
    QSlider *slRojo;
    QSlider *slVerde;
    QLabel *label_3;
    QSlider *slAzul;
    QLabel *label_4;
    QPushButton *bAnterior;
    QPushButton *bSiguiente;
    QLabel *lNombre;

    void setupUi(QDialog *DDetalleBola)
    {
        if (DDetalleBola->objectName().isEmpty())
            DDetalleBola->setObjectName(QString::fromUtf8("DDetalleBola"));
        DDetalleBola->resize(400, 300);
        buttonBox = new QDialogButtonBox(DDetalleBola);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lePosX = new QLineEdit(DDetalleBola);
        lePosX->setObjectName(QString::fromUtf8("lePosX"));
        lePosX->setGeometry(QRect(140, 43, 113, 32));
        label = new QLabel(DDetalleBola);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 50, 111, 21));
        label_2 = new QLabel(DDetalleBola);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 90, 51, 21));
        slRojo = new QSlider(DDetalleBola);
        slRojo->setObjectName(QString::fromUtf8("slRojo"));
        slRojo->setGeometry(QRect(110, 90, 160, 20));
        slRojo->setOrientation(Qt::Horizontal);
        slVerde = new QSlider(DDetalleBola);
        slVerde->setObjectName(QString::fromUtf8("slVerde"));
        slVerde->setGeometry(QRect(110, 120, 160, 20));
        slVerde->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(DDetalleBola);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 120, 51, 21));
        slAzul = new QSlider(DDetalleBola);
        slAzul->setObjectName(QString::fromUtf8("slAzul"));
        slAzul->setGeometry(QRect(110, 150, 160, 20));
        slAzul->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(DDetalleBola);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 150, 51, 21));
        bAnterior = new QPushButton(DDetalleBola);
        bAnterior->setObjectName(QString::fromUtf8("bAnterior"));
        bAnterior->setGeometry(QRect(60, 190, 88, 34));
        bSiguiente = new QPushButton(DDetalleBola);
        bSiguiente->setObjectName(QString::fromUtf8("bSiguiente"));
        bSiguiente->setGeometry(QRect(210, 190, 88, 34));
        lNombre = new QLabel(DDetalleBola);
        lNombre->setObjectName(QString::fromUtf8("lNombre"));
        lNombre->setGeometry(QRect(130, 10, 111, 21));

        retranslateUi(DDetalleBola);
        QObject::connect(buttonBox, SIGNAL(accepted()), DDetalleBola, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DDetalleBola, SLOT(reject()));

        QMetaObject::connectSlotsByName(DDetalleBola);
    } // setupUi

    void retranslateUi(QDialog *DDetalleBola)
    {
        DDetalleBola->setWindowTitle(QCoreApplication::translate("DDetalleBola", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DDetalleBola", "Posicion X", nullptr));
        label_2->setText(QCoreApplication::translate("DDetalleBola", "Rojo", nullptr));
        label_3->setText(QCoreApplication::translate("DDetalleBola", "Verde", nullptr));
        label_4->setText(QCoreApplication::translate("DDetalleBola", "Azul", nullptr));
        bAnterior->setText(QCoreApplication::translate("DDetalleBola", "Anterior", nullptr));
        bSiguiente->setText(QCoreApplication::translate("DDetalleBola", "Siguiente", nullptr));
        lNombre->setText(QCoreApplication::translate("DDetalleBola", "Posicion X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DDetalleBola: public Ui_DDetalleBola {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DDETALLEBOLA_H
