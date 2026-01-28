/********************************************************************************
** Form generated from reading UI file 'widgetdetallebola.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETDETALLEBOLA_H
#define UI_WIDGETDETALLEBOLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetDetalleBola
{
public:
    QLabel *lNombre;
    QLineEdit *lePosX;
    QSlider *slAzul;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QSlider *slRojo;
    QSlider *slVerde;
    QLabel *label_4;
    QPushButton *bParar;

    void setupUi(QWidget *WidgetDetalleBola)
    {
        if (WidgetDetalleBola->objectName().isEmpty())
            WidgetDetalleBola->setObjectName(QString::fromUtf8("WidgetDetalleBola"));
        WidgetDetalleBola->resize(400, 300);
        lNombre = new QLabel(WidgetDetalleBola);
        lNombre->setObjectName(QString::fromUtf8("lNombre"));
        lNombre->setGeometry(QRect(140, 20, 111, 21));
        lePosX = new QLineEdit(WidgetDetalleBola);
        lePosX->setObjectName(QString::fromUtf8("lePosX"));
        lePosX->setGeometry(QRect(150, 53, 113, 32));
        slAzul = new QSlider(WidgetDetalleBola);
        slAzul->setObjectName(QString::fromUtf8("slAzul"));
        slAzul->setGeometry(QRect(120, 160, 160, 20));
        slAzul->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(WidgetDetalleBola);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 130, 51, 21));
        label = new QLabel(WidgetDetalleBola);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 60, 111, 21));
        label_2 = new QLabel(WidgetDetalleBola);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 100, 51, 21));
        slRojo = new QSlider(WidgetDetalleBola);
        slRojo->setObjectName(QString::fromUtf8("slRojo"));
        slRojo->setGeometry(QRect(120, 100, 160, 20));
        slRojo->setOrientation(Qt::Horizontal);
        slVerde = new QSlider(WidgetDetalleBola);
        slVerde->setObjectName(QString::fromUtf8("slVerde"));
        slVerde->setGeometry(QRect(120, 130, 160, 20));
        slVerde->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(WidgetDetalleBola);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 160, 51, 21));
        bParar = new QPushButton(WidgetDetalleBola);
        bParar->setObjectName(QString::fromUtf8("bParar"));
        bParar->setGeometry(QRect(300, 200, 88, 34));

        retranslateUi(WidgetDetalleBola);

        QMetaObject::connectSlotsByName(WidgetDetalleBola);
    } // setupUi

    void retranslateUi(QWidget *WidgetDetalleBola)
    {
        WidgetDetalleBola->setWindowTitle(QCoreApplication::translate("WidgetDetalleBola", "Form", nullptr));
        lNombre->setText(QCoreApplication::translate("WidgetDetalleBola", "Posicion X", nullptr));
        label_3->setText(QCoreApplication::translate("WidgetDetalleBola", "Verde", nullptr));
        label->setText(QCoreApplication::translate("WidgetDetalleBola", "Posicion X", nullptr));
        label_2->setText(QCoreApplication::translate("WidgetDetalleBola", "Rojo", nullptr));
        label_4->setText(QCoreApplication::translate("WidgetDetalleBola", "Azul", nullptr));
        bParar->setText(QCoreApplication::translate("WidgetDetalleBola", "Parar Bola", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetDetalleBola: public Ui_WidgetDetalleBola {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETDETALLEBOLA_H
