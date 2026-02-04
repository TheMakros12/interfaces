/********************************************************************************
** Form generated from reading UI file 'dtablaassays.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DTABLAASSAYS_H
#define UI_DTABLAASSAYS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DTablaAssays
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTableView *tablaAssays;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DTablaAssays)
    {
        if (DTablaAssays->objectName().isEmpty())
            DTablaAssays->setObjectName(QString::fromUtf8("DTablaAssays"));
        DTablaAssays->resize(605, 407);
        layoutWidget = new QWidget(DTablaAssays);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 581, 391));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tablaAssays = new QTableView(layoutWidget);
        tablaAssays->setObjectName(QString::fromUtf8("tablaAssays"));

        verticalLayout->addWidget(tablaAssays);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DTablaAssays);
        QObject::connect(buttonBox, SIGNAL(accepted()), DTablaAssays, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DTablaAssays, SLOT(reject()));

        QMetaObject::connectSlotsByName(DTablaAssays);
    } // setupUi

    void retranslateUi(QDialog *DTablaAssays)
    {
        DTablaAssays->setWindowTitle(QCoreApplication::translate("DTablaAssays", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DTablaAssays: public Ui_DTablaAssays {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DTABLAASSAYS_H
