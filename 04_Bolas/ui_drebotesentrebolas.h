/********************************************************************************
** Form generated from reading UI file 'drebotesentrebolas.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DREBOTESENTREBOLAS_H
#define UI_DREBOTESENTREBOLAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DRebotesEntreBolas
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTableView *tablaRebotesBolas;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DRebotesEntreBolas)
    {
        if (DRebotesEntreBolas->objectName().isEmpty())
            DRebotesEntreBolas->setObjectName(QString::fromUtf8("DRebotesEntreBolas"));
        DRebotesEntreBolas->resize(427, 316);
        widget = new QWidget(DRebotesEntreBolas);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 401, 291));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tablaRebotesBolas = new QTableView(widget);
        tablaRebotesBolas->setObjectName(QString::fromUtf8("tablaRebotesBolas"));

        verticalLayout->addWidget(tablaRebotesBolas);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DRebotesEntreBolas);
        QObject::connect(buttonBox, SIGNAL(accepted()), DRebotesEntreBolas, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DRebotesEntreBolas, SLOT(reject()));

        QMetaObject::connectSlotsByName(DRebotesEntreBolas);
    } // setupUi

    void retranslateUi(QDialog *DRebotesEntreBolas)
    {
        DRebotesEntreBolas->setWindowTitle(QCoreApplication::translate("DRebotesEntreBolas", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DRebotesEntreBolas: public Ui_DRebotesEntreBolas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DREBOTESENTREBOLAS_H
