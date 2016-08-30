#include "iostream"
//=====================================================================

class Deque{
private:
    int upper_index;
    int lower_index;
    int size;
    int data[128];
    int max_size = 128;

public:

    Deque();
    ~Deque();
    bool empty();
    int get_size();
    int get_max_size();
    int begin();
    int end();
    void push_front(int i);
    void push_back(int i);
    void pop_front();
    void pop_back();
    void clear();
    void emplace(int position, int i);
    void emplace_front(int i);
    void emplace_end(int i);
};

Deque::Deque() {
    upper_index = 0;
    lower_index = 0;
    size = 0;
}

Deque::~Deque() {
    upper_index = 0;
    lower_index = 0;
    size = 0;
}

bool Deque::empty() {
    return size > 0;
}

int Deque::get_size() {
    return size;
}

int Deque::get_max_size(){
    return max_size;
}

int Deque::begin() {
    return data[lower_index];
}

int Deque::end() {
    return data[upper_index-1];
}

void Deque::push_front(int i) {
    if(max_size == size) {
        std::cout << "Deque is full" << std::endl;
        return;
    }

    if(lower_index == 0){
        lower_index = max_size-1;
    }
    else{
        lower_index -= 1;
    }

    size += 1;
    data[lower_index-1] = i;

}

void Deque::push_back(int i) {
    if(max_size == size) {
        std::cout << "Deque is full" << std::endl;
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

void Deque::pop_front() {
    if (size == 0){
        std::cout << "Deque is empty!" << std::endl;
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

void Deque::pop_back() {
    if (size == 0){
        std::cout << "Deque is empty!" << std::endl;
        return;
    }

    if (upper_index == 0){
        upper_index = max_size-1;
    }
    else{
        upper_index -= 1;
    }
    data[upper_index] = 0;
    size -= 1;

}
void Deque::clear() {
    for(int i=0; i<max_size; i++)
        data[i] = 0;
}
void Deque::emplace(int position, int i) {
    int pos = lower_index+position;

    if (pos > max_size)
        pos = pos - max_size;

    if (pos > upper_index)
    {
        std::cout << "you are out of the limit"<<std::endl;
        return;
    }
    else{
        data[pos] = i;
    }
}

void Deque::emplace_front(int i) {
    data[lower_index] = i;
}
void Deque::emplace_end(int i) {
    data[upper_index-1] = i;
}

//=====================================================================

int main(){
    Deque d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);

    std::cout<< "first: " << d.begin() << std::endl;
    std::cout<< "last: " << d.end() << std::endl;
    std::cout << "size: " << d.get_size() << std::endl;
    std::cout << "is empty: " << d.empty() << std::endl;
    for(int i = 0; i<130; i++){
        d.push_back(i);
    }

    for(int i = 0; i<130; i++){
        d.pop_front();
    }

    d.pop_front();
    d.pop_front();
    d.pop_front();
    std::cout << "is empty: " << d.empty() << std::endl;

    d.~Deque();

    return 0;
}
