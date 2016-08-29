#include "iostream"
//=====================================================================

class Stack{
private:
    int size;
    int data[128];
    int max_size = 128;

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
    if(size<max_size){
        data [size] = i;
        size += 1;
    }
    else{
        std::cout << "the stuck is full" << std::endl;
        return;
    }
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
    for(int i = 0; i<130; i++){
        s.push(i);
    }

    s.pop();
    s.pop();
    s.pop();
    std::cout << "is empty: " << s.empty() << std::endl;

    s.~Stack();

    return 0;
}
