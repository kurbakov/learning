#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QSlider>
#include <QtWidgets/QLabel>

class Slider : public QWidget {
    
  Q_OBJECT
  
  public:
    Slider(QWidget *parent = 0);

  private:
    QSlider *slider; 
    QLabel *label;
};