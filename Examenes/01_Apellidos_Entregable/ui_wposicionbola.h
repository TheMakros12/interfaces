/********************************************************************************
** Form generated from reading UI file 'wposicionbola.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WPOSICIONBOLA_H
#define UI_WPOSICIONBOLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WPosicionBola
{
public:
    QFrame *fPanel;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *labelito;
    QCheckBox *chControl;

    void setupUi(QWidget *WPosicionBola)
    {
        if (WPosicionBola->objectName().isEmpty())
            WPosicionBola->setObjectName(QString::fromUtf8("WPosicionBola"));
        WPosicionBola->resize(400, 300);
        fPanel = new QFrame(WPosicionBola);
        fPanel->setObjectName(QString::fromUtf8("fPanel"));
        fPanel->setGeometry(QRect(0, 0, 261, 281));
        fPanel->setFrameShape(QFrame::StyledPanel);
        fPanel->setFrameShadow(QFrame::Raised);
        widget = new QWidget(WPosicionBola);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(310, 20, 69, 48));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelito = new QLabel(widget);
        labelito->setObjectName(QString::fromUtf8("labelito"));

        verticalLayout->addWidget(labelito);

        chControl = new QCheckBox(widget);
        chControl->setObjectName(QString::fromUtf8("chControl"));

        verticalLayout->addWidget(chControl);


        retranslateUi(WPosicionBola);

        QMetaObject::connectSlotsByName(WPosicionBola);
    } // setupUi

    void retranslateUi(QWidget *WPosicionBola)
    {
        WPosicionBola->setWindowTitle(QCoreApplication::translate("WPosicionBola", "Form", nullptr));
        labelito->setText(QCoreApplication::translate("WPosicionBola", "TextLabel", nullptr));
        chControl->setText(QCoreApplication::translate("WPosicionBola", "Control", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WPosicionBola: public Ui_WPosicionBola {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WPOSICIONBOLA_H
