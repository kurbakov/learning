// http://prog-cpp.ru/cpp-child/
// http://www.quizful.net/post/Inheritance-in-C++
// https://code-live.ru/post/cpp-class-inheritance/
// http://cppstudio.com/post/10103/

#include "iostream"

class Parent{
private:
    int private_int;
    void parent_private_func(){std::cout << "parent private function" <<std::endl;}

protected:
    int protected_int;
    void parent_protected_func(){std::cout << "parent protected function" << std::endl;}

public:
    int public_int;
    void parent_public_func(){std::cout << "parent public function" << std::endl;}

    Parent(int x, int y, int z);
};
Parent::Parent(int x, int y, int z) {
    this->private_int = x;
    this->protected_int = y;
    this->public_int = z;
}

/* can access only public functions in Parent class */
class Child1 : public Parent{
private:
    int private_child;

public:
    Child1(int x, int y, int z, int r) : Parent(x, y, z){
        this->private_child = r;
    }
    void child_private(){std::cout << private_child << std::endl;}
};

class Child2 : private Parent{
private:
    int private_child;

public:
    Child2(int x, int y, int z, int r) : Parent(x, y, z){
        this->private_child = r;
    }
    void child_private2(){std::cout << private_child << std::endl;}
    void parent_protected2(){std::cout << protected_int << std::endl;}
};

class Child3 : protected Parent{
private:
    int private_child;

public:
    Child3(int x, int y, int z, int r) : Parent(x, y, z){
        this->private_child = r;
    }
    void child_private3(){std::cout << private_child << std::endl;}
    void parent_protected3(){std::cout << protected_int << std::endl;}
};


int main(){
    /* child public parent */
    Child1 c1(1,2,3,4);
    c1.child_private();
    c1.parent_public_func();

    /* child private parent */
    Child2 c2(1,2,3,4);
    c2.child_private2();
    c2.parent_protected2();

    /* child protected parent */
    Child3 c3(1,2,3,4);
    c3.child_private3();
    c3.parent_protected3();
}
