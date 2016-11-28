// Source: http://cpp-reference.ru/patterns/behavioral-patterns/mediator/

/*
 Мы хотим спроектировать систему с повторно используемыми компонентами, однако существующие связи
 между этими компонентами можно охарактеризовать феноменом "спагетти-кода".

 Паттерн Mediator заменяет взаимодействие "все со всеми" взаимодействием "один со всеми".

 Пример рационального использования паттерна Mediator – моделирование отношений между пользователями
 и группами операционной системы. Группа может иметь 0 или более пользователей, а пользователь может
 быть членом 0 или более групп. Паттерн Mediator предусматривает гибкий способ управления
 пользователями и группами.

 Назначение паттерна Mediator
    - Паттерн Mediator определяет объект, инкапсулирующий взаимодействие множества объектов.
    Mediator делает систему слабо связанной, избавляя объекты от необходимости ссылаться друг на друга,
    что позволяет изменять взаимодействие между ними независимо.
    - Паттерн Mediator вводит посредника для развязывания множества взаимодействующих объектов.
    - Заменяет взаимодействие "все со всеми" взаимодействием "один со всеми".
*/

// example

#include <iostream>

class FileSelectionDialog;

class Widget
{
public:
    Widget(FileSelectionDialog *mediator, char *name)
    {
        _mediator = mediator;
        strcpy(_name, name);
    }
    virtual void changed();
    virtual void updateWidget() = 0;
    virtual void queryWidget() = 0;
protected:
    char _name[20];
private:
    FileSelectionDialog *_mediator;
};

class List: public Widget
{
public:
    List(FileSelectionDialog *dir, char *name): Widget(dir, name){}
    void queryWidget()
    {
        std::cout << "   " << _name << " list queried" << std::endl;
    }
    void updateWidget()
    {
        std::cout << "   " << _name << " list updated" << std::endl;
    }
};

class Edit: public Widget
{
public:
    Edit(FileSelectionDialog *dir, char *name): Widget(dir, name){}
    void queryWidget()
    {
        std::cout << "   " << _name << " edit queried" << std::endl;
    }
    void updateWidget()
    {
        std::cout << "   " << _name << " edit updated" << std::endl;
    }
};

class FileSelectionDialog
{
public:
    enum Widgets
    {
        FilterEdit, DirList, FileList, SelectionEdit
    };
    FileSelectionDialog()
    {
        _components[FilterEdit] = new Edit(this, "filter");
        _components[DirList] = new List(this, "dir");
        _components[FileList] = new List(this, "file");
        _components[SelectionEdit] = new Edit(this, "selection");
    }
    virtual ~FileSelectionDialog();
    void handleEvent(int which)
    {
        _components[which]->changed();
    }
    virtual void widgetChanged(Widget *theChangedWidget)
    {
        if (theChangedWidget == _components[FilterEdit])
        {
            _components[FilterEdit]->queryWidget();
            _components[DirList]->updateWidget();
            _components[FileList]->updateWidget();
            _components[SelectionEdit]->updateWidget();
        }
        else if (theChangedWidget == _components[DirList])
        {
            _components[DirList]->queryWidget();
            _components[FileList]->updateWidget();
            _components[FilterEdit]->updateWidget();
            _components[SelectionEdit]->updateWidget();
        }
        else if (theChangedWidget == _components[FileList])
        {
            _components[FileList]->queryWidget();
            _components[SelectionEdit]->updateWidget();
        }
        else if (theChangedWidget == _components[SelectionEdit])
        {
            _components[SelectionEdit]->queryWidget();
            std::cout << "   file opened" << std::endl;
        }
    }
private:
    Widget *_components[4];
};

FileSelectionDialog::~FileSelectionDialog()
{
    for (int i = 0; i < 3; i++)
        delete _components[i];
}

void Widget::changed()
{
    _mediator->widgetChanged(this);
}

int main()
{
    FileSelectionDialog fileDialog;
    int i;

    std::cout << "Exit[0], Filter[1], Dir[2], File[3], Selection[4]: ";
    std::cin >> i;

    while (i)
    {
        fileDialog.handleEvent(i - 1);
        std::cout << "Exit[0], Filter[1], Dir[2], File[3], Selection[4]: ";
        std::cin >> i;
    }
}
