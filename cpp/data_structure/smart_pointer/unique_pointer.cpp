#include "iostream"

// smart pointer class
template <typename Type>
class unique_pointer{
private:
    Type* t;

public:
    unique_pointer(): t(new Type) {
        std::cout << "unique_pointer() " << this << " = " << t << std::endl;
    }

    unique_pointer(const unique_pointer<Type> &data): t(new Type(*data.t)) {
        std::cout << "unique_pointer() " << this << " = " << t << std::endl;
    }

    unique_pointer<Type> operator= (const unique_pointer<Type> &data) {
        if (&data != this)
        {
            delete t;
            t = new Type(*data.t);
        }
        return *this;
    }

    Type* operator-> () { return t; }
    Type& operator* () { return *t; }

    ~unique_pointer() {
        std::cout << "~unique_pointer() " << this << " = " << t << std::endl;
        delete t;
    }
};


// class to generate a memory leak
class Foo{
    friend class unique_pointer<Foo>;
    char* data;

protected:
    Foo(){std::cout << "Foo is initialized" << std::endl;}
    ~Foo(){std::cout << "Foo destructor worked" << std::endl;}

public:
    void set(char*);
    void print_data();
};

void Foo::set(char* i) {
    data = i;
}

void Foo::print_data() {
    std::cout << data << std::endl;
}

int main(){
    
    while (1) {
        unique_pointer<Foo> sp;
        sp->set("some text");
        sp->print_data();

        unique_pointer<Foo> sp2(sp);

        unique_pointer<Foo> sp3 = sp2;
        sp3->print_data();

        sp = sp3;
    }
    
    return 0;
}

