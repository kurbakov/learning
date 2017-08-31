/*
some useful links:

http://blog.trsquarelab.com/2015/02/smart-pointer-implementation-in-c.html
https://courses.cs.washington.edu/courses/cse333/12su/lectures/lec13.pdf
http://cs.brown.edu/~jrassi/nyc_cpp_meetup_20131107_smart_pointers.pdf
http://www.codeproject.com/Articles/541067/Cplusplus-Smart-Pointers
http://ee.usc.edu/~redekopp/cs104/slides/L25_DesignPatterns.pdf
http://catalogue.pearsoned.co.uk/samplechapter/0201704315.pdf
https://searchcode.com/codesearch/view/13711578/
http://www.codesynthesis.com/~boris/blog/2009/01/11/shared-ptr-counter/
http://www.aristeia.com/Papers/C++ReportColumns/apr96.pdf
http://geekwentfreak.com/posts/c/shared_ptr_impl_fun/ 
http://www.openguru.com/2015/07/a-simple-sharedptr-implementation-in-c.html
http://www.umich.edu/~eecs381/handouts/C++11_smart_ptrs.pdf 
https://github.com/Evgeny-Bukovski/ForStudentsLearningCpp/blob/master/Pointers/SmartPointer-Part2.cpp
*/

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

