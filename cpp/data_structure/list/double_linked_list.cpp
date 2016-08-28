#include "iostream"
//=====================================================================
// http://www.bogotobogo.com/cplusplus/linkedlist.php
// http://www.tutorialspoint.com/data_structures_algorithms/linked_lists_algorithm.htm


// our new data type
struct Node
{
    int value;
    Node *Next;
    Node *Prev;

    // constructor of struct
    Node(int y)
    {
        value = y;
        Next = NULL;
        Prev = NULL;
    }
};


class DoubleLinkedList{
private:
    Node *first;
    Node *last;
    long long size;

public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    void add_front(int x);
    void add_back(int x);
    void print_forward();
    void print_reverse();
    void delete_list();
    long long get_size();
    void reverse();
    bool find_node(Node *n);
    bool delete_node(Node *n);
    bool make_circular();
    bool detect_circular();
};

DoubleLinkedList::DoubleLinkedList() {
    first = NULL;
    last = NULL;
    size = 0;
}

DoubleLinkedList::~DoubleLinkedList() {
    delete_list();
}

void DoubleLinkedList::add_front(int x) {
    Node *n = new Node(x);
    if(first == NULL){
        first = n;
        last = n;
    }
    else{
        first->Prev = n;
        n->Next = first;
        first = n;
    }
    size += 1;
}

void DoubleLinkedList::add_back(int x) {
    Node *n = new Node(x);
    if(last == NULL){
        first = n;
        last = n;
    }
    else{
        last->Next = n;
        n->Prev = last;
        last = n;
    }
    size += 1;
}

void DoubleLinkedList::print_forward() {
    Node *cur = first;
    while(cur != NULL){
        std::cout << cur->value << " ";
        cur = cur->Next;
    }
    std::cout << std::endl;
}

void DoubleLinkedList::print_reverse() {
    Node *cur = last;
    while(cur != NULL){
        std::cout << cur->value << " ";
        cur = cur->Prev;
    }
    std::cout << std::endl;
}
void DoubleLinkedList::delete_list() {
    Node *cur = first;
    while(cur != NULL){
        Node *temp = cur;
        cur = cur->Next;
        delete temp;
    }
    first = NULL;
    last = NULL;
    size = 0;
}

long long DoubleLinkedList::get_size() {
    return size;
}

void DoubleLinkedList::reverse() {
    Node *cur = first;
    while(cur != NULL){
        Node *tmp = cur->Next;
        cur->Next = cur->Prev;
        cur->Prev = tmp;
        if(tmp == NULL){
            last = first;
            first = cur;
        }
        cur = tmp;
    }
}

bool DoubleLinkedList::delete_node(Node *n) {
    Node *cur = first;
    while(cur != NULL){
        if(cur->Next == n) {
            Node *tmp = n->Next;
            cur->Next = tmp;
            tmp->Prev = cur;
            delete n;
            return true;
        }
        cur = cur->Next;
    }
    return false;
}

bool DoubleLinkedList::find_node(Node *n) {
    Node *cur = first;
    while (cur != NULL){
        if(cur->Next == n)
            return true;
        cur = cur->Next;
    }
    return false;
}

bool DoubleLinkedList::make_circular() {
    if(first->Next == NULL){
        return false;
    }

    last->Next = first;
    first->Prev = last;
    return true;
}

bool DoubleLinkedList::detect_circular() {
    if(first->Next == NULL)
        return false;

    Node *ptr1 = first;
    Node *ptr2 = first;

    while(ptr1->Next != NULL && ptr2->Next != NULL) {

        ptr1 = ptr1->Next;
        ptr2 = ptr2->Next;
        if(ptr2) {
            ptr2 = ptr2->Next;
            if(!ptr2)
                return false;
        }
        else {
            return false;
        }

        if(ptr1==ptr2) {
            return true;
        }
    }
    return false;
}

//=====================================================================

int main(){
    DoubleLinkedList *my_list = new DoubleLinkedList();
    my_list->add_back(1);
    my_list->add_back(10);
    my_list->add_back(100);
    my_list->add_front(0);
    my_list->print_forward();
    my_list->print_reverse();
    std::cout << "the size is: " << my_list->get_size() << std::endl;

    my_list->reverse();
    my_list->print_forward();

    my_list->delete_list();


    return 0;
}
