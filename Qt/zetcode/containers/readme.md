### QVector [doc](http://doc.qt.io/qt-5/QVector.html)
  ```c++
  #include <QVector>
  QVector<int> vals = {1, 2, 3, 4, 5};
  ```
  - .size()
  - .first()
  - .last()
  - .append(element)
  - .prepend(element)

### QList [doc](http://doc.qt.io/qt-5/QList.html)
  ```c++
  #include <QList>
  QList<QString> authors = {"el1", "el2", "el3", "el4"}
  ```
  - .size()
  - .at(int)
  - .begin()
  - .end()
  
### QStringList [doc](http://doc.qt.io/qt-5/QStringList.html)
  ```c++
  #include <QStringList>
  QString string = "coin, book, cup, pencil, clock, bookmark";
  QStringList items = string.split(",");
  ```
  - .hasNext()
  - .next()
  - .trimmed()
  
### QSet [doc](http://doc.qt.io/qt-5/QSet.html)
  ```c++
  #include <QSet>
  QSet<QString> cols1 = {"yellow", "red", "blue"};
  ```
  - .insert(element)
  - .size()
  - .values()
  
### QMap [doc](http://doc.qt.io/qt-5/QMap.html)
  ```c++
  #include <QMap>
  QMap<QString, int> items = { {"coins", 5}, {"books", 3} };
  ```
  - .insert(Key, Value)
  - .values()
  - .keys()
  - QMapIterator<QString, int> it(QMap variable)
  
  
