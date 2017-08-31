// Source: http://cpp-reference.ru/patterns/behavioral-patterns/state/
// CODE DOES NOT WORK!!!

/*
 Назначение паттерна State
    - Паттерн State позволяет объекту изменять свое поведение в зависимости от внутреннего
    состояния. Создается впечатление, что объект изменил свой класс.
    - Паттерн State является объектно-ориентированной реализацией конечного автомата.

 Поведение объекта зависит от его состояния и должно изменяться во время выполнения программы. 
 Такую схему можно реализовать, применив множество условных операторов: на основе анализа 
 текущего состояния объекта предпринимаются определенные действия. Однако при большом числе 
 состояний условные операторы будут разбросаны по всему коду, и такую программу будет трудно 
 поддерживать.
*/

// example

#include <iostream>
using namespace std;
class Machine
{
    class State *current;
public:
    Machine();
    void setCurrent(State *s)
    {
        current = s;
    }
    void on();
    void off();
};

class State
{
public:
    virtual void on(Machine *m)
    {
        cout << "   already ON\n";
    }
    virtual void off(Machine *m)
    {
        cout << "   already OFF\n";
    }
};

void Machine::on()
{
    current->on(this);
}

void Machine::off()
{
    current->off(this);
}

class ON: public State
{
public:
    ON()
    {
        cout << "   ON-ctor ";
    };
    ~ON()
    {
        cout << "   dtor-ON\n";
    };
    void off(Machine *m);
};

class OFF: public State
{
public:
    OFF()
    {
        cout << "   OFF-ctor ";
    };
    ~OFF()
    {
        cout << "   dtor-OFF\n";
    };
    void on(Machine *m)
    {
        cout << "   going from OFF to ON";
        m->setCurrent(new ON());
        delete this;
    }
};

void ON::off(Machine *m)
{
    cout << "   going from ON to OFF";
    m->setCurrent(new OFF());
    delete this;
}

Machine::Machine()
{
    current = new OFF();
    cout << '\n';
}

int main()
{
    void(Machine:: *ptrs[])() =
            {
                    Machine::off, Machine::on
            };
    Machine fsm;
    int num;
    while (1)
    {
        cout << "Enter 0/1: ";
        cin >> num;
        (fsm. *ptrs[num])();
    }
}
