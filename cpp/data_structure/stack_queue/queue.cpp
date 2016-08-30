#include "iostream"
//=====================================================================

class Queue{
private:
    int upper_index;
    int lower_index;
    int size;
    int data[128];
    int max_size = 128;

public:

    Queue();
    ~Queue();
    bool empty();
    int get_size();
    int get_max_size();
    int first();
    int last();
    void push(int i);
    void pop();
};

Queue::Queue() {
    upper_index = 0;
    lower_index = 0;
    size = 0;
}

Queue::~Queue() {
    upper_index = 0;
    lower_index = 0;
    size = 0;
}

bool Queue::empty() {
    return size > 0 ? true : false;
}

int Queue::get_size() {
    return size;
}

int Queue::get_max_size(){
    return max_size;
}

int Queue::first() {
    return data[lower_index];
}

int Queue::last() {
    return data[upper_index-1];
}

void Queue::push(int i) {
    if(max_size == size) {
        std::cout << "the queue is full" << std::endl;
        return;
    }

    size += 1;
    data[upper_index] = i;

    if(upper_index == max_size-1){
        upper_index = 0;
    }
    else{
        upper_index += 1;
    }
}

void Queue::pop() {
    if (size == 0){
        std::cout << "queue is empty!" << std::endl;
        return;
    }

    data[lower_index] = 0;
    size -= 1;

    if (lower_index == max_size-1){
        lower_index = 0;
    }
    else{
        lower_index += 1;
    }

}

//=====================================================================

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    std::cout<< "first: " << q.first() << std::endl;
    std::cout<< "last: " << q.last() << std::endl;
    std::cout << "size: " << q.get_size() << std::endl;
    std::cout << "is empty: " << q.empty() << std::endl;
    for(int i = 0; i<130; i++){
        q.push(i);
    }

    for(int i = 0; i<130; i++){
        q.pop();
    }

    q.pop();
    q.pop();
    q.pop();
    std::cout << "is empty: " << q.empty() << std::endl;

    q.~Queue();

    return 0;
}
