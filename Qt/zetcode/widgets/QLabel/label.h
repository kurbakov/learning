#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>

class Label : public QWidget {

  public:
    Label(QWidget *parent = 0);

  private:
    QLabel *label;
};