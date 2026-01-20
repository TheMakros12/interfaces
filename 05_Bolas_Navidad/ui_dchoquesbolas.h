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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DChoquesBolas
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabChoques;
    QWidget *tab;
    QWidget *tab_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DChoquesBolas)
    {
        if (DChoquesBolas->objectName().isEmpty())
            DChoquesBolas->setObjectName(QString::fromUtf8("DChoquesBolas"));
        DChoquesBolas->resize(460, 380);
        layoutWidget = new QWidget(DChoquesBolas);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 441, 361));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabChoques = new QTabWidget(layoutWidget);
        tabChoques->setObjectName(QString::fromUtf8("tabChoques"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabChoques->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabChoques->addTab(tab_2, QString());

        verticalLayout->addWidget(tabChoques);

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
        tabChoques->setTabText(tabChoques->indexOf(tab), QCoreApplication::translate("DChoquesBolas", "Tab 1", nullptr));
        tabChoques->setTabText(tabChoques->indexOf(tab_2), QCoreApplication::translate("DChoquesBolas", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DChoquesBolas: public Ui_DChoquesBolas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DCHOQUESBOLAS_H
