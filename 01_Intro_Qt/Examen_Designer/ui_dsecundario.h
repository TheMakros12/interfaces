/********************************************************************************
** Form generated from reading UI file 'dsecundario.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DSECUNDARIO_H
#define UI_DSECUNDARIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DSecundario
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QListWidget *listaNombres;
    QSlider *slider;

    void setupUi(QDialog *DSecundario)
    {
        if (DSecundario->objectName().isEmpty())
            DSecundario->setObjectName(QString::fromUtf8("DSecundario"));
        DSecundario->resize(298, 214);
        widget = new QWidget(DSecundario);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 279, 194));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listaNombres = new QListWidget(widget);
        listaNombres->setObjectName(QString::fromUtf8("listaNombres"));

        horizontalLayout->addWidget(listaNombres);

        slider = new QSlider(widget);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider);


        retranslateUi(DSecundario);

        QMetaObject::connectSlotsByName(DSecundario);
    } // setupUi

    void retranslateUi(QDialog *DSecundario)
    {
        DSecundario->setWindowTitle(QCoreApplication::translate("DSecundario", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DSecundario: public Ui_DSecundario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DSECUNDARIO_H
