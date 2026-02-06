/********************************************************************************
** Form generated from reading UI file 'ddocument.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DDOCUMENT_H
#define UI_DDOCUMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DDocuent
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *lblDocumentTitle;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QTextBrowser *txtAuthors;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QTextBrowser *txtJournalFullTitle;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QTextBrowser *txtAbstract;

    void setupUi(QDialog *DDocuent)
    {
        if (DDocuent->objectName().isEmpty())
            DDocuent->setObjectName(QString::fromUtf8("DDocuent"));
        DDocuent->resize(872, 718);
        buttonBox = new QDialogButtonBox(DDocuent);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(40, 670, 811, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(DDocuent);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 10, 831, 642));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lblDocumentTitle = new QLabel(widget);
        lblDocumentTitle->setObjectName(QString::fromUtf8("lblDocumentTitle"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        lblDocumentTitle->setFont(font);
        lblDocumentTitle->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblDocumentTitle);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(2);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(14);
        label_2->setFont(font1);
        label_2->setFrameShape(QFrame::NoFrame);
        label_2->setFrameShadow(QFrame::Plain);

        horizontalLayout->addWidget(label_2);

        txtAuthors = new QTextBrowser(widget);
        txtAuthors->setObjectName(QString::fromUtf8("txtAuthors"));
        txtAuthors->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(200);
        sizePolicy1.setHeightForWidth(txtAuthors->sizePolicy().hasHeightForWidth());
        txtAuthors->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(txtAuthors);

        horizontalLayout->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        horizontalLayout_2->addWidget(label_3);

        txtJournalFullTitle = new QTextBrowser(widget);
        txtJournalFullTitle->setObjectName(QString::fromUtf8("txtJournalFullTitle"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(txtJournalFullTitle->sizePolicy().hasHeightForWidth());
        txtJournalFullTitle->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(txtJournalFullTitle);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_3->addWidget(label_4);

        txtAbstract = new QTextBrowser(widget);
        txtAbstract->setObjectName(QString::fromUtf8("txtAbstract"));

        horizontalLayout_3->addWidget(txtAbstract);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 6);

        retranslateUi(DDocuent);
        QObject::connect(buttonBox, SIGNAL(accepted()), DDocuent, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DDocuent, SLOT(reject()));

        QMetaObject::connectSlotsByName(DDocuent);
    } // setupUi

    void retranslateUi(QDialog *DDocuent)
    {
        DDocuent->setWindowTitle(QCoreApplication::translate("DDocuent", "Dialog", nullptr));
        lblDocumentTitle->setText(QCoreApplication::translate("DDocuent", "Document Title", nullptr));
        label_2->setText(QCoreApplication::translate("DDocuent", "authors:", nullptr));
        label_3->setText(QCoreApplication::translate("DDocuent", "journal_full_title:", nullptr));
        label_4->setText(QCoreApplication::translate("DDocuent", "abstract:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DDocuent: public Ui_DDocuent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DDOCUMENT_H
