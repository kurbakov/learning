// Source: http://cpp-reference.ru/patterns/behavioral-patterns/chain-of-responsibility/

/*
 Имеется поток запросов и переменное число "обработчиков" этих запросов. Необходимо
 эффективно обрабатывать запросы без жесткой привязки к их обработчикам, при этом запрос
 может быть обработан любым обработчиком.

 Паттерн Chain of Responsibility связывает в цепочку объекты-получатели, а затем передает
 запрос-сообщение от одного объекта к другому до тех пор, пока не достигнет объекта, способного
 его обработать. Число и типы объектов-обработчиков заранее неизвестны, они могут настраиваться
 динамически. Механизм связывания в цепочку использует рекурсивную композицию, что позволяет
 использовать неограниченное число обработчиков.

 Назначение паттерна Chain of Responsibility
    - Паттерн Chain of Responsibility позволяет избежать жесткой зависимости отправителя
    запроса от его получателя, при этом запрос может быть обработан несколькими объектами.
    Объекты-получатели связываются в цепочку. Запрос передается по этой цепочке, пока не
    будет обработан.
    - Вводит конвейерную обработку для запроса с множеством возможных обработчиков.
    - Объектно-ориентированный связанный список с рекурсивным обходом.
*/

// example

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Base
{
    // 1. Указатель "next" в базовом классе
    Base *next;
public:
    Base()
    {
        next = 0;
    }
    void setNext(Base *n)
    {
        next = n;
    }
    void add(Base *n)
    {
        if (next)
            next->add(n);
        else
            next = n;
    }
    // 2. Метод базового класса, делегирующий запрос next-объекту
    virtual void handle(int i)
    {
        next->handle(i);
    }
};

class Handler1: public Base
{
public:
    /*virtual*/void handle(int i)
    {
        if (rand() % 3)
        {
            // 3. 3 из 4 запросов не обрабатываем
            cout << "H1 passsed " << i << "  ";
            // 3. и делегируем базовому классу
            Base::handle(i);        }
        else
            cout << "H1 handled " << i << "  ";
    }
};

class Handler2: public Base
{
public:
    /*virtual*/void handle(int i)
    {
        if (rand() % 3)
        {
            cout << "H2 passsed " << i << "  ";
            Base::handle(i);
        }
        else
            cout << "H2 handled " << i << "  ";
    }
};

class Handler3: public Base
{
public:
    /*virtual*/void handle(int i)
    {
        if (rand() % 3)
        {
            cout << "H3 passsed " << i << "  ";
            Base::handle(i);
        }
        else
            cout << "H3 handled " << i << "  ";
    }
};

int main()
{
    srand(time(0));
    Handler1 root;
    Handler2 two;
    Handler3 thr;
    root.add(&two);
    root.add(&thr);
    thr.setNext(&root);
    for (int i = 1; i < 10; i++)
    {
        root.handle(i);
        cout << '\n';
    }
}
