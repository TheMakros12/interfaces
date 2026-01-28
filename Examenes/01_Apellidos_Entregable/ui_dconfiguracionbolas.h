/********************************************************************************
** Form generated from reading UI file 'dconfiguracionbolas.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DCONFIGURACIONBOLAS_H
#define UI_DCONFIGURACIONBOLAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DConfiguracionBolas
{
public:
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QPushButton *bPararTodas;
    QCheckBox *chActivoParar;

    void setupUi(QDialog *DConfiguracionBolas)
    {
        if (DConfiguracionBolas->objectName().isEmpty())
            DConfiguracionBolas->setObjectName(QString::fromUtf8("DConfiguracionBolas"));
        DConfiguracionBolas->resize(901, 572);
        buttonBox = new QDialogButtonBox(DConfiguracionBolas);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(470, 490, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tabWidget = new QTabWidget(DConfiguracionBolas);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(30, 30, 811, 401));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        bPararTodas = new QPushButton(DConfiguracionBolas);
        bPararTodas->setObjectName(QString::fromUtf8("bPararTodas"));
        bPararTodas->setGeometry(QRect(30, 470, 88, 34));
        chActivoParar = new QCheckBox(DConfiguracionBolas);
        chActivoParar->setObjectName(QString::fromUtf8("chActivoParar"));
        chActivoParar->setGeometry(QRect(140, 480, 171, 22));
        chActivoParar->setChecked(true);

        retranslateUi(DConfiguracionBolas);
        QObject::connect(buttonBox, SIGNAL(accepted()), DConfiguracionBolas, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DConfiguracionBolas, SLOT(reject()));

        QMetaObject::connectSlotsByName(DConfiguracionBolas);
    } // setupUi

    void retranslateUi(QDialog *DConfiguracionBolas)
    {
        DConfiguracionBolas->setWindowTitle(QCoreApplication::translate("DConfiguracionBolas", "Dialog", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("DConfiguracionBolas", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("DConfiguracionBolas", "Tab 2", nullptr));
        bPararTodas->setText(QCoreApplication::translate("DConfiguracionBolas", "PararTodas", nullptr));
        chActivoParar->setText(QCoreApplication::translate("DConfiguracionBolas", "Activar Parar Bolas", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DConfiguracionBolas: public Ui_DConfiguracionBolas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DCONFIGURACIONBOLAS_H
