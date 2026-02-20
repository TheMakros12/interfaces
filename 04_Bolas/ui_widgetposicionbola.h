/********************************************************************************
** Form generated from reading UI file 'widgetposicionbola.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETPOSICIONBOLA_H
#define UI_WIDGETPOSICIONBOLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetPosicionBola
{
public:
    QFrame *framePosicion;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QCheckBox *checkBox;

    void setupUi(QWidget *WidgetPosicionBola)
    {
        if (WidgetPosicionBola->objectName().isEmpty())
            WidgetPosicionBola->setObjectName(QString::fromUtf8("WidgetPosicionBola"));
        WidgetPosicionBola->resize(469, 269);
        framePosicion = new QFrame(WidgetPosicionBola);
        framePosicion->setObjectName(QString::fromUtf8("framePosicion"));
        framePosicion->setGeometry(QRect(10, 10, 271, 241));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(framePosicion->sizePolicy().hasHeightForWidth());
        framePosicion->setSizePolicy(sizePolicy);
        framePosicion->setFrameShape(QFrame::StyledPanel);
        framePosicion->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(WidgetPosicionBola);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(330, 50, 94, 52));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout->addWidget(checkBox);


        retranslateUi(WidgetPosicionBola);

        QMetaObject::connectSlotsByName(WidgetPosicionBola);
    } // setupUi

    void retranslateUi(QWidget *WidgetPosicionBola)
    {
        WidgetPosicionBola->setWindowTitle(QCoreApplication::translate("WidgetPosicionBola", "Form", nullptr));
        label->setText(QCoreApplication::translate("WidgetPosicionBola", "TextLabel", nullptr));
        checkBox->setText(QCoreApplication::translate("WidgetPosicionBola", "CheckBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetPosicionBola: public Ui_WidgetPosicionBola {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETPOSICIONBOLA_H
