// lambda functions are only from c++11 available!!!
/*
 * Structure of the lambda function:
 * [] () {};
 * [] is the capture list
 * () the argument list
 * {} the function body
 * */

// See more here: http://stackoverflow.com/questions/7627098/what-is-a-lambda-expression-in-c11
// And here: http://www.cprogramming.com/c++11/c++11-lambda-closures.html

#include <iostream>
#include "vector"

// lambda as an argument to increase each element
void external_func1(std::vector<int>& v) {
    std::for_each(v.begin(), v.end(), [](int &n) { n++; });
}

void external_func2(std::vector<int>& v, const int& epsilon) {
    std::for_each(v.begin(), v.end(), [epsilon](int &n){
        if(n>=epsilon)
            std::cout << 0 << " ";
        else
            std::cout << 1 << " ";
    });
};

int main()
{
    // void
    auto func = [] () { std::cout << "Hello world" << std::endl; };
    func();

    // int option 1
    auto val1 = [] (int) {return 10;};
    std::cout << val1 << std::endl;

    // int option 2
    auto val2 = [] () {int x = 10; return x;};
    std::cout << val2 << std::endl;

    std::vector<int> my_v {1,2,3,4,5};
    external_func1(my_v);
    for(int i=0;i<my_v.size();i++)
        std::cout << my_v[i]<<" ";
    std::cout << std::endl;

    external_func2(my_v, 4);

}
