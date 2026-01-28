/********************************************************************************
** Form generated from reading UI file 'dtablaapellidos.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DTABLAAPELLIDOS_H
#define UI_DTABLAAPELLIDOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DTablaApellidos
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTableView *tablaApellidos;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DTablaApellidos)
    {
        if (DTablaApellidos->objectName().isEmpty())
            DTablaApellidos->setObjectName(QString::fromUtf8("DTablaApellidos"));
        DTablaApellidos->resize(1091, 664);
        widget = new QWidget(DTablaApellidos);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 1081, 651));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tablaApellidos = new QTableView(widget);
        tablaApellidos->setObjectName(QString::fromUtf8("tablaApellidos"));

        verticalLayout->addWidget(tablaApellidos);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DTablaApellidos);
        QObject::connect(buttonBox, SIGNAL(accepted()), DTablaApellidos, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DTablaApellidos, SLOT(reject()));

        QMetaObject::connectSlotsByName(DTablaApellidos);
    } // setupUi

    void retranslateUi(QDialog *DTablaApellidos)
    {
        DTablaApellidos->setWindowTitle(QCoreApplication::translate("DTablaApellidos", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DTablaApellidos: public Ui_DTablaApellidos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DTABLAAPELLIDOS_H
