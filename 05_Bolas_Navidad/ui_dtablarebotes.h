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
    QWidget *layoutWidget;
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
        DTablaRebotes->resize(398, 336);
        layoutWidget = new QWidget(DTablaRebotes);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 9, 381, 321));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tablaRebotes = new QTableView(layoutWidget);
        tablaRebotes->setObjectName(QString::fromUtf8("tablaRebotes"));

        verticalLayout->addWidget(tablaRebotes);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnRestablecerRebotes = new QPushButton(layoutWidget);
        btnRestablecerRebotes->setObjectName(QString::fromUtf8("btnRestablecerRebotes"));

        horizontalLayout->addWidget(btnRestablecerRebotes);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(layoutWidget);
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
