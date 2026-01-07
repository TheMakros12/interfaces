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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DDetalleBola
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *leNuevoNombre;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSlider *slRojo;
    QLabel *lblIntRojo;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSlider *slVerde;
    QLabel *lblIntVerde;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSlider *slAzul;
    QLabel *lblIntAzul;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnAnterior;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnSiguiente;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lblNombreBola;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLabel *lblNumBola;

    void setupUi(QDialog *DDetalleBola)
    {
        if (DDetalleBola->objectName().isEmpty())
            DDetalleBola->setObjectName(QString::fromUtf8("DDetalleBola"));
        DDetalleBola->resize(444, 356);
        buttonBox = new QDialogButtonBox(DDetalleBola);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(60, 290, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(DDetalleBola);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 50, 281, 221));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        leNuevoNombre = new QLineEdit(layoutWidget);
        leNuevoNombre->setObjectName(QString::fromUtf8("leNuevoNombre"));

        horizontalLayout->addWidget(leNuevoNombre);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        slRojo = new QSlider(layoutWidget);
        slRojo->setObjectName(QString::fromUtf8("slRojo"));
        slRojo->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(slRojo);

        lblIntRojo = new QLabel(layoutWidget);
        lblIntRojo->setObjectName(QString::fromUtf8("lblIntRojo"));

        horizontalLayout_2->addWidget(lblIntRojo);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        slVerde = new QSlider(layoutWidget);
        slVerde->setObjectName(QString::fromUtf8("slVerde"));
        slVerde->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(slVerde);

        lblIntVerde = new QLabel(layoutWidget);
        lblIntVerde->setObjectName(QString::fromUtf8("lblIntVerde"));

        horizontalLayout_3->addWidget(lblIntVerde);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        slAzul = new QSlider(layoutWidget);
        slAzul->setObjectName(QString::fromUtf8("slAzul"));
        slAzul->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(slAzul);

        lblIntAzul = new QLabel(layoutWidget);
        lblIntAzul->setObjectName(QString::fromUtf8("lblIntAzul"));

        horizontalLayout_4->addWidget(lblIntAzul);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        btnAnterior = new QPushButton(layoutWidget);
        btnAnterior->setObjectName(QString::fromUtf8("btnAnterior"));

        horizontalLayout_5->addWidget(btnAnterior);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        btnSiguiente = new QPushButton(layoutWidget);
        btnSiguiente->setObjectName(QString::fromUtf8("btnSiguiente"));

        horizontalLayout_5->addWidget(btnSiguiente);


        verticalLayout_2->addLayout(horizontalLayout_5);

        layoutWidget1 = new QWidget(DDetalleBola);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(120, 20, 205, 23));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        lblNombreBola = new QLabel(layoutWidget1);
        lblNombreBola->setObjectName(QString::fromUtf8("lblNombreBola"));

        horizontalLayout_7->addWidget(lblNombreBola);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        lblNumBola = new QLabel(layoutWidget1);
        lblNumBola->setObjectName(QString::fromUtf8("lblNumBola"));

        horizontalLayout_6->addWidget(lblNumBola);


        horizontalLayout_7->addLayout(horizontalLayout_6);


        retranslateUi(DDetalleBola);
        QObject::connect(buttonBox, SIGNAL(accepted()), DDetalleBola, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DDetalleBola, SLOT(reject()));

        QMetaObject::connectSlotsByName(DDetalleBola);
    } // setupUi

    void retranslateUi(QDialog *DDetalleBola)
    {
        DDetalleBola->setWindowTitle(QCoreApplication::translate("DDetalleBola", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DDetalleBola", "NUevo nombre:", nullptr));
        label_2->setText(QCoreApplication::translate("DDetalleBola", "Rojo:", nullptr));
        lblIntRojo->setText(QCoreApplication::translate("DDetalleBola", "0", nullptr));
        label_3->setText(QCoreApplication::translate("DDetalleBola", "Verde:", nullptr));
        lblIntVerde->setText(QCoreApplication::translate("DDetalleBola", "0", nullptr));
        label_4->setText(QCoreApplication::translate("DDetalleBola", "Azul", nullptr));
        lblIntAzul->setText(QCoreApplication::translate("DDetalleBola", "0", nullptr));
        btnAnterior->setText(QCoreApplication::translate("DDetalleBola", "Bola Anterior", nullptr));
        btnSiguiente->setText(QCoreApplication::translate("DDetalleBola", "Bola Siguiente", nullptr));
        lblNombreBola->setText(QCoreApplication::translate("DDetalleBola", "Nombre", nullptr));
        label_5->setText(QCoreApplication::translate("DDetalleBola", "N\302\272:", nullptr));
        lblNumBola->setText(QCoreApplication::translate("DDetalleBola", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DDetalleBola: public Ui_DDetalleBola {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DDETALLEBOLA_H
