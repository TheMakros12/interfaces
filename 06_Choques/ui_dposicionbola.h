/********************************************************************************
** Form generated from reading UI file 'dposicionbola.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DPOSICIONBOLA_H
#define UI_DPOSICIONBOLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DPosicionBola
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabPosicion;
    QWidget *tab;
    QWidget *tab_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DPosicionBola)
    {
        if (DPosicionBola->objectName().isEmpty())
            DPosicionBola->setObjectName(QString::fromUtf8("DPosicionBola"));
        DPosicionBola->resize(486, 383);
        widget = new QWidget(DPosicionBola);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 471, 361));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabPosicion = new QTabWidget(widget);
        tabPosicion->setObjectName(QString::fromUtf8("tabPosicion"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabPosicion->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabPosicion->addTab(tab_2, QString());

        verticalLayout->addWidget(tabPosicion);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DPosicionBola);
        QObject::connect(buttonBox, SIGNAL(accepted()), DPosicionBola, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DPosicionBola, SLOT(reject()));

        QMetaObject::connectSlotsByName(DPosicionBola);
    } // setupUi

    void retranslateUi(QDialog *DPosicionBola)
    {
        DPosicionBola->setWindowTitle(QCoreApplication::translate("DPosicionBola", "Dialog", nullptr));
        tabPosicion->setTabText(tabPosicion->indexOf(tab), QCoreApplication::translate("DPosicionBola", "Tab 1", nullptr));
        tabPosicion->setTabText(tabPosicion->indexOf(tab_2), QCoreApplication::translate("DPosicionBola", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DPosicionBola: public Ui_DPosicionBola {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPOSICIONBOLA_H
