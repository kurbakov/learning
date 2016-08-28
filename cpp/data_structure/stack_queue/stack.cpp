#include "iostream"
//=====================================================================

class Stack{
private:
    int size;
    int data[128];

public:

    Stack();
    ~Stack();
    bool empty();
    int get_size();
    int top();
    void push(int i);
    void pop();
};

Stack::Stack() {
    size = 0;
}

Stack::~Stack() {
    size = 0;
}

bool Stack::empty() {
    return size>0? true: false;
}

int Stack::get_size() {
    return size;
}

int Stack::top() {
    return data[size-1];
}

void Stack::push(int i) {
    data [size] = i;
    size += 1;
}

void Stack::pop() {
    size -= 1;
    data[size] = 0;
}

//=====================================================================

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    std::cout<< "top: " << s.top() << std::endl;
    std::cout << "size: " << s.get_size() << std::endl;
    std::cout << "is empty: " << s.empty() << std::endl;

    s.pop();
    s.pop();
    s.pop();
    std::cout << "is empty: " << s.empty() << std::endl;

    s.~Stack();

    return 0;
}
