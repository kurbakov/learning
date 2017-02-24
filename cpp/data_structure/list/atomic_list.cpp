#include <iostream>
#include <atomic>

template <typename T>
struct Node{
    T data;
    Node* next;

    Node(T d): data(d), next(nullptr) {}
};

template <class T>
class Llist{
private:
    std::atomic<Node<T>*> front;
    std::atomic<Node<T>*> back;
//    std::atomic<int> size;

public:
    Llist(){ back = front = nullptr; }
    Llist(T element){ back = front = new Node<T>(element);}


    void add_front(T element);
    void add_back(T element);

    void pop_front();

    void clean();
    void print();
};

template <class T>
void Llist<T>::add_front(T element) {

    // adding first element
    if(front == back && front == nullptr) {
        front = back = new Node<T>(element);
        return;
    }

    Node<T>* old_front = front.load(std::memory_order_relaxed);
    Node<T>* new_front = new Node<T>(element);

    do{
        new_front->next = front;
    }while(!front.compare_exchange_weak(old_front, new_front, std::memory_order_release, std::memory_order_relaxed));

    return;
}

template <class T>
void Llist<T>::add_back(T element) {

    Node<T>* old_back = back.load(std::memory_order_relaxed);
    Node<T>* new_back = new Node<T>(element);

    do{
        old_back->next = new_back;
    }while(!back.compare_exchange_weak(old_back, new_back, std::memory_order_release, std::memory_order_relaxed));

    return;
}

template <class T>
void Llist<T>::print() {
    for (Node<T>* it = front; it != nullptr; it = it->next)
        std::cout <<it->data << " ";
    std::cout << '\n';
    return;
}


int main(){

    // check if Node struct lock free
    std::atomic<Node<int>> node;
    std::cout << "struct Node is lock free: " << std::boolalpha << std::atomic_is_lock_free(&node) << std::endl;

    // check if List class lock free
    std::atomic<Llist<int>> llist;
    std::cout << "class Llist is lock free: " << std::boolalpha << std::atomic_is_lock_free(&llist) << std::endl;

    Llist<int> l;
    l.add_front(10);
    l.add_front(20);
    l.add_back(30);

    l.print();

    return 0;
}
