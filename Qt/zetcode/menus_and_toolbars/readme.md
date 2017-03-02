### Dependencies:
```c++
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QAction>
#include <QStatusBar>
```

### QAction [doc](http://doc.qt.io/Qt-5/QAction.html)
  ```c++
  QAction *a = new QAction("&Quit", this);
  ```
  - ->setShortcut(tr("CTRL+Q"))
  - ->setChecked(bool)
  
### QMenu [doc](http://doc.qt.io/Qt-5/QMenu.html)
  ```c++
  QMenu *menu;
  menu = nemuBar()->addMenu("&File");
  ```
  - ->addAction(QAction)
  
### QPixmap [doc](http://doc.qt.io/Qt-5/QPixmap.html)
  ```c++
  QPixmap newpix(path/to/pic);
  ```
  
### QToolBar [doc](http://doc.qt.io/Qt-5/QToolBar.html)
  ```c++
  QToolBr *t = new QToolBar(str);
  ```
  - ->addAction(QIcon(QPixmap), str)
  - ->addSeparator()
  
### QTexEdit [doc](http://doc.qt.io/qt-4.8/qtextedit.html)
  ```c++
  QTexEdit *e = new QTexEdit(this);
  ```
  - setCentralwidget(QTexEdit)
  
