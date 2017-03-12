#include <QPixmap>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include "pixmap.h"

Pixmap::Pixmap(QWidget *parent)
    : QWidget(parent) {

  QHBoxLayout *hbox = new QHBoxLayout(this);
  
  QPixmap pixmap("bojnice.jpg");
  
  QLabel *label = new QLabel(this);
  label->setPixmap(pixmap);

  hbox->addWidget(label, 0, Qt::AlignTop);
}