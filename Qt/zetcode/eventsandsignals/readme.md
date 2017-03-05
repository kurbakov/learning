### Events are splitted into:
  - event source
  - event object
  - event target
  
Important part of the event:
```c++
connect(*QPushButton, &QPushButton::clicked, qApp, &QApplication::quit);
```
### qApp
  ```
  qApp -> a global pointer to tha app and sorn of constanta. We do not need to define the variable in the code.
  ```
  - -> quit()
  
### QKeyEvent [doc](http://doc.qt.io/qt-5/QKeyEvent.html)
  ```c++
  QKeyEvent *event; // as an input parameter to the function
  ```
  - ->key() // checked if the key was pressed
  
### QMoveEvent [doc](http://doc.qt.io/qt-5/QMoveEvent.html)
  ```c++
  QMoveEvent *e; // as an input parameter to the function
  ```
  - ->pos().x()
  - ->pos().y()
  
### QCheckBox [doc](http://doc.qt.io/qt-5/QCheckBox.html)
  ```c++
  QCheckBox *cb = new QCheckBox(str, this);
  ```
  - ->setCheckStat(Qt::Checked)

### QTime [doc](http://doc.qt.io/qt-5/QTime.html)
  ```c++
  QTime qtime = QTime::currentTime();
  ```
  - startTimer(int) // Every number of ms a timer event is generated => put 1000 for second accuracy
  
