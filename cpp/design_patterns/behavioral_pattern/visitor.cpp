// Source: http://cpp-reference.ru/patterns/behavioral-patterns/visitor/

/*
 Различные и несвязанные операции должны выполняться над узловыми объектами некоторой гетерогенной
 совокупной структуры. Вы хотите избежать "загрязнения" классов этих узлов такими операциями (то
 есть избежать добавления соответствующих методов в эти классы). И вы не хотите запрашивать тип
 каждого узла и осуществлять приведение указателя к правильному типу, прежде чем выполнить нужную
 операцию.

 Основным назначением паттерна Visitor является введение абстрактной функциональности для совокупной
 иерархической структуры объектов "элемент", а именно, паттерн Visitor позволяет, не изменяя классы
 Element, добавлять в них новые операции. Для этого вся обрабатывающая функциональность переносится
 из самих классов Element (эти классы становятся "легковесными") в иерархию наследования Visitor.

 Паттерн Visitor позволяет легко добавлять новые операции – нужно просто добавить новый производный
 от Visitor класс. Однако паттерн Visitor следует использовать только в том случае, если подклассы
 Element совокупной иерархической структуры остаются стабильными (неизменяемыми). В противном случае,
 нужно приложить значительные усилия на обновление всей иерархии Visitor.

 Назначение паттерна Visitor
    - Паттерн Visitor определяет операцию, выполняемую на каждом элементе из некоторой структуры.
    Позволяет, не изменяя классы этих объектов, добавлять в них новые операции.
    - Является классической техникой для восстановления потерянной информации о типе.
    - Паттерн Visitor позволяет выполнить нужные действия в зависимости от типов двух объектов.
    - Предоставляет механизм двойной диспетчеризации.
*/

// example

#include <iostream>
#include <string>
using namespace std;

// 1. Добавьте метод accept(Visitor) иерархию "элемент"
class Element
{
public:
    virtual void accept(class Visitor &v) = 0;
};

class This: public Element
{
public:
    /*virtual*/void accept(Visitor &v);
    string thiss()
    {
        return "This";
    }
};

class That: public Element
{
public:
    /*virtual*/void accept(Visitor &v);
    string that()
    {
        return "That";
    }
};

class TheOther: public Element
{
public:
    /*virtual*/void accept(Visitor &v);
    string theOther()
    {
        return "TheOther";
    }
};

// 2. Создайте базовый класс Visitor и определите 
// методы visit()для каждого типа "элемента"
class Visitor
{
public:
    virtual void visit(This *e) = 0;
    virtual void visit(That *e) = 0;
    virtual void visit(TheOther *e) = 0;
};

/*virtual*/void This::accept(Visitor &v)
{
    v.visit(this);
}

/*virtual*/void That::accept(Visitor &v)
{
    v.visit(this);
}

/*virtual*/void TheOther::accept(Visitor &v)
{
    v.visit(this);
}

// 3. Создайте производные классы Visitor для каждой 
// "операции", исполняемой над "элементами"
class UpVisitor: public Visitor
{
    /*virtual*/void visit(This *e)
    {
        cout << "do Up on " + e->thiss() << '\n';
    }
    /*virtual*/void visit(That *e)
    {
        cout << "do Up on " + e->that() << '\n';
    }
    /*virtual*/void visit(TheOther *e)
    {
        cout << "do Up on " + e->theOther() << '\n';
    }
};

class DownVisitor: public Visitor
{
    /*virtual*/void visit(This *e)
    {
        cout << "do Down on " + e->thiss() << '\n';
    }
    /*virtual*/void visit(That *e)
    {
        cout << "do Down on " + e->that() << '\n';
    }
    /*virtual*/void visit(TheOther *e)
    {
        cout << "do Down on " + e->theOther() << '\n';
    }
};

int main()
{
    Element *list[] =
            {
                    new This(), new That(), new TheOther()
            };

    UpVisitor up;      // 4. Клиент создает 
    DownVisitor down;  //    объекты Visitor
    for (int i = 0; i < 3; i++)
        // и передает каждый 
        list[i]->accept(up);
    for (int i = 0; i < 3; i++)
        // в вызываемый метод accept()
        list[i]->accept(down);
}
