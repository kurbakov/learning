// Source: http://cpp-reference.ru/patterns/creational-patterns/builder/

/*
    Паттерн Builder отделяет алгоритм поэтапного конструирования сложного продукта
    (объекта) от его внешнего представления так, что с помощью одного и того же
    алгоритма можно получать разные представления этого продукта.

    Поэтапное создание продукта означает его построение по частям. После того как
    построена последняя часть, продукт можно использовать.Паттерн Builder отделяет
    алгоритм поэтапного конструирования сложного продукта (объекта) от его внешнего
    представления так, что с помощью одного и того же алгоритма можно получать разные
    представления этого продукта.

    Паттерн Builder может помочь в решении следующих задач:

    - В системе могут существовать сложные объекты, создание которых за одну операцию
    затруднительно или невозможно. Требуется поэтапное построение объектов с контролем
    результатов выполнения каждого этапа.

    - Данные должны иметь несколько представлений. Приведем классический пример. Пусть
    есть некоторый исходный документ в формате RTF (Rich Text Format), в общем случае
    содержащий текст, графические изображения и служебную информацию о форматировании
    (размер и тип шрифтов, отступы и др.). Если этот документ в формате RTF
    преобразовать в другие форматы (например, Microsoft Word или простой ASCII-текст),

    Достоинства паттерна Builder

    - Возможность контролировать процесс создания сложного продукта.
    - Возможность получения разных представлений некоторых данных.

    Недостатки паттерна Builder

    - ConcreteBuilder и создаваемый им продукт жестко связаны между собой, поэтому
    при внесеннии изменений в класс продукта скорее всего придется соотвествующим
    образом изменять и класс ConcreteBuilder.
*/

#include <iostream>
#include <vector>

// Классы всех возможных родов войск
class Infantryman
{
public:
    void info() {
        std::cout << "Infantryman" << std::endl;
    }
};

class Archer
{
public:
    void info() {
        std::cout << "Archer" << std::endl;
    }
};

class Horseman
{
public:
    void info() {
        std::cout << "Horseman" << std::endl;
    }
};

class Catapult
{
public:
    void info() {
        std::cout << "Catapult" << std::endl;
    }
};

class Elephant
{
public:
    void info() {
        std::cout << "Elephant" << std::endl;
    }
};


// Класс "Армия", содержащий все типы боевых единиц
class Army
{
public:
    std::vector<Infantryman> vi;
    std::vector<Archer> va;
    std::vector<Horseman> vh;
    std::vector<Catapult> vc;
    std::vector<Elephant> ve;
    void info() {
        int i;
        for(i=0; i<vi.size(); ++i)  vi[i].info();
        for(i=0; i<va.size(); ++i)  va[i].info();
        for(i=0; i<vh.size(); ++i)  vh[i].info();
        for(i=0; i<vc.size(); ++i)  vc[i].info();
        for(i=0; i<ve.size(); ++i)  ve[i].info();
    }
};


// Базовый класс ArmyBuilder объявляет интерфейс для поэтапного
// построения армии и предусматривает его реализацию по умолчанию
class ArmyBuilder
{
protected:
    Army* p;
public:
    ArmyBuilder(): p(0) {}
    virtual ~ArmyBuilder() {}
    virtual void createArmy() {}
    virtual void buildInfantryman() {}
    virtual void buildArcher() {}
    virtual void buildHorseman() {}
    virtual void buildCatapult() {}
    virtual void buildElephant() {}
    virtual Army* getArmy() { return p; }
};


// Римская армия имеет все типы боевых единиц кроме боевых слонов
class RomanArmyBuilder: public ArmyBuilder
{
public:
    void createArmy() { p = new Army; }
    void buildInfantryman() { p->vi.push_back( Infantryman()); }
    void buildArcher() { p->va.push_back( Archer()); }
    void buildHorseman() { p->vh.push_back( Horseman()); }
    void buildCatapult() { p->vc.push_back( Catapult()); }
};


// Армия Карфагена имеет все типы боевых единиц кроме катапульт
class CarthaginianArmyBuilder: public ArmyBuilder
{
public:
    void createArmy() { p = new Army; }
    void buildInfantryman() { p->vi.push_back( Infantryman()); }
    void buildArcher() { p->va.push_back( Archer()); }
    void buildHorseman() { p->vh.push_back( Horseman()); }
    void buildElephant() { p->ve.push_back( Elephant()); }
};


// Класс-распорядитель, поэтапно создающий армию той или иной стороны.
// Именно здесь определен алгоритм построения армии.
class Director
{
public:
    Army* createArmy( ArmyBuilder & builder )
    {
        builder.createArmy();
        builder.buildInfantryman();
        builder.buildArcher();
        builder.buildHorseman();
        builder.buildCatapult();
        builder.buildElephant();
        return( builder.getArmy());
    }
};


int main()
{
    Director dir;
    RomanArmyBuilder ra_builder;
    CarthaginianArmyBuilder ca_builder;

    Army * ra = dir.createArmy( ra_builder);
    Army * ca = dir.createArmy( ca_builder);
    std::cout << "Roman army:" << std::endl;
    ra->info();
    std::cout << "\nCarthaginian army:" << std::endl;
    ca->info();
    // ...

    return 0;
}


