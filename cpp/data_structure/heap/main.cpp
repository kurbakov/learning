// Source: http://www.sourcetricks.com/2011/06/c-heaps.html

#include <iostream>
#include "vector"

class Heap{
private:
    std::vector<int> heap;
    void fix_insert(int);
    int parent(int);

public:
    Heap();
    ~Heap();

    int get_size();
    void add_node(int);
    void print_heap();
    void delete_min();
    void delete_max();
};

Heap::Heap() {}
Heap::~Heap() {}

int Heap::get_size() { return heap.size();}

void Heap::add_node(int i) {
    heap.push_back(i);
    fix_insert(heap.size() - 1);
}

void Heap::fix_insert(int x) {
    while ( (x>0) && (parent(x)>=0) && (heap[parent(x)]>heap[x]) )
    {
        int tmp = heap[parent(x)];
        heap[parent(x)] = heap[x];
        heap[x] = tmp;
        x = parent(x);
    }
}

int Heap::parent(int child) {
    if (child != 0) {
        int i = (child - 1) >> 1;
        return i;
    }
    return -1;
}

void Heap::print_heap() {
    for(unsigned int i=0;i<heap.size();i++)
        std::cout << heap[i] << " ";
    std::cout<<std::endl;
}

void Heap::delete_max() {
    heap.pop_back();
}

void Heap::delete_min() {
    heap.erase(heap.begin());
}


int main() {
    Heap h;
    std::cout << h.get_size() << std::endl;
    h.add_node(3);
    h.add_node(10);
    h.add_node(5);
    h.add_node(1);

    h.print_heap();

    h.delete_max();
    h.delete_min();

    h.print_heap();
    return 0;
}
