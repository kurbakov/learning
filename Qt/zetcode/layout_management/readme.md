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

### QTextEdit
  ```c++
  QTextEdit *ledit = new QTextEdit(this);
  ```
  - ->setGeometry(int, int, int, int);
### QVBoxLayout/QHBoxLayout
  ```c++
  QVBoxLayout *vbox = new QVBoxLayout(this);
  QHBoxLayout *hbox = new QHBoxLayout();
  ```
  - ->setSpacing(1)
  - ->addWidget(*QPushButton)
  
  
### QListWidget 
  ```c++
  QListWidget *lw = new QListWidget(this);
  ```
  - ->addItem(str)

### QLineEdit 
  ```c++
  QLineEdit *nameEdit = new QLineEdit(this);
  ```
  
### QFormLayout
  ```c++
  QFormLayout *formLayout = new QFormLayout;
  ```
  - ->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter)
  - ->addRow(str, *QLineEdit)
  - setLayout(*QFormLayout)

### QGridLayout
  ```c++
  QGridLayout *grid = new QGridLayout(this);
  ```
  - ->setVerticalSpacing(int)
  - ->setHorizontalSpacing(int)
