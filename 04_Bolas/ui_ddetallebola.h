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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DDetalleBola
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *lblNombreBola;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lePosicionX;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSlider *slRojo;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSlider *slVerde;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSlider *slAzul;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnAnterior;
    QPushButton *btnSiguiente;

    void setupUi(QDialog *DDetalleBola)
    {
        if (DDetalleBola->objectName().isEmpty())
            DDetalleBola->setObjectName(QString::fromUtf8("DDetalleBola"));
        DDetalleBola->resize(450, 355);
        buttonBox = new QDialogButtonBox(DDetalleBola);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(60, 310, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lblNombreBola = new QLabel(DDetalleBola);
        lblNombreBola->setObjectName(QString::fromUtf8("lblNombreBola"));
        lblNombreBola->setGeometry(QRect(180, 20, 66, 19));
        widget = new QWidget(DDetalleBola);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 50, 281, 221));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lePosicionX = new QLineEdit(widget);
        lePosicionX->setObjectName(QString::fromUtf8("lePosicionX"));

        horizontalLayout->addWidget(lePosicionX);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        slRojo = new QSlider(widget);
        slRojo->setObjectName(QString::fromUtf8("slRojo"));
        slRojo->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(slRojo);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        slVerde = new QSlider(widget);
        slVerde->setObjectName(QString::fromUtf8("slVerde"));
        slVerde->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(slVerde);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        slAzul = new QSlider(widget);
        slAzul->setObjectName(QString::fromUtf8("slAzul"));
        slAzul->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(slAzul);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        btnAnterior = new QPushButton(widget);
        btnAnterior->setObjectName(QString::fromUtf8("btnAnterior"));

        horizontalLayout_5->addWidget(btnAnterior);

        btnSiguiente = new QPushButton(widget);
        btnSiguiente->setObjectName(QString::fromUtf8("btnSiguiente"));

        horizontalLayout_5->addWidget(btnSiguiente);


        verticalLayout_2->addLayout(horizontalLayout_5);


        retranslateUi(DDetalleBola);
        QObject::connect(buttonBox, SIGNAL(accepted()), DDetalleBola, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DDetalleBola, SLOT(reject()));

        QMetaObject::connectSlotsByName(DDetalleBola);
    } // setupUi

    void retranslateUi(QDialog *DDetalleBola)
    {
        DDetalleBola->setWindowTitle(QCoreApplication::translate("DDetalleBola", "Dialog", nullptr));
        lblNombreBola->setText(QCoreApplication::translate("DDetalleBola", "Nombre", nullptr));
        label->setText(QCoreApplication::translate("DDetalleBola", "Posici\303\263n X:", nullptr));
        label_2->setText(QCoreApplication::translate("DDetalleBola", "Rojo:", nullptr));
        label_3->setText(QCoreApplication::translate("DDetalleBola", "Verde:", nullptr));
        label_4->setText(QCoreApplication::translate("DDetalleBola", "Azul", nullptr));
        btnAnterior->setText(QCoreApplication::translate("DDetalleBola", "Bola Anterior", nullptr));
        btnSiguiente->setText(QCoreApplication::translate("DDetalleBola", "Bola Siguiente", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DDetalleBola: public Ui_DDetalleBola {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DDETALLEBOLA_H
