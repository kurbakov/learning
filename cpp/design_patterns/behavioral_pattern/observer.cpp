// Source: http://cpp-reference.ru/patterns/behavioral-patterns/observer/

/*
 Имеется система, состоящая из множества взаимодействующих классов. При этом взаимодействующие
 объекты должны находиться в согласованных состояниях. Вы хотите избежать монолитности такой
 системы, сделав классы слабо связанными (или повторно используемыми).

 Паттерн Observer определяет объект Subject, хранящий данные (модель), а всю функциональность
 "представлений" делегирует слабосвязанным отдельным объектам Observer. При создании наблюдатели
 Observer регистрируются у объекта Subject. Когда объект Subject изменяется, он извещает об этом
 всех зарегистрированных наблюдателей. После этого каждый обозреватель запрашивает у объекта
 Subject ту часть состояния, которая необходима для отображения данных.

 Назначение паттерна Observer
    - Паттерн Observer определяет зависимость "один-ко-многим" между объектами так, что при
    изменении состояния одного объекта все зависящие от него объекты уведомляются и обновляются
    автоматически.
    - Паттерн Observer инкапсулирует главный (независимый) компонент в абстракцию Subject и
    изменяемые (зависимые) компоненты в иерархию Observer.
    - Паттерн Observer определяет часть "View" в модели Model-View-Controller (MVC) .

 Паттерн Observer находит широкое применение в системах пользовательского интерфейса, в которых
 данные и их представления ("виды") отделены друг от друга. При изменении данных должны быть
 изменены все представления этих данных (например, в виде таблицы, графика и диаграммы).
*/

// example

#include <iostream>
#include <vector>
using namespace std;

// 1. "Независимая" функциональность
class Subject {
    // 3. Связь только базовым классом Observer
    vector < class Observer * > views;
    int value;
public:
    void attach(Observer *obs) {
        views.push_back(obs);
    }
    void setVal(int val) {
        value = val;
        notify();
    }
    int getVal() {
        return value;
    }
    void notify();
};

// 2. "Зависимая" функциональность
class Observer {
    Subject *model;
    int denom;
public:
    Observer(Subject *mod, int div) {
        model = mod;
        denom = div;
        // 4. Наблюдатели регистрируются у субъекта
        model->attach(this);
    }
    virtual void update() = 0;
protected:
    Subject *getSubject() {
        return model;
    }
    int getDivisor() {
        return denom;
    }
};

void Subject::notify() {
    // 5. Извещение наблюдателей
    for (int i = 0; i < views.size(); i++)
        views[i]->update();
}

class DivObserver: public Observer {
public:
    DivObserver(Subject *mod, int div): Observer(mod, div){}
    void update() {
        // 6. "Вытягивание" интересующей информации
        int v = getSubject()->getVal(), d = getDivisor();
        cout << v << " div " << d << " is " << v/d << '\n';
    }
};

class ModObserver: public Observer {
public:
    ModObserver(Subject *mod, int div): Observer(mod, div){}
    void update() {
        int v = getSubject()->getVal(), d = getDivisor();
        cout << v << " mod " << d << " is " << v%d << '\n';
    }
};

int main() {
    Subject subj;
    DivObserver divObs1(&subj, 4); // 7. Клиент настраивает число 
    DivObserver divObs2(&subj, 3); //    и типы наблюдателей
    ModObserver modObs3(&subj, 3);
    subj.setVal(14);
}
