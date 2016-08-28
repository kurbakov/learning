#include "iostream"
//=====================================================================
// http://www.bogotobogo.com/cplusplus/linkedlist.php
// http://www.tutorialspoint.com/data_structures_algorithms/linked_lists_algorithm.htm


// our new data type
struct Node
{
    int value;
    Node *Next;

    // constructor of struct
    Node(int y)
    {
        value = y;
        Next = NULL;
    }
};


class SingleLinkedList{
private:
    Node *first;
    long long size;

public:
    SingleLinkedList();
    ~SingleLinkedList();
    void add_front(int x);
    void add_back(int x);
    void print_forward();
    void delete_list();
    long long get_size();
    void reverse();
    bool find_node(Node *n);
    bool delete_node(Node *n);
    bool make_circular();
    bool detect_circular();
};

SingleLinkedList::SingleLinkedList() {
    first = NULL;
    size = 0;
}

SingleLinkedList::~SingleLinkedList() {
    delete_list();
}

void SingleLinkedList::add_front(int x) {
    Node *n = new Node(x);
    if(first == NULL){
        first = n;
    }
    else{
        n->Next = first;
        first = n;
    }
    size += 1;
}

void SingleLinkedList::add_back(int x) {
    Node *n = new Node(x);
    if(first == NULL){
        first = n;
        size += 1;
        return;
    }
    else{
        Node *cur = first;
        while(cur) {
            if(cur->Next == NULL) {
                cur->Next = n;
                size += 1;
                return;
            }
            cur = cur->Next;
        }
    }
}

void SingleLinkedList::print_forward() {
    Node *cur = first;
    while(cur != NULL){
        std::cout << cur->value << " ";
        cur = cur->Next;
    }
    std::cout << std::endl;
}

void SingleLinkedList::delete_list() {
    Node *cur = first;
    while(cur != NULL){
        Node *temp = cur;
        cur = cur->Next;
        delete temp;
    }
    first = NULL;
    size = 0;
}

long long SingleLinkedList::get_size() {
    return size;
}

void SingleLinkedList::reverse() {
    Node *parent = first;
    Node *me = parent->Next;
    Node *child = me->Next;

    /* make parent as tail */
    parent->Next = NULL;
    while(child) {
        me->Next = parent;
        parent = me;
        me = child;
        child = child->Next;
    }
    me->Next = parent;
    first = me;
}

bool SingleLinkedList::delete_node(Node *n) {
    Node *cur = first;
    while(cur != NULL){
        if(cur->Next == n) {
            cur->Next = n->Next;
            delete n;
            return true;
        }
        cur = cur->Next;
    }
    return false;
}

bool SingleLinkedList::find_node(Node *n) {
    Node *cur = first;
    while (cur != NULL){
        if(cur->Next == n)
            return true;
        cur = cur->Next;
    }
    return false;
}

bool SingleLinkedList::make_circular() {
    if(first->Next==NULL)
        return false;

    Node *cur = first;
    while(cur) {
        if(cur->Next == NULL) {
            cur->Next = first;
            return true;
        }
        cur = cur->Next;
    }
    return false;
}

bool SingleLinkedList::detect_circular() {

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
    SingleLinkedList *my_list = new SingleLinkedList();
    my_list->add_back(1);
    my_list->add_back(10);
    my_list->add_back(100);
    my_list->add_front(0);
    my_list->print_forward();
    std::cout << "the size is: " << my_list->get_size() << std::endl;

    my_list->reverse();
    my_list->print_forward();

    my_list->delete_list();


    return 0;
}
