// Source: http://cpp-reference.ru/patterns/structural-patterns/composite/

/*
 Паттерн Composite предлагает следующее решение. Он вводит абстрактный базовый класс 
 Component с поведением, общим для всех примитивных и составных объектов. Для случая 
 стратегической игры - это метод getStrength() для подсчета разрушающей силы. 
 Подклассы Primitive and Composite являются производными от класса Component. 
 Составной объект Composite хранит компоненты-потомки абстрактного типа Component, 
 каждый из которых может быть также Composite.

 Достоинства паттерна Composite
    - В систему легко добавлять новые примитивные или составные объекты, так как
    паттерн Composite использует общий базовый класс Component.
    - Код клиента имеет простую структуру – примитивные и составные объекты обрабатываются
    одинаковым образом.
    - Паттерн Composite позволяет легко обойти все узлы древовидной структуры

 Недостатки паттерна Composite
    - Неудобно осуществить запрет на добавление в составной объект Composite объектов
    определенных типов. Так, например, в состав римской армии не могут входить боевые слоны.
*/


// example
#include <iostream>
#include <vector>
#include <assert.h>

// Component
class Unit
{
public:
    virtual int getStrength() = 0;
    virtual void addUnit(Unit* p) {
        assert( false);
    }
    virtual ~Unit() {}
};

// Primitives
class Archer: public Unit
{
public:
    virtual int getStrength() {
        return 1;
    }
};

class Infantryman: public Unit
{
public:
    virtual int getStrength() {
        return 2;
    }
};

class Horseman: public Unit
{
public:
    virtual int getStrength() {
        return 3;
    }
};


// Composite
class CompositeUnit: public Unit
{
public:
    int getStrength() {
        int total = 0;
        for(int i=0; i<c.size(); ++i)
            total += c[i]->getStrength();
        return total;
    }
    void addUnit(Unit* p) {
        c.push_back( p);
    }
    ~CompositeUnit() {
        for(int i=0; i<c.size(); ++i)
            delete c[i];
    }
private:
    std::vector<Unit*> c;
};


// Вспомогательная функция для создания легиона
CompositeUnit* createLegion()
{
    // Римский легион содержит:
    CompositeUnit* legion = new CompositeUnit;
    // 3000 тяжелых пехотинцев
    for (int i=0; i<3000; ++i)
        legion->addUnit(new Infantryman);
    // 1200 легких пехотинцев
    for (int i=0; i<1200; ++i)
        legion->addUnit(new Archer);
    // 300 всадников
    for (int i=0; i<300; ++i)
        legion->addUnit(new Horseman);

    return legion;
}

int main()
{
    // Римская армия состоит из 4-х легионов
    CompositeUnit* army = new CompositeUnit;
    for (int i=0; i<4; ++i)
        army->addUnit( createLegion());

    std::cout << "Roman army damaging strength is "
         << army->getStrength() << std::endl;
    // …
    delete army;
    return 0;
}
