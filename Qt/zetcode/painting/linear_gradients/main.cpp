#include <QApplication>
#include "linear_gradients.h"

int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  
    
  LinearGradients window;

  window.resize(350, 260);  
  window.setWindowTitle("Linear gradients");
  window.show();

  return app.exec();
}