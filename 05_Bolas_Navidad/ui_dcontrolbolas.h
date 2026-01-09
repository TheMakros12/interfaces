/********************************************************************************
** Form generated from reading UI file 'dcontrolbolas.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DCONTROLBOLAS_H
#define UI_DCONTROLBOLAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DControlBolas
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabBolas;
    QWidget *tab;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnMoverTodas;
    QPushButton *btnPararTodas;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QComboBox *cbTamanyoBolas;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DControlBolas)
    {
        if (DControlBolas->objectName().isEmpty())
            DControlBolas->setObjectName(QString::fromUtf8("DControlBolas"));
        DControlBolas->resize(589, 340);
        layoutWidget = new QWidget(DControlBolas);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 9, 571, 321));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabBolas = new QTabWidget(layoutWidget);
        tabBolas->setObjectName(QString::fromUtf8("tabBolas"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabBolas->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabBolas->addTab(tab_2, QString());

        verticalLayout->addWidget(tabBolas);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnMoverTodas = new QPushButton(layoutWidget);
        btnMoverTodas->setObjectName(QString::fromUtf8("btnMoverTodas"));

        horizontalLayout_2->addWidget(btnMoverTodas);

        btnPararTodas = new QPushButton(layoutWidget);
        btnPararTodas->setObjectName(QString::fromUtf8("btnPararTodas"));

        horizontalLayout_2->addWidget(btnPararTodas);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        cbTamanyoBolas = new QComboBox(layoutWidget);
        cbTamanyoBolas->addItem(QString());
        cbTamanyoBolas->addItem(QString());
        cbTamanyoBolas->addItem(QString());
        cbTamanyoBolas->setObjectName(QString::fromUtf8("cbTamanyoBolas"));

        horizontalLayout_2->addWidget(cbTamanyoBolas);


        verticalLayout->addLayout(horizontalLayout_2);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DControlBolas);
        QObject::connect(buttonBox, SIGNAL(accepted()), DControlBolas, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DControlBolas, SLOT(reject()));

        tabBolas->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(DControlBolas);
    } // setupUi

    void retranslateUi(QDialog *DControlBolas)
    {
        DControlBolas->setWindowTitle(QCoreApplication::translate("DControlBolas", "Dialog", nullptr));
        tabBolas->setTabText(tabBolas->indexOf(tab), QCoreApplication::translate("DControlBolas", "Tab 1", nullptr));
        tabBolas->setTabText(tabBolas->indexOf(tab_2), QCoreApplication::translate("DControlBolas", "Tab 2", nullptr));
        btnMoverTodas->setText(QCoreApplication::translate("DControlBolas", "Mover Bolas", nullptr));
        btnPararTodas->setText(QCoreApplication::translate("DControlBolas", "Parar Bolas", nullptr));
        label->setText(QCoreApplication::translate("DControlBolas", "Tama\303\261o de las Bolas", nullptr));
        cbTamanyoBolas->setItemText(0, QCoreApplication::translate("DControlBolas", "Peque\303\261as", nullptr));
        cbTamanyoBolas->setItemText(1, QCoreApplication::translate("DControlBolas", "Normales", nullptr));
        cbTamanyoBolas->setItemText(2, QCoreApplication::translate("DControlBolas", "Grandes", nullptr));

    } // retranslateUi

};

namespace Ui {
    class DControlBolas: public Ui_DControlBolas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DCONTROLBOLAS_H
