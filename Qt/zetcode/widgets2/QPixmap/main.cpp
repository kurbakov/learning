#include <QtWidgets/QApplication>
#include "pixmap.h"

int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  
    
  Pixmap window;

  window.setWindowTitle("QPixmap");
  window.show();
  
  return app.exec();
}