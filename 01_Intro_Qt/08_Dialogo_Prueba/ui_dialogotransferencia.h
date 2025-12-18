/********************************************************************************
** Form generated from reading UI file 'dialogotransferencia.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOTRANSFERENCIA_H
#define UI_DIALOGOTRANSFERENCIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogoTransferencia
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *lblNumCuenta;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *lblCantidad;

    void setupUi(QDialog *DialogoTransferencia)
    {
        if (DialogoTransferencia->objectName().isEmpty())
            DialogoTransferencia->setObjectName(QString::fromUtf8("DialogoTransferencia"));
        DialogoTransferencia->resize(261, 135);
        widget = new QWidget(DialogoTransferencia);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 20, 229, 96));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lblNumCuenta = new QLabel(widget);
        lblNumCuenta->setObjectName(QString::fromUtf8("lblNumCuenta"));

        horizontalLayout->addWidget(lblNumCuenta);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lblCantidad = new QLabel(widget);
        lblCantidad->setObjectName(QString::fromUtf8("lblCantidad"));

        horizontalLayout_2->addWidget(lblCantidad);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(DialogoTransferencia);

        QMetaObject::connectSlotsByName(DialogoTransferencia);
    } // setupUi

    void retranslateUi(QDialog *DialogoTransferencia)
    {
        DialogoTransferencia->setWindowTitle(QCoreApplication::translate("DialogoTransferencia", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogoTransferencia", "Destiono de la transferencia:", nullptr));
        lblNumCuenta->setText(QCoreApplication::translate("DialogoTransferencia", "111", nullptr));
        label_2->setText(QCoreApplication::translate("DialogoTransferencia", "Cantidad de transferencia", nullptr));
        lblCantidad->setText(QCoreApplication::translate("DialogoTransferencia", "111", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogoTransferencia: public Ui_DialogoTransferencia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOTRANSFERENCIA_H
