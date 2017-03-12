#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QSpinBox>

class SpinBox : public QWidget {
    
  Q_OBJECT

  public:
    SpinBox(QWidget *parent = 0);

  private:
    QSpinBox *spinbox;
};