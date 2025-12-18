#include "dsecundario.h"

#include <QHBoxLayout>
#include <QListWidgetItem>
#include <QListWidget>


DSecundario::DSecundario(QString nombre, QWidget *parent) : QDialog(parent) {

    listaNombres = new QListWidget(this);
    listaNombres->clear();

    slider = new QSlider(Qt::Vertical);
    slider->setRange(0,10);
    slider->setValue(listaNombres->count());

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(listaNombres);
    mainLayout->addWidget(slider);
    setLayout(mainLayout);

    connect(listaNombres, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(seleccionarNombre()));

}

void DSecundario::anyadirNombre(const QString &nombre) {

    if (listaNombres->count() >= slider->maximum()) {
        return;
    }

    listaNombres->addItem(nombre);
    actualizarSlider();

}

void DSecundario::actualizarSlider() {
    slider->setValue(listaNombres->count());
}

void DSecundario::seleccionarNombre() {

    QListWidgetItem *item = listaNombres->currentItem();
    if (item) {
        emit nombreSeleccionado(item->text());
    }

}
