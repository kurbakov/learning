#include "iostream"

template <typename Type>
class SimpleSmartPointer{
    Type *pointer;
public:
    SimpleSmartPointer(Type *obj)
        : pointer(obj)
        {}

    ~SimpleSmartPointer()
    {
        delete pointer;
    }

    Type* operator->() { return pointer; }
    Type& operator* () { return *pointer; }
};


// class to generate a memory leak
class Foo{
public:

    ~Foo();

    int *data = new int[100];
    void create_memory_leak();
};

void Foo::create_memory_leak(){
    for (int i = 0; i < 100; ++i)
        data[i] = i;
}

Foo::~Foo() {
    delete[] data;
}


int main(){

    while(true){
//        can execute, no memory leak !!!
        SimpleSmartPointer<Foo> ssp(new Foo());
        ssp->create_memory_leak();

//        Really bad idea to run this code: system restart required!!!
//        Foo *f = new Foo;
//        f->create_memory_leak();
    }

    return 0;
}

