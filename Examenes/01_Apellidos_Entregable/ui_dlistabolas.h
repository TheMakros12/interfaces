/********************************************************************************
** Form generated from reading UI file 'dlistabolas.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLISTABOLAS_H
#define UI_DLISTABOLAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DListaBolas
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listaBolas;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DListaBolas)
    {
        if (DListaBolas->objectName().isEmpty())
            DListaBolas->setObjectName(QString::fromUtf8("DListaBolas"));
        DListaBolas->resize(643, 616);
        verticalLayout = new QVBoxLayout(DListaBolas);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listaBolas = new QListWidget(DListaBolas);
        listaBolas->setObjectName(QString::fromUtf8("listaBolas"));

        verticalLayout->addWidget(listaBolas);

        buttonBox = new QDialogButtonBox(DListaBolas);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DListaBolas);
        QObject::connect(buttonBox, SIGNAL(accepted()), DListaBolas, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DListaBolas, SLOT(reject()));

        QMetaObject::connectSlotsByName(DListaBolas);
    } // setupUi

    void retranslateUi(QDialog *DListaBolas)
    {
        DListaBolas->setWindowTitle(QCoreApplication::translate("DListaBolas", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DListaBolas: public Ui_DListaBolas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLISTABOLAS_H
