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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetDetalleBola
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *leNuevoNombre;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSlider *slRojo;
    QLabel *lblIntRojo;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSlider *slVerde;
    QLabel *lblIntVerde;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSlider *slAzul;
    QLabel *lblIntAzul;
    QPushButton *btnPararBola;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lblNombreBola;

    void setupUi(QWidget *WidgetDetalleBola)
    {
        if (WidgetDetalleBola->objectName().isEmpty())
            WidgetDetalleBola->setObjectName(QString::fromUtf8("WidgetDetalleBola"));
        WidgetDetalleBola->resize(387, 296);
        layoutWidget = new QWidget(WidgetDetalleBola);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 40, 281, 201));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        leNuevoNombre = new QLineEdit(layoutWidget);
        leNuevoNombre->setObjectName(QString::fromUtf8("leNuevoNombre"));

        horizontalLayout->addWidget(leNuevoNombre);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        slRojo = new QSlider(layoutWidget);
        slRojo->setObjectName(QString::fromUtf8("slRojo"));
        slRojo->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(slRojo);

        lblIntRojo = new QLabel(layoutWidget);
        lblIntRojo->setObjectName(QString::fromUtf8("lblIntRojo"));

        horizontalLayout_2->addWidget(lblIntRojo);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        slVerde = new QSlider(layoutWidget);
        slVerde->setObjectName(QString::fromUtf8("slVerde"));
        slVerde->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(slVerde);

        lblIntVerde = new QLabel(layoutWidget);
        lblIntVerde->setObjectName(QString::fromUtf8("lblIntVerde"));

        horizontalLayout_3->addWidget(lblIntVerde);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        slAzul = new QSlider(layoutWidget);
        slAzul->setObjectName(QString::fromUtf8("slAzul"));
        slAzul->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(slAzul);

        lblIntAzul = new QLabel(layoutWidget);
        lblIntAzul->setObjectName(QString::fromUtf8("lblIntAzul"));

        horizontalLayout_4->addWidget(lblIntAzul);


        verticalLayout->addLayout(horizontalLayout_4);

        btnPararBola = new QPushButton(layoutWidget);
        btnPararBola->setObjectName(QString::fromUtf8("btnPararBola"));

        verticalLayout->addWidget(btnPararBola);


        verticalLayout_2->addLayout(verticalLayout);

        layoutWidget_2 = new QWidget(WidgetDetalleBola);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(100, 10, 205, 23));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        lblNombreBola = new QLabel(layoutWidget_2);
        lblNombreBola->setObjectName(QString::fromUtf8("lblNombreBola"));
        lblNombreBola->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(lblNombreBola);


        retranslateUi(WidgetDetalleBola);

        QMetaObject::connectSlotsByName(WidgetDetalleBola);
    } // setupUi

    void retranslateUi(QWidget *WidgetDetalleBola)
    {
        WidgetDetalleBola->setWindowTitle(QCoreApplication::translate("WidgetDetalleBola", "Form", nullptr));
        label->setText(QCoreApplication::translate("WidgetDetalleBola", "NUevo nombre:", nullptr));
        label_2->setText(QCoreApplication::translate("WidgetDetalleBola", "Rojo:", nullptr));
        lblIntRojo->setText(QCoreApplication::translate("WidgetDetalleBola", "0", nullptr));
        label_3->setText(QCoreApplication::translate("WidgetDetalleBola", "Verde:", nullptr));
        lblIntVerde->setText(QCoreApplication::translate("WidgetDetalleBola", "0", nullptr));
        label_4->setText(QCoreApplication::translate("WidgetDetalleBola", "Azul", nullptr));
        lblIntAzul->setText(QCoreApplication::translate("WidgetDetalleBola", "0", nullptr));
        btnPararBola->setText(QCoreApplication::translate("WidgetDetalleBola", "Parar Bola", nullptr));
        lblNombreBola->setText(QCoreApplication::translate("WidgetDetalleBola", "Nombre", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetDetalleBola: public Ui_WidgetDetalleBola {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETDETALLEBOLA_H
