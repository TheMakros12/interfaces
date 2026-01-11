/********************************************************************************
** Form generated from reading UI file 'dtablarebotebolas.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DTABLAREBOTEBOLAS_H
#define UI_DTABLAREBOTEBOLAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DTablaReboteBolas
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTableView *tablaReboteBolas;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DTablaReboteBolas)
    {
        if (DTablaReboteBolas->objectName().isEmpty())
            DTablaReboteBolas->setObjectName(QString::fromUtf8("DTablaReboteBolas"));
        DTablaReboteBolas->resize(641, 391);
        layoutWidget = new QWidget(DTablaReboteBolas);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 621, 381));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(9, 9, 9, 9);
        tablaReboteBolas = new QTableView(layoutWidget);
        tablaReboteBolas->setObjectName(QString::fromUtf8("tablaReboteBolas"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tablaReboteBolas->sizePolicy().hasHeightForWidth());
        tablaReboteBolas->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(tablaReboteBolas);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy1);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DTablaReboteBolas);
        QObject::connect(buttonBox, SIGNAL(accepted()), DTablaReboteBolas, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DTablaReboteBolas, SLOT(reject()));

        QMetaObject::connectSlotsByName(DTablaReboteBolas);
    } // setupUi

    void retranslateUi(QDialog *DTablaReboteBolas)
    {
        DTablaReboteBolas->setWindowTitle(QCoreApplication::translate("DTablaReboteBolas", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DTablaReboteBolas: public Ui_DTablaReboteBolas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DTABLAREBOTEBOLAS_H
