/********************************************************************************
** Form generated from reading UI file 'dmenubolas.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DMENUBOLAS_H
#define UI_DMENUBOLAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DMenuBolas
{
public:
    QLabel *lblNombreBola;

    void setupUi(QDialog *DMenuBolas)
    {
        if (DMenuBolas->objectName().isEmpty())
            DMenuBolas->setObjectName(QString::fromUtf8("DMenuBolas"));
        DMenuBolas->resize(400, 300);
        lblNombreBola = new QLabel(DMenuBolas);
        lblNombreBola->setObjectName(QString::fromUtf8("lblNombreBola"));
        lblNombreBola->setGeometry(QRect(160, 120, 66, 19));

        retranslateUi(DMenuBolas);

        QMetaObject::connectSlotsByName(DMenuBolas);
    } // setupUi

    void retranslateUi(QDialog *DMenuBolas)
    {
        DMenuBolas->setWindowTitle(QCoreApplication::translate("DMenuBolas", "Dialog", nullptr));
        lblNombreBola->setText(QCoreApplication::translate("DMenuBolas", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DMenuBolas: public Ui_DMenuBolas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DMENUBOLAS_H
