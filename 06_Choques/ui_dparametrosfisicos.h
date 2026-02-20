/********************************************************************************
** Form generated from reading UI file 'dparametrosfisicos.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DPARAMETROSFISICOS_H
#define UI_DPARAMETROSFISICOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DParametrosFisicos
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSlider *slElasticidad;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSlider *slGravitacion;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSlider *slJugador;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *slRozamiento;

    void setupUi(QDialog *DParametrosFisicos)
    {
        if (DParametrosFisicos->objectName().isEmpty())
            DParametrosFisicos->setObjectName(QString::fromUtf8("DParametrosFisicos"));
        DParametrosFisicos->resize(358, 277);
        buttonBox = new QDialogButtonBox(DParametrosFisicos);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 230, 271, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(DParametrosFisicos);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 110, 291, 21));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        slElasticidad = new QSlider(layoutWidget);
        slElasticidad->setObjectName(QString::fromUtf8("slElasticidad"));
        slElasticidad->setMaximum(100);
        slElasticidad->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(slElasticidad);

        layoutWidget_2 = new QWidget(DParametrosFisicos);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 30, 291, 21));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        slGravitacion = new QSlider(layoutWidget_2);
        slGravitacion->setObjectName(QString::fromUtf8("slGravitacion"));
        slGravitacion->setMaximum(100);
        slGravitacion->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(slGravitacion);

        layoutWidget_3 = new QWidget(DParametrosFisicos);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(30, 150, 291, 21));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        slJugador = new QSlider(layoutWidget_3);
        slJugador->setObjectName(QString::fromUtf8("slJugador"));
        slJugador->setMaximum(100);
        slJugador->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(slJugador);

        layoutWidget1 = new QWidget(DParametrosFisicos);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 70, 291, 21));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        slRozamiento = new QSlider(layoutWidget1);
        slRozamiento->setObjectName(QString::fromUtf8("slRozamiento"));
        slRozamiento->setMaximum(100);
        slRozamiento->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(slRozamiento);


        retranslateUi(DParametrosFisicos);
        QObject::connect(buttonBox, SIGNAL(accepted()), DParametrosFisicos, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DParametrosFisicos, SLOT(reject()));

        QMetaObject::connectSlotsByName(DParametrosFisicos);
    } // setupUi

    void retranslateUi(QDialog *DParametrosFisicos)
    {
        DParametrosFisicos->setWindowTitle(QCoreApplication::translate("DParametrosFisicos", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("DParametrosFisicos", "Elasticidad: ", nullptr));
        label_3->setText(QCoreApplication::translate("DParametrosFisicos", "Gravitaci\303\263n: ", nullptr));
        label_4->setText(QCoreApplication::translate("DParametrosFisicos", "Jugador", nullptr));
        label->setText(QCoreApplication::translate("DParametrosFisicos", "Rozamiento: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DParametrosFisicos: public Ui_DParametrosFisicos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPARAMETROSFISICOS_H
