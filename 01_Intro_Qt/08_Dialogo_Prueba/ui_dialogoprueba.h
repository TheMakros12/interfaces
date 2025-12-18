/********************************************************************************
** Form generated from reading UI file 'dialogoprueba.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOPRUEBA_H
#define UI_DIALOGOPRUEBA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogoPrueba
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *leNumCuenta;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *leCantidad;
    QPushButton *btnLanzarTransferencia;

    void setupUi(QDialog *DialogoPrueba)
    {
        if (DialogoPrueba->objectName().isEmpty())
            DialogoPrueba->setObjectName(QString::fromUtf8("DialogoPrueba"));
        DialogoPrueba->resize(376, 226);
        buttonBox = new QDialogButtonBox(DialogoPrueba);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 180, 344, 27));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(DialogoPrueba);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 10, 346, 147));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        leNumCuenta = new QLineEdit(widget);
        leNumCuenta->setObjectName(QString::fromUtf8("leNumCuenta"));

        horizontalLayout->addWidget(leNumCuenta);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        leCantidad = new QLineEdit(widget);
        leCantidad->setObjectName(QString::fromUtf8("leCantidad"));

        horizontalLayout_2->addWidget(leCantidad);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        btnLanzarTransferencia = new QPushButton(widget);
        btnLanzarTransferencia->setObjectName(QString::fromUtf8("btnLanzarTransferencia"));

        verticalLayout_2->addWidget(btnLanzarTransferencia);


        retranslateUi(DialogoPrueba);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogoPrueba, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogoPrueba, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogoPrueba);
    } // setupUi

    void retranslateUi(QDialog *DialogoPrueba)
    {
        DialogoPrueba->setWindowTitle(QCoreApplication::translate("DialogoPrueba", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogoPrueba", "N\303\272mero de Cuenta Bancaria:", nullptr));
        label_2->setText(QCoreApplication::translate("DialogoPrueba", "Cantidad:", nullptr));
        btnLanzarTransferencia->setText(QCoreApplication::translate("DialogoPrueba", "Lanzar Transferencia", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogoPrueba: public Ui_DialogoPrueba {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOPRUEBA_H
