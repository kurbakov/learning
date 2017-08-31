// Source: http://cpp-reference.ru/patterns/creational-patterns/abstract-factory/

/*
 Любое семейство или группа взаимосвязанных объектов характеризуется несколькими общими
 типами создаваемых продуктов, при этом сами продукты таких типов будут различными для
 разных семейств. Например, для случая стратегической игры общими типами создаваемых
 продуктов будут пехота, лучники и конница, при этом каждый из этих родов войск римской
 армии может существенно отличаться по внешнему виду и боевым характеристикам от
 соответствуюших родов войск армии Карфагена.

 Используйте паттерн Abstract Factory (абстрактная фабрика) если:

    - Система должна оставаться независимой как от процесса создания новых объектов,
    так и от типов порождаемых объектов. Непосредственное использование выражения new
    в коде приложения нежелательно (подробнее об этом в разделе Порождающие паттерны).

    - Необходимо создавать группы или семейства взаимосвязанных объектов, исключая
    возможность одновременного использования объектов из разных семейств в одном контексте.


 Достоинства паттерна Abstract Factory

    - Скрывает сам процесс порождения объектов, а также делает систему независимой от
    типов создаваемых объектов, специфичных для различных семейств или групп
    (пользователи оперируют этими объектами через соответствующие абстрактные интерфейсы).

    - Позволяет быстро настраивать систему на нужное семейство создаваемых объектов.
    В случае многоплатформенного графического приложения для перехода на новую платформу,
    то есть для замены графических элементов (кнопок, меню, полос прокрутки) одного стиля
    другим достаточно создать нужный подкласс абстрактной фабрики. При этом условие
    невозможности одновременного использования элементов разных стилей для некоторой
    платформы будет выполнено автоматически.

 Недостатки паттерна Abstract Factory

    - Трудно добавлять новые типы создаваемых продуктов или заменять существующие, так
    как интерфейс базового класса абстрактной фабрики фиксирован. Например, если для
    нашей стратегической игры нужно будет ввести новый вид военной единицы - осадные
    орудия, то надо будет добавить новый фабричный метод, объявив его интерфейс в
    полиморфном базовом классе AbstractFactory и реализовав во всех подклассах. Снять
    это ограничение можно следующим образом. Все создаваемые объекты должны наследовать от
    общего абстрактного базового класса, а в единственный фабричный метод в качестве
    параметра необходимо передавать идентификатор типа объекта, который нужно создать.
    Однако в этом случае необходимо учитывать следующий момент. Фабричный метод создает
    объект запрошенного подкласса, но при этом возвращает его с интерфейсом общего
    абстрактного класса в виде ссылки или указателя, поэтому для такого объекта будет
    затруднительно выполнить какую-либо операцию, специфичную для подкласса.
*/

#include <iostream>
#include <vector>

// Абстрактные базовые классы всех возможных видов воинов
class Infantryman
{
public:
    virtual void info() = 0;
    virtual ~Infantryman() {}
};

class Archer
{
public:
    virtual void info() = 0;
    virtual ~Archer() {}
};

class Horseman
{
public:
    virtual void info() = 0;
    virtual ~Horseman() {}
};


// Классы всех видов воинов Римской армии
class RomanInfantryman: public Infantryman
{
public:
    void info() {
        std::cout << "RomanInfantryman" << std::endl;
    }
};

class RomanArcher: public Archer
{
public:
    void info() {
        std::cout << "RomanArcher" << std::endl;
    }
};

class RomanHorseman: public Horseman
{
public:
    void info() {
        std::cout << "RomanHorseman" << std::endl;
    }
};


// Классы всех видов воинов армии Карфагена
class CarthaginianInfantryman: public Infantryman
{
public:
    void info() {
        std::cout << "CarthaginianInfantryman" << std::endl;
    }
};

class CarthaginianArcher: public Archer
{
public:
    void info() {
        std::cout << "CarthaginianArcher" << std::endl;
    }
};

class CarthaginianHorseman: public Horseman
{
public:
    void info() {
        std::cout << "CarthaginianHorseman" << std::endl;
    }
};


// Абстрактная фабрика для производства воинов
class ArmyFactory
{
public:
    virtual Infantryman* createInfantryman() = 0;
    virtual Archer* createArcher() = 0;
    virtual Horseman* createHorseman() = 0;
    virtual ~ArmyFactory() {}
};


// Фабрика для создания воинов Римской армии
class RomanArmyFactory: public ArmyFactory
{
public:
    Infantryman* createInfantryman() {
        return new RomanInfantryman;
    }
    Archer* createArcher() {
        return new RomanArcher;
    }
    Horseman* createHorseman() {
        return new RomanHorseman;
    }
};


// Фабрика для создания воинов армии Карфагена
class CarthaginianArmyFactory: public ArmyFactory
{
public:
    Infantryman* createInfantryman() {
        return new CarthaginianInfantryman;
    }
    Archer* createArcher() {
        return new CarthaginianArcher;
    }
    Horseman* createHorseman() {
        return new CarthaginianHorseman;
    }
};


// Класс, содержащий всех воинов той или иной армии
class Army
{
public:
    ~Army() {
        int i;
        for(i=0; i<vi.size(); ++i)  delete vi[i];
        for(i=0; i<va.size(); ++i)  delete va[i];
        for(i=0; i<vh.size(); ++i)  delete vh[i];
    }
    void info() {
        int i;
        for(i=0; i<vi.size(); ++i)  vi[i]->info();
        for(i=0; i<va.size(); ++i)  va[i]->info();
        for(i=0; i<vh.size(); ++i)  vh[i]->info();
    }
    std::vector<Infantryman*> vi;
    std::vector<Archer*> va;
    std::vector<Horseman*> vh;
};


// Здесь создается армия той или иной стороны
class Game
{
public:
    Army* createArmy( ArmyFactory& factory ) {
        Army* p = new Army;
        p->vi.push_back( factory.createInfantryman());
        p->va.push_back( factory.createArcher());
        p->vh.push_back( factory.createHorseman());
        return p;
    }
};


int main()
{
    Game game;
    RomanArmyFactory ra_factory;
    CarthaginianArmyFactory ca_factory;

    Army * ra = game.createArmy(ra_factory);
    Army * ca = game.createArmy(ca_factory);
    std::cout << "Roman army:" << std::endl;
    ra->info();
    std::cout << "\nCarthaginian army:" << std::endl;
    ca->info();
    // ...
}
