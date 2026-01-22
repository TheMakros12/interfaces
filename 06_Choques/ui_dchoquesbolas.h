/********************************************************************************
** Form generated from reading UI file 'dchoquesbolas.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DCHOQUESBOLAS_H
#define UI_DCHOQUESBOLAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DChoquesBolas
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTableView *tablaChoques;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DChoquesBolas)
    {
        if (DChoquesBolas->objectName().isEmpty())
            DChoquesBolas->setObjectName(QString::fromUtf8("DChoquesBolas"));
        DChoquesBolas->resize(616, 430);
        layoutWidget = new QWidget(DChoquesBolas);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 591, 411));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tablaChoques = new QTableView(layoutWidget);
        tablaChoques->setObjectName(QString::fromUtf8("tablaChoques"));

        verticalLayout->addWidget(tablaChoques);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DChoquesBolas);
        QObject::connect(buttonBox, SIGNAL(accepted()), DChoquesBolas, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DChoquesBolas, SLOT(reject()));

        QMetaObject::connectSlotsByName(DChoquesBolas);
    } // setupUi

    void retranslateUi(QDialog *DChoquesBolas)
    {
        DChoquesBolas->setWindowTitle(QCoreApplication::translate("DChoquesBolas", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DChoquesBolas: public Ui_DChoquesBolas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DCHOQUESBOLAS_H
