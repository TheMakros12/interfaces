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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetBola
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnParar;
    QSpacerItem *verticalSpacer;
    QPushButton *btnMover;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btnColor;

    void setupUi(QWidget *WidgetBola)
    {
        if (WidgetBola->objectName().isEmpty())
            WidgetBola->setObjectName(QString::fromUtf8("WidgetBola"));
        WidgetBola->resize(301, 263);
        layoutWidget = new QWidget(WidgetBola);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 30, 131, 151));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
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


        retranslateUi(WidgetBola);

        QMetaObject::connectSlotsByName(WidgetBola);
    } // setupUi

    void retranslateUi(QWidget *WidgetBola)
    {
        WidgetBola->setWindowTitle(QCoreApplication::translate("WidgetBola", "Form", nullptr));
        btnParar->setText(QCoreApplication::translate("WidgetBola", "Parar", nullptr));
        btnMover->setText(QCoreApplication::translate("WidgetBola", "Mover", nullptr));
        btnColor->setText(QCoreApplication::translate("WidgetBola", "Color", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetBola: public Ui_WidgetBola {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETBOLA_H
