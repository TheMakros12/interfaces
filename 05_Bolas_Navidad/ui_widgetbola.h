/********************************************************************************
** Form generated from reading UI file 'widgetbola.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETBOLA_H
#define UI_WIDGETBOLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetBola
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QPushButton *btnParar;
    QSpacerItem *verticalSpacer;
    QPushButton *btnMover;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btnColor;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *lblNombreBola;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QLabel *lblVidasBola;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lblColorBola;
    QLabel *lblBolaRed;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lblColorBola_3;
    QLabel *lblBolaGreen;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lblColorBola_5;
    QLabel *lblBolaBlue;

    void setupUi(QWidget *WidgetBola)
    {
        if (WidgetBola->objectName().isEmpty())
            WidgetBola->setObjectName(QString::fromUtf8("WidgetBola"));
        WidgetBola->resize(597, 290);
        layoutWidget = new QWidget(WidgetBola);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 30, 361, 171));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnParar = new QPushButton(layoutWidget);
        btnParar->setObjectName(QString::fromUtf8("btnParar"));

        verticalLayout->addWidget(btnParar);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btnMover = new QPushButton(layoutWidget);
        btnMover->setObjectName(QString::fromUtf8("btnMover"));

        verticalLayout->addWidget(btnMover);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        btnColor = new QPushButton(layoutWidget);
        btnColor->setObjectName(QString::fromUtf8("btnColor"));

        verticalLayout->addWidget(btnColor);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lblNombreBola = new QLabel(layoutWidget);
        lblNombreBola->setObjectName(QString::fromUtf8("lblNombreBola"));

        horizontalLayout->addWidget(lblNombreBola);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_7->addWidget(label_2);

        lblVidasBola = new QLabel(layoutWidget);
        lblVidasBola->setObjectName(QString::fromUtf8("lblVidasBola"));

        horizontalLayout_7->addWidget(lblVidasBola);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lblColorBola = new QLabel(layoutWidget);
        lblColorBola->setObjectName(QString::fromUtf8("lblColorBola"));

        horizontalLayout_4->addWidget(lblColorBola);

        lblBolaRed = new QLabel(layoutWidget);
        lblBolaRed->setObjectName(QString::fromUtf8("lblBolaRed"));

        horizontalLayout_4->addWidget(lblBolaRed);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lblColorBola_3 = new QLabel(layoutWidget);
        lblColorBola_3->setObjectName(QString::fromUtf8("lblColorBola_3"));

        horizontalLayout_5->addWidget(lblColorBola_3);

        lblBolaGreen = new QLabel(layoutWidget);
        lblBolaGreen->setObjectName(QString::fromUtf8("lblBolaGreen"));

        horizontalLayout_5->addWidget(lblBolaGreen);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lblColorBola_5 = new QLabel(layoutWidget);
        lblColorBola_5->setObjectName(QString::fromUtf8("lblColorBola_5"));

        horizontalLayout_6->addWidget(lblColorBola_5);

        lblBolaBlue = new QLabel(layoutWidget);
        lblBolaBlue->setObjectName(QString::fromUtf8("lblBolaBlue"));

        horizontalLayout_6->addWidget(lblBolaBlue);


        verticalLayout_3->addLayout(horizontalLayout_6);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(WidgetBola);

        QMetaObject::connectSlotsByName(WidgetBola);
    } // setupUi

    void retranslateUi(QWidget *WidgetBola)
    {
        WidgetBola->setWindowTitle(QCoreApplication::translate("WidgetBola", "Form", nullptr));
        btnParar->setText(QCoreApplication::translate("WidgetBola", "Parar", nullptr));
        btnMover->setText(QCoreApplication::translate("WidgetBola", "Mover", nullptr));
        btnColor->setText(QCoreApplication::translate("WidgetBola", "Color", nullptr));
        label->setText(QCoreApplication::translate("WidgetBola", "Nombre:", nullptr));
        lblNombreBola->setText(QCoreApplication::translate("WidgetBola", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("WidgetBola", "Vidas:", nullptr));
        lblVidasBola->setText(QCoreApplication::translate("WidgetBola", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("WidgetBola", "Color:", nullptr));
        lblColorBola->setText(QCoreApplication::translate("WidgetBola", "R: ", nullptr));
        lblBolaRed->setText(QCoreApplication::translate("WidgetBola", "Red", nullptr));
        lblColorBola_3->setText(QCoreApplication::translate("WidgetBola", "G:", nullptr));
        lblBolaGreen->setText(QCoreApplication::translate("WidgetBola", "Green", nullptr));
        lblColorBola_5->setText(QCoreApplication::translate("WidgetBola", "B:", nullptr));
        lblBolaBlue->setText(QCoreApplication::translate("WidgetBola", "Blue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetBola: public Ui_WidgetBola {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETBOLA_H
