// Source: http://cpp-reference.ru/patterns/structural-patterns/adapter/

/*
 Вам нужно управлять ресурсоемкими объектами. Вы не хотите создавать экземпляры
 таких объектов до момента их реального использования.
 
 Паттерн Proxy для доступа к реальному объекту использует его суррогат или заместитель. 
 Банковский чек является заместителем денежных средств на счете. Чек может быть 
 использован вместо наличных денег для совершения покупок и, в конечном счете, 
 контролирует доступ к наличным деньгам на счете чекодателя.

 Достоинства паттерна Adapter
    - Паттерн Adapter позволяет повторно использовать уже имеющийся код, адаптируя
    его несовместимый интерфейс к виду, пригодному для использования.

 Недостатки паттерна Adapter
    - Задача преобразования интерфейсов может оказаться непростой в случае, если
    клиентские вызовы и (или) передаваемые параметры не имеют функционального
    соответствия в адаптируемом объекте.
*/


// example
#include <iostream>

class FahrenheitSensor
{
public:
    float getFahrenheitTemp() {
        float t = 32.0;
        // ...
        return t;
    }
protected:
    void adjust() {} // Настройка датчика (защищенный метод)
};

class Sensor
{
public:
    virtual ~Sensor() {}
    virtual float getTemperature() = 0;
    virtual void adjust() = 0;
};

class Adapter : public Sensor, private FahrenheitSensor
{
public:
    Adapter() { }
    float getTemperature() {
        return (getFahrenheitTemp()-32.0)*5.0/9.0;
    }
    void adjust() {
        FahrenheitSensor::adjust();
    }
};

int main()
{
    Sensor * p = new Adapter();
    p->adjust();
    std::cout << "Celsius temperature = " << p->getTemperature() << std::endl;
    delete p;
    return 0;
}
