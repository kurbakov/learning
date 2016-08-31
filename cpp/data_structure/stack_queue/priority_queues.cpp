#include "iostream"
#include <vector>
//=====================================================================

class Priority_queues{
private:
    std::vector<int> data;
    unsigned long binary_search(int i);
public:
    Priority_queues();
    ~Priority_queues();

    bool empty();
    int size();
    int top();
    void push(int i);
    void pop();
    void print();
};

Priority_queues::Priority_queues() {}
Priority_queues::~Priority_queues() {
    data.clear();
}

bool Priority_queues::empty() {
    if(data.size() == 0)
        return true;

    return false;
}

int Priority_queues::size() {
    return data.size();
}

int Priority_queues::top() {
    return data[data.size()-1];
}

unsigned long Priority_queues::binary_search(int i) {
    unsigned long low = 0;
    unsigned long upp = data.size();

    while( upp-low > 1){

        unsigned long mid = low + (upp-low)/2;

        if(data[mid] > i)
            upp = mid;

        else if (data[mid] < i)
            low = mid;

        else
            return mid;
    }

    return low+1;
}

void Priority_queues::push(int i) {
    if(data.size() == 0) {
        data.push_back(i);
        return;
    }

    if(data.size() == 1){
        if(data[0]>i)
            data.insert(data.begin(),i);
        else
            data.push_back(i);

        return;
    }

    unsigned long position = binary_search(i);
    data.insert(data.begin()+position, i);
}

void Priority_queues::pop() {
    data.erase(data.end());
}

void Priority_queues::print() {
    for (int i=0; i<data.size(); i++)
        std::cout << data[i] << " ";
    std::cout << std::endl;
}


//=====================================================================

int main(){

    std::vector<int> v {1,2,3,5,6,10,7,5,9};

    Priority_queues p;
    for (int i=0; i<v.size(); i++) {
        p.push(v[i]);
        p.print();
    }

    return 0;
}
