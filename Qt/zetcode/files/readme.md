### Dependencies
```c++
// writing and reading files
#include <QTextStream>

// working woth files
#include <QFileInfo>
#include <QFile>
#include <QDir>
```

### QFile [doc](http://doc.qt.io/qt-5/QFile.html)
  ```c++
  QFile file(path/to/file);
  ```
  - .exists()
  - .open(QIODevice::ReadOnly)
  - .open(QIODevice::WriteOnly)
  - .close()
  - QFile::copy(from, to)
  - QFile::Permissions
    - QFile::ReadOwner
    - QFile::WriteOwner
    - QFile::ExeOwner
    - QFile::ReadGroup
    - QFile::WriteGroup
    - QFile::ExeGroup
    - QFile::ReadOther
    - QFile::WriteOther
    - QFile::ExeOther

### QFileInfo [doc](http://doc.qt.io/qt-5/QFileInfo.html)
  ```c++
  QFileInfo fileinfo(filename);
  ```
  - .size()
  - .group()
  - .owner()
  - .lastRead()
  - .lastModified()
  - .absoluteFilePath()
  - .baseName()
  - .completeBaseName()
  - .fileName()
  - .suffix()
  - .completeSuffix()
  
### QTextStream [doc](http://doc.qt.io/qt-5/QTextStream.html)
  ```c++
  // reading file
  QTextStream in(&file);
  
  // writing to the file
  QTextStream out(&file);
  out << "Xubuntu" << endl;
  ```
  - .atEnd()
  - .readLine()
  
### QDir [doc](http://doc.qt.io/qt-5/QDir.html)
  ```c++
  QDir dir;
  ```
  - .mkdir(DIR)
  - .exists(DIR)
  - .mkpath(some/path);
  - QDir::currentPath()
  - QDir::homePath()
  - QDir::tempPath()
  - QDir::rootPath()
  - .setFilter(QDir::Files | QDir::AllDirs)
  - .setSorting(QDir::Size | QDir::Reversed)
  
### QFileInfoList [doc](http://doc.qt.io/qt-5/qfileinfo.html)
  ```c++
  QFileInfoList list = QDir(directory).entryInfoList();
  ```
  - .fileName()
  - .size()
  
