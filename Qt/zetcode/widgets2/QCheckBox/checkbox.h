#pragma once

#include <QtWidgets/QWidget>

class CheckBox : public QWidget {
    
  Q_OBJECT

  public:
    CheckBox(QWidget *parent = 0);

  private slots:
    void showTitle(int);
};