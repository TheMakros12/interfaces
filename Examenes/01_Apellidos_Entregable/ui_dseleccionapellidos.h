/********************************************************************************
** Form generated from reading UI file 'dseleccionapellidos.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DSELECCIONAPELLIDOS_H
#define UI_DSELECCIONAPELLIDOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DSeleccionApellidos
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listaNombres;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QListWidget *listaApellidos;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnPrimerApellido;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnSegundoApellido;
    QSpacerItem *verticalSpacer_2;
    QLabel *lblNombreCompleto;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DSeleccionApellidos)
    {
        if (DSeleccionApellidos->objectName().isEmpty())
            DSeleccionApellidos->setObjectName(QString::fromUtf8("DSeleccionApellidos"));
        DSeleccionApellidos->resize(642, 487);
        widget = new QWidget(DSeleccionApellidos);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 621, 461));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        listaNombres = new QListWidget(widget);
        listaNombres->setObjectName(QString::fromUtf8("listaNombres"));

        verticalLayout->addWidget(listaNombres);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        listaApellidos = new QListWidget(widget);
        listaApellidos->setObjectName(QString::fromUtf8("listaApellidos"));

        verticalLayout_2->addWidget(listaApellidos);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnPrimerApellido = new QPushButton(widget);
        btnPrimerApellido->setObjectName(QString::fromUtf8("btnPrimerApellido"));

        horizontalLayout_2->addWidget(btnPrimerApellido);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btnSegundoApellido = new QPushButton(widget);
        btnSegundoApellido->setObjectName(QString::fromUtf8("btnSegundoApellido"));

        horizontalLayout_2->addWidget(btnSegundoApellido);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        lblNombreCompleto = new QLabel(widget);
        lblNombreCompleto->setObjectName(QString::fromUtf8("lblNombreCompleto"));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        lblNombreCompleto->setFont(font1);
        lblNombreCompleto->setLayoutDirection(Qt::LeftToRight);
        lblNombreCompleto->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lblNombreCompleto);


        verticalLayout_4->addLayout(verticalLayout_3);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_4->addWidget(buttonBox);


        retranslateUi(DSeleccionApellidos);
        QObject::connect(buttonBox, SIGNAL(accepted()), DSeleccionApellidos, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DSeleccionApellidos, SLOT(reject()));

        QMetaObject::connectSlotsByName(DSeleccionApellidos);
    } // setupUi

    void retranslateUi(QDialog *DSeleccionApellidos)
    {
        DSeleccionApellidos->setWindowTitle(QCoreApplication::translate("DSeleccionApellidos", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DSeleccionApellidos", "Nombres:", nullptr));
        label_2->setText(QCoreApplication::translate("DSeleccionApellidos", "Apellidos:", nullptr));
        btnPrimerApellido->setText(QCoreApplication::translate("DSeleccionApellidos", "Sel. Primer Apellido", nullptr));
        btnSegundoApellido->setText(QCoreApplication::translate("DSeleccionApellidos", "Sel. Segundo Apellido", nullptr));
        lblNombreCompleto->setText(QCoreApplication::translate("DSeleccionApellidos", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DSeleccionApellidos: public Ui_DSeleccionApellidos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DSELECCIONAPELLIDOS_H
