/********************************************************************************
** Form generated from reading UI file 'dinfobolas.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DINFOBOLAS_H
#define UI_DINFOBOLAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DInfoBolas
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listaBolas;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DInfoBolas)
    {
        if (DInfoBolas->objectName().isEmpty())
            DInfoBolas->setObjectName(QString::fromUtf8("DInfoBolas"));
        DInfoBolas->resize(428, 300);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DInfoBolas->sizePolicy().hasHeightForWidth());
        DInfoBolas->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(DInfoBolas);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listaBolas = new QListWidget(DInfoBolas);
        listaBolas->setObjectName(QString::fromUtf8("listaBolas"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listaBolas->sizePolicy().hasHeightForWidth());
        listaBolas->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(listaBolas);

        buttonBox = new QDialogButtonBox(DInfoBolas);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DInfoBolas);
        QObject::connect(buttonBox, SIGNAL(accepted()), DInfoBolas, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DInfoBolas, SLOT(reject()));

        QMetaObject::connectSlotsByName(DInfoBolas);
    } // setupUi

    void retranslateUi(QDialog *DInfoBolas)
    {
        DInfoBolas->setWindowTitle(QCoreApplication::translate("DInfoBolas", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DInfoBolas: public Ui_DInfoBolas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DINFOBOLAS_H
