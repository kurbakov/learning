// i wish i knew it before

// Write the copy constructor for the class Foo.
// Ownership of a and b should be maintained by Foo.
// Types A and B are copy-constructible.

// A and B substituted by int and double for testing purposes.
// a,b are splited into inp_ and foo_ for better understanding where is 
// the input variable in class constructor and wher is the private
// variable of the constructor.

#include <iostream>

class Foo {
public:
    Foo(int* inp_a, double* inp_b)
    {
        foo_a = new int;
        foo_a = inp_a;

        foo_b = new double;
        foo_b = inp_b;
    }
    ~Foo() {
        foo_a = NULL;
        delete foo_a;

        foo_b=NULL;
        delete foo_b;
    }

    Foo(const Foo& inp_a, const Foo& inp_b)
    {
        foo_a = inp_a.foo_a;
        foo_b = inp_b.foo_b;
    }
    
    int* get_a(){return foo_a;}
    double* get_b(){return foo_b;}

private:
    int* foo_a;
    double* foo_b;
};

int main()
{
    int a_v = 1;
    int* a = &a_v;

    double b_v = 2;
    double* b = &b_v;

    Foo f = Foo(a, b);
    Foo c = f;
}
