/********************************************************************************
** Form generated from reading UI file 'dinformacion.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DINFORMACION_H
#define UI_DINFORMACION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DInformacion
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *lblDimensiones;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *lblNumBolas;

    void setupUi(QDialog *DInformacion)
    {
        if (DInformacion->objectName().isEmpty())
            DInformacion->setObjectName(QString::fromUtf8("DInformacion"));
        DInformacion->resize(400, 243);
        buttonBox = new QDialogButtonBox(DInformacion);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 190, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(DInformacion);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(70, 30, 261, 131));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lblDimensiones = new QLabel(widget);
        lblDimensiones->setObjectName(QString::fromUtf8("lblDimensiones"));
        QFont font1;
        font1.setPointSize(12);
        lblDimensiones->setFont(font1);

        horizontalLayout->addWidget(lblDimensiones);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        lblNumBolas = new QLabel(widget);
        lblNumBolas->setObjectName(QString::fromUtf8("lblNumBolas"));
        lblNumBolas->setFont(font1);

        horizontalLayout_2->addWidget(lblNumBolas);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(DInformacion);
        QObject::connect(buttonBox, SIGNAL(accepted()), DInformacion, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DInformacion, SLOT(reject()));

        QMetaObject::connectSlotsByName(DInformacion);
    } // setupUi

    void retranslateUi(QDialog *DInformacion)
    {
        DInformacion->setWindowTitle(QCoreApplication::translate("DInformacion", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DInformacion", "Tama\303\261o del Juego:", nullptr));
        lblDimensiones->setText(QCoreApplication::translate("DInformacion", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("DInformacion", "N\303\272mero de Bolas: ", nullptr));
        lblNumBolas->setText(QCoreApplication::translate("DInformacion", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DInformacion: public Ui_DInformacion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DINFORMACION_H
