#include "cstring"
#include "iostream"

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
    /* deep assignment operator */
    Boo& operator=(const Boo&);

    /* move operator */
    Boo(Boo&&) noexcept;
    /* move assignment */
    Boo& operator=(Boo&&) noexcept;

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
    if (this == &b)
        return *this;

    delete[] str_value;

    str_length = b.str_length;

    if (b.str_value){
        str_value = new char[str_length];

        for (int i=0; i < str_length; ++i)
            str_value[i] = b.str_value[i];
    }
    else
        str_value = 0;

    return *this;
}
Boo::Boo(Boo &&b) noexcept {
    str_value = b.str_value;
    str_length = b.str_length;

    b.str_length = nullptr;
    b.str_value = nullptr;
}

Boo& Boo::operator=(Boo &&b) noexcept {
    delete[] str_value;
    str_length = b.str_length;
    str_value = b.str_value;

    b.str_length = nullptr;
    b.str_value = nullptr;

    return *this;
}

int main(){

    Boo boo("some string");
    std::cout << boo.getString() << std::endl;

    Boo b(boo);
    std::cout << b.getString() << std::endl;

    Boo a("another string");

    b = a;
    std::cout << b.getString() << std::endl;
}
