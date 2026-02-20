/********************************************************************************
** Form generated from reading UI file 'dtablarebotes.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DTABLAREBOTES_H
#define UI_DTABLAREBOTES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DTablaRebotes
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTableView *tablaRebotes;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnRestablecerRebotes;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DTablaRebotes)
    {
        if (DTablaRebotes->objectName().isEmpty())
            DTablaRebotes->setObjectName(QString::fromUtf8("DTablaRebotes"));
        DTablaRebotes->resize(482, 424);
        widget = new QWidget(DTablaRebotes);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 461, 401));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tablaRebotes = new QTableView(widget);
        tablaRebotes->setObjectName(QString::fromUtf8("tablaRebotes"));

        verticalLayout->addWidget(tablaRebotes);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(400, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnRestablecerRebotes = new QPushButton(widget);
        btnRestablecerRebotes->setObjectName(QString::fromUtf8("btnRestablecerRebotes"));

        horizontalLayout->addWidget(btnRestablecerRebotes);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DTablaRebotes);
        QObject::connect(buttonBox, SIGNAL(accepted()), DTablaRebotes, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DTablaRebotes, SLOT(reject()));

        QMetaObject::connectSlotsByName(DTablaRebotes);
    } // setupUi

    void retranslateUi(QDialog *DTablaRebotes)
    {
        DTablaRebotes->setWindowTitle(QCoreApplication::translate("DTablaRebotes", "Dialog", nullptr));
        btnRestablecerRebotes->setText(QCoreApplication::translate("DTablaRebotes", "Restablecer Rebotes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DTablaRebotes: public Ui_DTablaRebotes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DTABLAREBOTES_H
