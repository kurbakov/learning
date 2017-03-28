#pragma once

#include <QWidget>

class RadialGradient : public QWidget {

  public:
    RadialGradient(QWidget *parent = 0);

  protected:
    void paintEvent(QPaintEvent *e);
    
  private:
    void doPainting();  
};