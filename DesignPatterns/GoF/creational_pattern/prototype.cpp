// Source: http://cpp-reference.ru/patterns/creational-patterns/prototype/

/*
 Для создания новых объектов паттерн Prototype использует прототипы. Прототип - это 
 уже существующий в системе объект, который поддерживает операцию клонирования, то 
 есть умеет создавать копию самого себя. Таким образом, для создания объекта 
 некоторого класса достаточно выполнить операцию clone() соответствующего прототипа.

 Паттерн Prototype (прототип) можно использовать в следующих случаях:

    - Система должна оставаться независимой как от процесса создания новых объектов, 
    так и от типов порождаемых объектов. Непосредственное использование выражения new 
    в коде приложения считается нежелательным (подробнее об этом в разделе Порождающие 
    паттерны).
    - Необходимо создавать объекты, точные классы которых становятся известными уже 
    на стадии выполнения программы.

 Достоинства паттерна Prototype

    - Для создания новых объектов клиенту необязательно знать их конкретные классы.
    - Возможность гибкого управления процессом создания новых объектов за счет 
    возможности динамических добавления и удаления прототипов в реестр.

 Недостатки паттерна Prototype

    - Каждый тип создаваемого продукта должен реализовывать операцию клонирования 
    clone(). В случае, если требуется глубокое копирование объекта (объект содержит 
    ссылки или указатели на другие объекты), это может быть непростой задачей.
*/

#include <iostream>
#include <vector>

// Иерархия классов игровых персонажей
// Полиморфный базовый класс
class Warrior
{
public:
    virtual Warrior* clone() = 0;
    virtual void info() = 0;
    virtual ~Warrior() {}
};


// Производные классы различных родов войск
class Infantryman: public Warrior
{
    friend class PrototypeFactory;
public:
    Warrior* clone() {
        return new Infantryman( *this);
    }
    void info() {
        std::cout << "Infantryman" << std::endl;
    }
private:
    Infantryman() {}
};

class Archer: public Warrior
{
    friend class PrototypeFactory;
public:
    Warrior* clone() {
        return new Archer( *this);
    }
    void info() {
        std::cout << "Archer" << std::endl;
    }
private:
    Archer() {}
};

class Horseman: public Warrior
{
    friend class PrototypeFactory;
public:
    Warrior* clone() {
        return new Horseman( *this);
    }
    void info() {
        std::cout << "Horseman" << std::endl;
    }
private:
    Horseman() {}
};


// Фабрика для создания боевых единиц всех родов войск
class PrototypeFactory
{
public:
    Warrior* createInfantrman() {
        static Infantryman prototype;
        return prototype.clone();
    }
    Warrior* createArcher() {
        static Archer prototype;
        return prototype.clone();
    }
    Warrior* createHorseman() {
        static Horseman prototype;
        return prototype.clone();
    }
};


int main()
{
    PrototypeFactory factory;
    std::vector<Warrior*> v;
    v.push_back( factory.createInfantrman());
    v.push_back( factory.createArcher());
    v.push_back( factory.createHorseman());

    for(int i=0; i<v.size(); i++)
        v[i]->info();
    // ...
}
