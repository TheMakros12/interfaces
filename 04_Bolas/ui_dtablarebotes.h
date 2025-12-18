/********************************************************************************
** Form generated from reading UI file 'dtablarebotes.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DTABLAREBOTES_H
#define UI_DTABLAREBOTES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DTablaRebotes
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tablaRebotes;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DTablaRebotes)
    {
        if (DTablaRebotes->objectName().isEmpty())
            DTablaRebotes->setObjectName(QString::fromUtf8("DTablaRebotes"));
        DTablaRebotes->resize(539, 396);
        verticalLayout = new QVBoxLayout(DTablaRebotes);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tablaRebotes = new QTableView(DTablaRebotes);
        tablaRebotes->setObjectName(QString::fromUtf8("tablaRebotes"));

        verticalLayout->addWidget(tablaRebotes);

        buttonBox = new QDialogButtonBox(DTablaRebotes);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DTablaRebotes);
        QObject::connect(buttonBox, SIGNAL(accepted()), DTablaRebotes, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DTablaRebotes, SLOT(reject()));

        QMetaObject::connectSlotsByName(DTablaRebotes);
    } // setupUi

    void retranslateUi(QDialog *DTablaRebotes)
    {
        DTablaRebotes->setWindowTitle(QCoreApplication::translate("DTablaRebotes", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DTablaRebotes: public Ui_DTablaRebotes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DTABLAREBOTES_H
