### Dependencies:
```
#include <QTextStream>
```

### What we learned:

1. QTextStream [doc](http://doc.qt.io/qt-4.8/QTextStream.html)
  ```c++
  QTextStream out(stdout);
  ```

2. QString [doc](http://doc.qt.io/qt-4.8/QString.html)
  - .append(str);
  - .toUpper()
  - .toLower()
  - QString::fromLatin1(str1.data(), str2.size());
  - .at(int)
  - .isNull()
  - .length()
  - .arg(str)
  - .right(int)
  - .left(int)
  - .mid(int, int)
  - .begin()
  - .end()
  - .size()
  - .toInt()
  - .setNum(int)
  - .clear()
  - .remove(int, int)
  - .append(str)
  - .rightJustified(int, char)
  - .toHtmlEscaped()

3. QStringRef [doc](http://doc.qt.io/qt-4.8/QStringRef.html)
  - build the QStringRef
  ```c++
  QString str2("The big apple");
  QStringRef sub(&str2, 0, 7);
  ```
  - .toString()

4. QChar [doc](http://doc.qt.io/qt-4.8/QChar.html)
  - .isDigit()
  - .isLetter()
  - .isSpace()
  - .isPunct()

5. foreach [doc](http://doc.qt.io/qt-4.8/containers.html#the-foreach-keyword)
  ```c++
  QTextStream out(stdout);
  QString str = "There are many stars.";
  foreach (QChar qc, str) {
      out << qc << " ";  
  }
  ```

6. Comparision
  ```c++
  if (QString::compare(str1, str2) == 0)
    return true;
  ```
  ```c++
  if (QString::compare(a, b, Qt::CaseInsensitive) == 0)
    return true
  ```

7. QFile [doc](http://doc.qt.io/qt-4.8/QFile.html)
  ```c++
  QFile file("cprog.c");
  ```
  - .open(QIODevice::ReadOnly)
  - qWarning(str);

8. QTextStream [doc](http://doc.qt.io/qt-4.8/qtextstream.html)
  ```c++
  QTextStream in(&file);
  ```
  - .readAll()
