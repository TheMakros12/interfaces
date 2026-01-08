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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DConfiguracionBola
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPararTodas;
    QSpacerItem *horizontalSpacer;
    QCheckBox *cbActivarBotones;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DConfiguracionBola)
    {
        if (DConfiguracionBola->objectName().isEmpty())
            DConfiguracionBola->setObjectName(QString::fromUtf8("DConfiguracionBola"));
        DConfiguracionBola->resize(474, 400);
        layoutWidget = new QWidget(DConfiguracionBola);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 0, 441, 391));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(layoutWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnPararTodas = new QPushButton(layoutWidget);
        btnPararTodas->setObjectName(QString::fromUtf8("btnPararTodas"));

        horizontalLayout->addWidget(btnPararTodas);

        horizontalSpacer = new QSpacerItem(140, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cbActivarBotones = new QCheckBox(layoutWidget);
        cbActivarBotones->setObjectName(QString::fromUtf8("cbActivarBotones"));

        horizontalLayout->addWidget(cbActivarBotones);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(layoutWidget);
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
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("DConfiguracionBola", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("DConfiguracionBola", "Tab 2", nullptr));
        btnPararTodas->setText(QCoreApplication::translate("DConfiguracionBola", "Parar Todas", nullptr));
        cbActivarBotones->setText(QCoreApplication::translate("DConfiguracionBola", "Activar Bot\303\263n Parar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DConfiguracionBola: public Ui_DConfiguracionBola {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DCONFIGURACIONBOLA_H
