// Source: http://cpp-reference.ru/patterns/behavioral-patterns/strategy/

/*
 Существуют системы, поведение которых может определяться согласно одному алгоритму из некоторого
 семейства. Все алгоритмы этого семейства являются родственными: предназначены для решения общих
 задач, имеют одинаковый интерфейс для использования и отличаются только реализацией (поведением).
 Пользователь, предварительно настроив программу на нужный алгоритм (выбрав стратегию), получает
 ожидаемый результат.

 Достоинства паттерна Strategy
    - Систему проще поддерживать и модифицировать, так как семейство алгоритмов перенесено в
    отдельную иерархию классов.
    - Паттерн Strategy предоставляет возможность замены одного алгоритма другим в процессе
    выполнения программы.
    - Паттерн Strategy позволяет скрыть детали реализации алгоритмов от клиента.

 Недостатки паттерна Strategy
    - Для правильной настройки системы пользователь должен знать об особенностях всех алгоритмов.
    - Число классов в системе, построенной с применением паттерна Strategy, возрастает.

*/

// example
#include <iostream>
#include <string>

using namespace std;

// Иерархия классов, определяющая алгоритмы сжатия файлов
class Compression
{
public:
    virtual ~Compression() {}
    virtual void compress( const string & file ) = 0;
};

class ZIP_Compression : public Compression
{
public:
    void compress( const string & file ) {
        cout << "ZIP compression" << endl;
    }
};

class ARJ_Compression : public Compression
{
public:
    void compress( const string & file ) {
        cout << "ARJ compression" << endl;
    }
};

class RAR_Compression : public Compression
{
public:
    void compress( const string & file ) {
        cout << "RAR compression" << endl;
    }
};


// Класс для использования
class Compressor
{
public:
    Compressor( Compression* comp): p(comp) {}
    ~Compressor() { delete p; }
    void compress( const string & file ) {
        p->compress( file);
    }
private:
    Compression* p;
};


int main()
{
    Compressor* p = new Compressor( new ZIP_Compression);
    p->compress( "file.txt");
    delete p;
    return 0;
}
