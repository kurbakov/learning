#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>

class ComboBoxEx : public QWidget {
    
  Q_OBJECT
  
  public:
    ComboBoxEx(QWidget *parent = 0);

  private:
    QComboBox *combo; 
    QLabel *label;
};