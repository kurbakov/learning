### Note: in NAME.pro we need to add the following line
```
QT += gui widgets
```

### Dependencies
```c++
#include <QApplication>
#include <QWidget>
#include <QIcon>
#include <QFrame>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
```
### QApplicationqt [doc]()
  ```c++
  QApplication app(argc, argv); // for all Qt applications
  return app.execute(); // in main function
  ```
  - .execute()
  
### QWidget [doc]()
  ```c++
  QWidget window;
  ```
  - .resize(int, int)
  - .setWindowTitle(str)
  - .show()
  - .move()
  - .setToolTip(str)
  - .setWindowIcon(path/to/file)
  
### QFrame [doc]()
  ```c++
  Qframe *f = new QFrame(this);
  ```
  - ->setFrameStyle(style) // stype -> QFrame::Box
  - ->setCursor(cursor) // cursors -> Qt::SizeAllCursor, Qt::QaitCursor, Qt::PointingHandCursor

### QGridLayout [doc]()
  ```c++
  QGridLayout *l = new QGridLayout(this);
  ```
  - ->addWidget(QFrame, int, int)
  - setLayout(QGridLayout) // void function

### QPushButton [doc]()
  ```c++
  QPushButton *b = new QPushButton("Button name", this);
  ```
  - ->setGeometry(int, int, int, int)
  - connect(QPushButton, , &QPushButton::clicked, this, pointer_to_function)
  
### QLabel [doc]()
  ```c++
  QLable *l;
  ```
  
