#include "iostream"
#include <vector>
//=====================================================================

/*
......................STILL IN PROGRESS................................
*/


// https://en.wikipedia.org/wiki/Red%E2%80%93black_tree
// https://www.cs.cmu.edu/~fp/courses/15122-f10/lectures/17-rbtrees.pdf
struct Node{
    Node* parent;
    int data;
    char color;
    Node* lower;
    Node* higher;

    Node(int i){
        parent = NULL;
        data = i;
        color = 'r';
        lower = NULL;
        higher = NULL;
    }
};

class Set{
private:
    Node* root;
    unsigned long set_size;
    void rebalance_tree(Node*);
    void turn_left(Node*);
    void turn_right(Node*);

public:
    Set();
    ~Set();

    bool empty();
    unsigned long size();
    void insert(int i);
    void print_set_bsf();
    bool find(int i);
    void destroy_set();
    void delete_subtree(Node*);
    void delete_node(int i);
};

Set::Set() {
    root = NULL;
    set_size = 0;
}
Set::~Set() {
    destroy_set();
}

bool Set::empty() {
    return set_size == 0;
}

unsigned long Set::size() {
    return set_size;
}

void Set::insert(int i) {

    Node* n = new Node(i);

    if(root == NULL) {
        root = n;
        root->color = 'b';
        set_size += 1;
    }
    else{
        Node* cur = root;
        while( cur != NULL ){
            if(cur->data > n->data){
                n->parent = cur;
                cur = cur->lower;
            }
            else if(cur->data < n->data){
                n->parent = cur;
                cur = cur->higher;
            }
            else{return;}
        }

        cur = n->parent;
        if(cur->data > n->data)
            cur->lower = n;
        else
            cur->higher = n;

        set_size += 1;
    }
    rebalance_tree(n);
}

void Set::rebalance_tree(Node *n) {
    if(n == root){
        n->color = 'b';
        return;
    }

    else if(n->parent->color == 'b'){
        return;
    }

    else{
        if(n->data > n->parent->data){
            /* turn left */
            turn_left(n);
        }
        else{
            /* turn right */
            turn_right(n);
        }
    }
}


void Set::turn_left(Node *z){

    Node *y = z->parent;
    Node *x = y->parent;
    Node *temp = x;

    z->color = 'b';

    x->parent = y;
    x->higher = y->lower;
    y->lower = x;

    y->parent = temp->parent;
    temp = temp->parent;

    if(y->data>temp->data)
        temp->higher = y;
    else
        temp->lower = y;

    rebalance_tree(y);

}

void Set::turn_right(Node *y){
    Node* z = y->parent;
    Node* x = z->parent;
    Node* temp = x;

    z->color = 'b';

    x->higher = y->lower;
    x->parent = y;
    y->lower = x;

    z->lower = y->higher;
    z->parent = y;
    y->higher = z;

    y->parent = temp->parent;
    temp = temp->parent;

    if(y->data>temp->data)
        temp->higher = y;
    else
        temp->lower = y;

    rebalance_tree(y);
}


void Set::print_set_bsf() {
    /*обход в ширину*/

    std::vector<Node*> nodes;
    if(root->lower != NULL)
        nodes.push_back(root->lower);
    if(root->higher != NULL)
        nodes.push_back(root->higher);

    while(nodes.size() != 0){

        Node *cur = nodes[0];
        std::cout << cur->data << std::endl;

        if(cur->lower != NULL)
            nodes.push_back(root->lower);
        if(cur->higher != NULL)
            nodes.push_back(root->higher);
        nodes.erase(nodes.begin());
    }
}

bool Set::find(int i) {
    if(root == NULL)
        return false;

    Node* cur = root;
    while (cur != NULL){
        if(cur->data == i)
            return true;
        else{
            if (i>cur->data)
                cur = cur->higher;
            else
                cur = cur->lower;
        }
    }
    return false;
}

void Set::destroy_set() {
    delete_subtree(root);
    set_size = 0;
    root = NULL;
}

void Set::delete_subtree(Node * n) {
    if(n != NULL ){
        delete_subtree(n->lower);
        delete_subtree(n->higher);
    }
    delete n;
}

void Set::delete_node(int i) {
    Node *cur = root;
    while(cur != NULL) {
        if (cur->data == i) {
            // delete operation
            // rebalance operation
            return;
        } else if (i > cur->data) {
            cur = cur->higher;
        } else {
            cur = cur->lower;
        }
    }
    return;
}

//=====================================================================

int main(){

    std::vector<int> v {1,2,3,5,6,10,7,5,9};

    Set s;

    return 0;
}
