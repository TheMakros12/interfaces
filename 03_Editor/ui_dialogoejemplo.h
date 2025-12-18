/********************************************************************************
** Form generated from reading UI file 'dialogoejemplo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOEJEMPLO_H
#define UI_DIALOGOEJEMPLO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogoEjemplo
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout;
    QPushButton *btn1;
    QPushButton *btn2;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogoEjemplo)
    {
        if (DialogoEjemplo->objectName().isEmpty())
            DialogoEjemplo->setObjectName(QString::fromUtf8("DialogoEjemplo"));
        DialogoEjemplo->resize(405, 212);
        verticalLayout_3 = new QVBoxLayout(DialogoEjemplo);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(DialogoEjemplo);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btn1 = new QPushButton(DialogoEjemplo);
        btn1->setObjectName(QString::fromUtf8("btn1"));

        verticalLayout->addWidget(btn1);

        btn2 = new QPushButton(DialogoEjemplo);
        btn2->setObjectName(QString::fromUtf8("btn2"));

        verticalLayout->addWidget(btn2);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout_3->addLayout(verticalLayout_2);

        buttonBox = new QDialogButtonBox(DialogoEjemplo);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(DialogoEjemplo);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogoEjemplo, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogoEjemplo, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogoEjemplo);
    } // setupUi

    void retranslateUi(QDialog *DialogoEjemplo)
    {
        DialogoEjemplo->setWindowTitle(QCoreApplication::translate("DialogoEjemplo", "Dialog", nullptr));
        btn1->setText(QCoreApplication::translate("DialogoEjemplo", "Bot\303\263n 1", nullptr));
        btn2->setText(QCoreApplication::translate("DialogoEjemplo", "Bot\303\263n 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogoEjemplo: public Ui_DialogoEjemplo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOEJEMPLO_H
