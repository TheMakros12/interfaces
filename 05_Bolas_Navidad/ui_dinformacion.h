/********************************************************************************
** Form generated from reading UI file 'dinformacion.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DINFORMACION_H
#define UI_DINFORMACION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DInformacion
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *lblDimensiones;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *lblNumBolas;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DInformacion)
    {
        if (DInformacion->objectName().isEmpty())
            DInformacion->setObjectName(QString::fromUtf8("DInformacion"));
        DInformacion->resize(310, 204);
        verticalLayout_2 = new QVBoxLayout(DInformacion);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(DInformacion);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lblDimensiones = new QLabel(DInformacion);
        lblDimensiones->setObjectName(QString::fromUtf8("lblDimensiones"));

        horizontalLayout->addWidget(lblDimensiones);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(DInformacion);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        lblNumBolas = new QLabel(DInformacion);
        lblNumBolas->setObjectName(QString::fromUtf8("lblNumBolas"));

        horizontalLayout_2->addWidget(lblNumBolas);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(DInformacion);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(DInformacion);
        QObject::connect(buttonBox, SIGNAL(accepted()), DInformacion, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DInformacion, SLOT(reject()));

        QMetaObject::connectSlotsByName(DInformacion);
    } // setupUi

    void retranslateUi(QDialog *DInformacion)
    {
        DInformacion->setWindowTitle(QCoreApplication::translate("DInformacion", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DInformacion", "Tama\303\261o del juego:", nullptr));
        lblDimensiones->setText(QCoreApplication::translate("DInformacion", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("DInformacion", "N\303\272mero de Bolas:", nullptr));
        lblNumBolas->setText(QCoreApplication::translate("DInformacion", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DInformacion: public Ui_DInformacion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DINFORMACION_H
