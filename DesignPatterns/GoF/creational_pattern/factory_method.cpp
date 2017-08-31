// Source: http://cpp-reference.ru/patterns/creational-patterns/factory-method/

/*
 Для того, чтобы система оставалась независимой от различных типов объектов, паттерн
 Factory Method использует механизм полиморфизма - классы всех конечных типов
 наследуют от одного абстрактного базового класса, предназначенного для полиморфного
 использования. В этом базовом классе определяется единый интерфейс, через который
 пользователь будет оперировать объектами конечных типов.

 Назначение паттерна Factory Method

 В системе часто требуется создавать объекты самых разных типов. Паттерн Factory Method
 (фабричный метод) может быть полезным в решении следующих задач:

    - Система должна оставаться расширяемой путем добавления объектов новых типов.
    Непосредственное использование выражения new является нежелательным, так как
    в этом случае код создания объектов с указанием конкретных типов может получиться
    разбросанным по всему приложению. Тогда такие операции как добавление в систему
    объектов новых типов или замена объектов одного типа на другой будут
    затруднительными (подробнее в разделе Порождающие паттерны). Паттерн Factory
    Method позволяет системе оставаться независимой как от самого процесса порождения
    объектов, так и от их типов.
    - Заранее известно, когда нужно создавать объект, но неизвестен его тип.

 Достоинства паттерна Factory Method

    - Создает объекты разных типов, позволяя системе оставаться независимой как от
    самого процесса создания, так и от типов создаваемых объектов.

 Недостатки паттерна Factory Method

    - В случае классического варианта паттерна даже для порождения единственного
    объекта необходимо создавать соответствующую фабрику
*/

#include <iostream>
#include <vector>

// Иерархия классов игровых персонажей
class Warrior
{
public:
    virtual void info() = 0;
    virtual ~Warrior() {}
};

class Infantryman: public Warrior
{
public:
    void info() {
        std::cout << "Infantryman" << std::endl;
    };
};

class Archer: public Warrior
{
public:
    void info() {
        std::cout << "Archer" << std::endl;
    };
};

class Horseman: public Warrior
{
public:
    void info() {
        std::cout << "Horseman" << std::endl;
    };
};


// Фабрики объектов
class Factory
{
public:
    virtual Warrior* createWarrior() = 0;
    virtual ~Factory() {}
};

class InfantryFactory: public Factory
{
public:
    Warrior* createWarrior() {
        return new Infantryman;
    }
};

class ArchersFactory: public Factory
{
public:
    Warrior* createWarrior() {
        return new Archer;
    }
};

class CavalryFactory: public Factory
{
public:
    Warrior* createWarrior() {
        return new Horseman;
    }
};


// Создание объектов при помощи фабрик объектов
int main()
{
    InfantryFactory* infantry_factory = new InfantryFactory;
    ArchersFactory*  archers_factory  = new ArchersFactory ;
    CavalryFactory*  cavalry_factory  = new CavalryFactory ;

    std::vector<Warrior*> v;
    v.push_back( infantry_factory->createWarrior());
    v.push_back( archers_factory->createWarrior());
    v.push_back( cavalry_factory->createWarrior());

    for(int i=0; i<v.size(); i++)
        v[i]->info();
    // ...
}
