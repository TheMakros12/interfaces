/********************************************************************************
** Form generated from reading UI file 'dialogoassay.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOASSAY_H
#define UI_DIALOGOASSAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_DialogoAssay
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *lblId;
    QTextBrowser *txtDescription;

    void setupUi(QDialog *DialogoAssay)
    {
        if (DialogoAssay->objectName().isEmpty())
            DialogoAssay->setObjectName(QString::fromUtf8("DialogoAssay"));
        DialogoAssay->resize(610, 345);
        buttonBox = new QDialogButtonBox(DialogoAssay);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(240, 290, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(DialogoAssay);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 131, 41));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(DialogoAssay);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 80, 131, 41));
        label_2->setFont(font);
        lblId = new QLabel(DialogoAssay);
        lblId->setObjectName(QString::fromUtf8("lblId"));
        lblId->setGeometry(QRect(200, 20, 131, 41));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        lblId->setFont(font1);
        txtDescription = new QTextBrowser(DialogoAssay);
        txtDescription->setObjectName(QString::fromUtf8("txtDescription"));
        txtDescription->setGeometry(QRect(160, 80, 441, 131));

        retranslateUi(DialogoAssay);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogoAssay, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogoAssay, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogoAssay);
    } // setupUi

    void retranslateUi(QDialog *DialogoAssay)
    {
        DialogoAssay->setWindowTitle(QCoreApplication::translate("DialogoAssay", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogoAssay", "assay_chembl_id:", nullptr));
        label_2->setText(QCoreApplication::translate("DialogoAssay", "description:", nullptr));
        lblId->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogoAssay: public Ui_DialogoAssay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOASSAY_H
