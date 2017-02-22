### dependencies
```c++
#include <QDate>
#include <QTime>
#include <QDateTime>
```

1. QDate [doc](http://doc.qt.io/qt-5/qdate.html)
  - .setDate(2015, 3, 3)
  - .toString()
  - QDate::currentDate()
  - QDate::isLeapYear(year_as_int)
  - .dayOfWeek()
  - QDate::shortDayName(weekday)
  - QDate::longDayName(weekday)
  - .daysInMonth()
  - .daysInYear()
  - .isValid()
  - .addDays(int)
  - .daysTo(QDate)
  - .toJulianDay()

2. list of date formats
  - Qt::LocaleDate
  - Qt::SystemLocaleDate
  - Qt::DefaultLocaleLongDate
  - Qt::DefaultLocaleShortDate
  - Qt::SystemLocaleLongDate
  - Qt::SystemLocaleShortDate
  - Qt::ISODate
  - Qt::TextDate

3. QTime [doc](http://doc.qt.io/qt-5/QTime.html)
  - .setHMS(13, 52, 45, 155)
  - .toString("hh:mm:ss.zzz")
  - QTime::currentTime()
  
4. list of time formats
  - Qt::TextDate
  - Qt::ISODate
  - Qt::SystemLocaleShortDate
  - Qt::SystemLocaleLongDate
  - Qt::DefaultLocaleShortDate
  - Qt::DefaultLocaleLongDate
  - Qt::SystemLocaleDate
  - Qt::LocaleDate
  
5. QDateTime [doc](http://doc.qt.io/qt-5/QDateTime.html)
  - .date()
  - .time()
  - .toString()
  - QDateTime::currentDateTime()
  - .toUTC()
  - .toLocalTime()
  - .setTime_t(variable from ctime)

6. QList [doc](http://doc.qt.io/qt-5/QList.html)
  - .append(element)
 
Source: http://zetcode.com/gui/qt5/datetime/
