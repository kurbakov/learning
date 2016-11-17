// http://www.learncpp.com/cpp-tutorial/911-the-copy-constructor/
// http://www.learncpp.com/cpp-tutorial/915-shallow-vs-deep-copying/

#include "cstring"
#include "iostream"

/* simple copy */
class Foo{
private:
    int a;
    int b;

public:
    /* constructor */
    Foo(int, int);

    /* copy constructor */
    Foo(const Foo& f);

    /* print function */
    void print(){std::cout << a << " " << b << std::endl; }
};

Foo::Foo(int i, int k) {
    this->a = i;
    this->b = k;
}

Foo::Foo(const Foo &f) {
    a = f.a;
    b = f.b;
    std::cout << "Copy constructor called" << std::endl;
}


/* deep copy */
class Boo{
private:
    char* str_value;
    int str_length;

public:
    /* constructor */
    Boo(const char*);
    /* destructor */
    ~Boo();

    /* deep copy constructor */
    Boo(const Boo&);
    Boo&operator=(const Boo&);
    char* getString() { return str_value; }
    int getLength() { return str_length; }
};

Boo::Boo(const char* source) {
    str_length = strlen(source)+1;
    str_value = new char[str_length];
    for (int i=0; i < str_length; ++i)
        str_value[i] = source[i];

    str_value[str_length-1] = '\0';
}
Boo::~Boo() {
    delete[] str_value;
}
Boo::Boo(const Boo &b) {
    str_length = b.str_length;

    if(b.str_value){
        str_value = new char[str_length];
        for(int i = 0; i < str_length; i++)
            str_value[i] = b.str_value[i];
    } else{
        str_length = 0;
    }
}

Boo& Boo::operator=(const Boo &b) {
    // check for self-assignment
    if (this == &b)
        return *this;

    // first we need to deallocate any value that this string is holding!
    delete[] str_value;

    // because m_length is not a pointer, we can shallow copy it
    str_length = b.str_length;

    // m_data is a pointer, so we need to deep copy it if it is non-null
    if (b.str_value)
    {
        // allocate memory for our copy
        str_value = new char[str_length];

        // do the copy
        for (int i=0; i < str_length; ++i)
            str_value[i] = b.str_value[i];
    }
    else
        str_value = 0;

    return *this;

}

int main(){
    Foo sample(1,2);
    Foo copy_sample(sample);
    copy_sample.print();

    Boo boo("some string");
    std::cout << boo.getString() << std::endl;

    Boo b(boo);
    std::cout << b.getString() << std::endl;

    Boo a("another string");
    
    b = a;
    std::cout << b.getString() << std::endl;
}
