### Dependencies
```c++
#include <QApplication>
#include <QDesktopWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QFormLayout>
#include <QLabel>
#include <QGridLayout>
```

### QTextEdit [doc](http://doc.qt.io/qt-5/QTextEdit.html)
  ```c++
  QTextEdit *ledit = new QTextEdit(this);
  ```
  - ->setGeometry(int, int, int, int);

### QVBoxLayout/QHBoxLayout [docV](http://doc.qt.io/qt-5/QVBoxLayout.html), [docH](http://doc.qt.io/qt-5/QHBoxLayout.html)
  ```c++
  QVBoxLayout *vbox = new QVBoxLayout(this);
  QHBoxLayout *hbox = new QHBoxLayout();
  ```
  - ->setSpacing(1)
  - ->addWidget(*QPushButton)
  
  
### QListWidget [doc](http://doc.qt.io/qt-5/QListWidget.html)
  ```c++
  QListWidget *lw = new QListWidget(this);
  ```
  - ->addItem(str)

### QLineEdit [doc](http://doc.qt.io/qt-5/QLineEdit.html)
  ```c++
  QLineEdit *nameEdit = new QLineEdit(this);
  ```
  
### QFormLayout [doc](http://doc.qt.io/qt-5/QFormLayout.html)
  ```c++
  QFormLayout *formLayout = new QFormLayout;
  ```
  - ->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter)
  - ->addRow(str, *QLineEdit)
  - setLayout(*QFormLayout)

### QGridLayout [doc](http://doc.qt.io/qt-5/QGridLayout.html)
  ```c++
  QGridLayout *grid = new QGridLayout(this);
  ```
  - ->setVerticalSpacing(int)
  - ->setHorizontalSpacing(int)
