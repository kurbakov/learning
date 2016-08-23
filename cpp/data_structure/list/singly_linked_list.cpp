#include "iostream"
//=====================================================================
// http://www.bogotobogo.com/cplusplus/linkedlist.php
// http://www.tutorialspoint.com/data_structures_algorithms/linked_lists_algorithm.htm


// our new data type
struct Node{
    int data;
    Node *next;
};

void create_list(struct Node *head, int x){
    head->data = x;
    head->next = NULL;
}

void add_node(struct Node *head, int x){
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;

    Node *cur = head;
    while(cur) {
        if(cur->next == NULL) {
            cur->next = newNode;
            return;
        }
        cur = cur->next;
    }
}

bool delete_node(struct Node **head, Node *ptrDel) {
    Node *cur = *head;
    if(ptrDel == *head) {
        *head = cur->next;
        delete ptrDel;
        return true;
    }

    while(cur) {
        if(cur->next == ptrDel) {
            cur->next = ptrDel->next;
            delete ptrDel;
            return true;
        }
        cur = cur->next;
    }
    return false;
}

void insert_front(struct Node **head, int n) {
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = *head;
    *head = newNode;
}

// true if was deleted and false if was not found
bool search_node(struct Node *head, int n) {
    Node *cur = head;
    while(cur) {
        if(cur->data == n)
            return true;
        cur = cur->next;
    }
    return false;
}

void delete_list(struct Node **node)
{
    struct Node *tmpNode;
    while(*node) {
        tmpNode = *node;
        *node = tmpNode->next;
        delete tmpNode;
    }
}

// true is they are the same and false if different
bool compare_lists(struct Node *node1, struct Node *node2)
{

    /* both lists are null and have no differences in nodes */
    if(node1 == NULL && node2 == NULL) {
        return true;
    }

    /* still have elements in the lists and need keep going*/
    else {
        if(node1 == NULL || node2 == NULL)
            return false;
        else if(node1->data != node2->data)
            return false;
        else
            return compare_lists(node1->next, node2->next);
    }
}

void print_list(struct Node *head) {
    Node *list = head;
    while(list) {
        std::cout << list->data << " " << std::endl;
        list = list->next;
    }
}

void copy_list(struct Node *node, struct Node **pNew)
{
    if(node != NULL) {
        *pNew = new Node;
        (*pNew)->data = node->data;
        (*pNew)->next = NULL;
        copy_list(node->next, &((*pNew)->next));
    }
}

int size_of_list(struct Node *head)
{
    Node *cur = head;
    int size = 0;
    while(cur) {
        size++;
        if(cur->next == NULL) {
            return size;
        }
        cur = cur->next;
    }
    return size;
}

void reverse(struct Node** head)
{
    Node *parent = *head;
    Node *me = parent->next;
    Node *child = me->next;

    /* make parent as tail */
    parent->next = NULL;
    while(child) {
        me->next = parent;
        parent = me;
        me = child;
        child = child->next;
    }
    me->next = parent;
    *head = me;
}

bool makeCircular(struct Node* head)
{
    if(head->next==NULL)
        return false;

    Node *cur = head;
    while(cur) {
        if(cur->next == NULL) {
            cur->next = head;
            return true;
        }
        cur = cur->next;
    }
    return false;
}

bool detect_circular(struct Node* head)
{

    if(head->next == NULL)
        return false;

    Node *ptr1 = head;
    Node *ptr2 = head;

    while(ptr1->next != NULL && ptr2->next != NULL) {

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        if(ptr2) {
            ptr2 = ptr2->next;
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
    Node *head = new Node;

    create_list(head, 10);
    add_node(head,30);
    add_node(head,35);

    insert_front(&head,5);
    delete_node(&(head), head->next);

    print_list(head);
    std::cout << "result: " << search_node(head, 5) << std::endl;

    Node *newHead = new Node;
    copy_list(head,&newHead);

    delete_list(&head);
    print_list(newHead);

    Node *newHead_copy = new Node;
    copy_list(newHead, &newHead_copy);

    std::cout << "results of compare is: " << compare_lists(newHead, newHead_copy) << std::endl;

    Node *reverse_list = new Node;
    copy_list(newHead, &reverse_list);
    reverse(&reverse_list);

    print_list(reverse_list);
    std::cout << "results of compare is: " << compare_lists(newHead, reverse_list) << std::endl;

    delete_list(&reverse_list);
    delete_list(&newHead_copy);

    std::cout << "the size of the list: " << size_of_list(newHead) << std::endl;
    std::cout << "is the list cycled: " << detect_circular(newHead) << std::endl;
    makeCircular(newHead);
    std::cout << "is the list cycled: " << detect_circular(newHead) << std::endl;

    return 0;
}
