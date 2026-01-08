/********************************************************************************
** Form generated from reading UI file 'dconfiguracionbola.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DCONFIGURACIONBOLA_H
#define UI_DCONFIGURACIONBOLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DConfiguracionBola
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPararTodas;
    QCheckBox *cbActivarBotones;
    QWidget *tab_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DConfiguracionBola)
    {
        if (DConfiguracionBola->objectName().isEmpty())
            DConfiguracionBola->setObjectName(QString::fromUtf8("DConfiguracionBola"));
        DConfiguracionBola->resize(694, 407);
        widget = new QWidget(DConfiguracionBola);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 0, 441, 391));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayoutWidget = new QWidget(tab);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 280, 439, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnPararTodas = new QPushButton(horizontalLayoutWidget);
        btnPararTodas->setObjectName(QString::fromUtf8("btnPararTodas"));

        horizontalLayout->addWidget(btnPararTodas);

        cbActivarBotones = new QCheckBox(horizontalLayoutWidget);
        cbActivarBotones->setObjectName(QString::fromUtf8("cbActivarBotones"));

        horizontalLayout->addWidget(cbActivarBotones);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DConfiguracionBola);
        QObject::connect(buttonBox, SIGNAL(accepted()), DConfiguracionBola, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DConfiguracionBola, SLOT(reject()));

        QMetaObject::connectSlotsByName(DConfiguracionBola);
    } // setupUi

    void retranslateUi(QDialog *DConfiguracionBola)
    {
        DConfiguracionBola->setWindowTitle(QCoreApplication::translate("DConfiguracionBola", "Dialog", nullptr));
        btnPararTodas->setText(QCoreApplication::translate("DConfiguracionBola", "Parar Todas", nullptr));
        cbActivarBotones->setText(QCoreApplication::translate("DConfiguracionBola", "Activar Bot\303\263n Parar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("DConfiguracionBola", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("DConfiguracionBola", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DConfiguracionBola: public Ui_DConfiguracionBola {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DCONFIGURACIONBOLA_H
