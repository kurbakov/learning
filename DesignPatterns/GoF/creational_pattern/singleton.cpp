// Source: http://cpp-reference.ru/patterns/creational-patterns/singleton/

/*
 Архитектура паттерна Singleton основана на идее использования глобальной переменной,
 имеющей следующие важные свойства:

    - Такая переменная доступна всегда. Время жизни глобальной переменной - от запуска
    программы до ее завершения.
    - Предоставляет глобальный доступ, то есть, такая переменная может быть доступна
    из любой части программы.

 Достоинства паттерна Singleton

    - Класс сам контролирует процесс создания единственного экземпляра.
    - Паттерн легко адаптировать для создания нужного числа экземпляров.
    - Возможность создания объектов классов, производных от Singleton.

 Недостатки паттерна Singleton

    - В случае использования нескольких взаимозависимых одиночек их реализация может 
    резко усложниться.
*/


// Singleton.h
class Singleton1
{
private:
    Singleton1() { }
    Singleton1( const Singleton1& );
    Singleton1& operator=( Singleton1& );
public:
    static Singleton1& getInstance() {
        static Singleton1 instance;
        return instance;
    }
};

class Singleton2
{
private:
    Singleton2( Singleton1& instance): s1( instance) { }
    Singleton2( const Singleton2& );
    Singleton2& operator=( Singleton2& );
    Singleton1& s1;
public:
    static Singleton2& getInstance() {
        static Singleton2 instance( Singleton1::getInstance());
        return instance;
    }
};

// main.cpp
// #include "Singleton.h"

int main()
{
    Singleton2& s = Singleton2::getInstance();
    return 0;
}
