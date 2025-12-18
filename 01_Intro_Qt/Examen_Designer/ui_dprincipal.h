/********************************************************************************
** Form generated from reading UI file 'dprincipal.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DPRINCIPAL_H
#define UI_DPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DPrincipal
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *leNombre;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAnyadir;
    QPushButton *btnQuitar;

    void setupUi(QDialog *DPrincipal)
    {
        if (DPrincipal->objectName().isEmpty())
            DPrincipal->setObjectName(QString::fromUtf8("DPrincipal"));
        DPrincipal->resize(252, 119);
        widget = new QWidget(DPrincipal);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 231, 101));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        leNombre = new QLineEdit(widget);
        leNombre->setObjectName(QString::fromUtf8("leNombre"));

        verticalLayout->addWidget(leNombre);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnAnyadir = new QPushButton(widget);
        btnAnyadir->setObjectName(QString::fromUtf8("btnAnyadir"));

        horizontalLayout->addWidget(btnAnyadir);

        btnQuitar = new QPushButton(widget);
        btnQuitar->setObjectName(QString::fromUtf8("btnQuitar"));

        horizontalLayout->addWidget(btnQuitar);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DPrincipal);

        QMetaObject::connectSlotsByName(DPrincipal);
    } // setupUi

    void retranslateUi(QDialog *DPrincipal)
    {
        DPrincipal->setWindowTitle(QCoreApplication::translate("DPrincipal", "Dialog", nullptr));
        btnAnyadir->setText(QCoreApplication::translate("DPrincipal", "A\303\261adir", nullptr));
        btnQuitar->setText(QCoreApplication::translate("DPrincipal", "Quitar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DPrincipal: public Ui_DPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPRINCIPAL_H
