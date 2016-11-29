/*

 Sources:
    - https://en.wikipedia.org/wiki/Delegation_pattern
    - https://en.wikipedia.org/wiki/Delegation_(object-oriented_programming)

 Russian:
 Делегирование (англ. Delegation) — основной шаблон проектирования, в котором объект внешне выражает некоторое
 поведение, но в реальности передаёт ответственность за выполнение этого поведения связанному объекту. Шаблон
 делегирования является фундаментальной абстракцией, на основе которой реализованы другие шаблоны - композиция
 (также называемая агрегацией), примеси (mixins) и аспекты (aspects).

 English:
 Delegation is a way to make composition as powerful for reuse as inheritance [Lie86, JZ91]. In delegation, two
 objects are involved in handling a request: a receiving object delegates operations to its delegate. This is
 analogous to subclasses deferring requests to parent classes. But with inheritance, an inherited operation can always
 refer to the receiving object through the this member variable in C++ and self in Smalltalk. To achieve the same
 effect with delegation, the receiver passes itself to the delegate to let the delegated operation refer to the receiver.

*/

#include <iostream>

class I {
public:
    virtual void f() = 0;
    virtual void g() = 0;
};

class A : public I {
public:
    void f() { std::cout << "A: call method f()" << std::endl; }
    void g() { std::cout << "A: call method g()" << std::endl; }
};

class B : public I {
public:
    void f() { std::cout << "B: call method f()" << std::endl; }
    void g() { std::cout << "B: call method g()" << std::endl; }
};

class C : public I {
public:
    // Конструктор
    C() : m_i ( new A() ) { }
    // Деструктор
    virtual ~C() {
        delete m_i;
    }
    void f() { m_i->f(); }
    void g() { m_i->g(); }
    // Этими методами меняем поле-объект, чьи методы будем делегировать
    void toA() {
        delete m_i;
        m_i = new A();
    }
    void toB() {
        delete m_i;
        m_i = new B();
    }
private:
    // Объявляем объект методы которого будем делегировать
    I * m_i;
};

int main() {
    C c;

    c.f();
    c.g();
    c.toB();
    c.f();
    c.g();

    return 0;
}
