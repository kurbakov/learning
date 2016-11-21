#important CPP keywords 
- Overall: http://en.cppreference.com/w/cpp/keyword
- Definitions: http://www.bogotobogo.com/cplusplus/cplusplus_keywords.php

### const
http://en.cppreference.com/w/cpp/keyword/const

Definition: declare immutable data or functions that do not change data
```
/* be declaretion of the variable you should assign the value */
const int i = 10;
```

### constexpr 
http://en.cppreference.com/w/cpp/keyword/constexpr

Definition: specifies that the value of a variable or function can appear in constant expressions
```
constexpr int f();
```

### explicit
http://en.cppreference.com/w/cpp/keyword/explicit

Definition: only use constructors when they exactly match
```
class Foo{
  Foo(int);
};
int main(){
  Foo f(10); // ok, because exactly like in constructor
  return 0;
}
```

### extern
http://en.cppreference.com/w/cpp/keyword/extern

Definition: eclares a variable or function and specifies that it has external linkage
```
extern const int a = 20;
```

### final
http://en.cppreference.com/w/cpp/language/final

Definition: specifies that a virtual function cannot be overridden in a derived class or that a class cannot be inherited from.
```
struct Base
{
    virtual void foo();
};
 
struct A : Base
{
    void foo() final; // A::foo is overridden and it is the final override
    void bar() final; // Error: non-virtual function cannot be overridden or be final
};
 
struct B final : A // struct B is final
{
    void foo() override; // Error: foo cannot be overridden as it's final in A
};
```

### friend
http://en.cppreference.com/w/cpp/keyword/friend

Definition: grant non-member function access to private data
```
class Foo{
  Foo();
  ~Foo();
  
  friend int some_funct();
};
friend int some_funct(){...}
```

### inline: 
http://en.cppreference.com/w/cpp/language/inline

Definition: optimize calls to short functions
```
inline int some_funct(){...}
```

### mutable
http://en.cppreference.com/w/cpp/keyword/mutable

Definition: override a const variable
```
class Foo
{
...
private:
	mutable int x;
};
```

### noexcept 
http://en.cppreference.com/w/cpp/keyword/noexcept

Definition: specifies whether a function will throw exceptions or not.
```
void f() noexcept; // the function f() does not throw
```

### override
http://en.cppreference.com/w/cpp/language/override

Definition: specifies that a virtual function overrides another virtual function.
```
struct A
{
    virtual void foo();
    void bar();
};
 
struct B : A
{
    void foo() const override;  // Error: B::foo does not override A::foo
                                // (signature mismatch)
    void foo() override;        // OK: B::foo overrides A::foo
    void bar() override;        // Error: A::bar is not virtual
};
```

### register
http://en.cppreference.com/w/cpp/keyword/register

Definition: request that a variable be optimized for speed
```
register int heavy_use;
```

### static
http://en.cppreference.com/w/cpp/keyword/static

Definition: create permanent storage for a variable
```
static int b = 2;
```

### this
http://en.cppreference.com/w/cpp/keyword/this

Definition: a pointer to the current object
```
class Foo{
public:
  Foo(int,int);
private: 
  int x;
  int y;
};
Foo::Foo(int i, int j){
  this->x = i;
  this->y = j;
}
```

### union
http://en.cppreference.com/w/cpp/language/union

Definition: a structure that assigns multiple variables to the same memory location
```
union S
{
  int i;    
  std::string s; 
};
```

### virtual
http://en.cppreference.com/w/cpp/keyword/virtual

Definition: create a function that can be overridden by a derived class
```
Class Foo{
...
  virtual void f();
...
};
```

### volatile
http://en.cppreference.com/w/cpp/keyword/volatile

Definition: warn the compiler about variables that can be modified unexpectedly
```
int square(volatile int *p)
{
    return *p * *p;
}
```
