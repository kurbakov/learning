#include "iostream"
#include <vector>
//=====================================================================

/*
logic is implemented but will not compile!!!!
 My goal was to understand the data type and all internal processes
 So I took the decision to keep it as it is and do not waste the time
 for debugging and fixing. Anyway this code will never be used!

*/

// https://en.wikipedia.org/wiki/Red%E2%80%93black_tree
// https://www.cs.cmu.edu/~fp/courses/15122-f10/lectures/17-rbtrees.pdf

struct Node{
    Node* parent;
    int data;
    char color;
    Node* lower;    /* left     */
    Node* higher;   /* right    */

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
    /* private variables */
    Node* root;
    unsigned long set_size;

    /* private functions */
    void rebalance_tree_insert(Node*);
    void turn_left(Node*);
    void turn_right(Node*);
    Node* find_node(int i);
    Node* find_successor(Node*);
    void delete_subtree(Node*);
    void rebalance_tree_delete(Node*);
    void case_4_1(Node*);
    void case_4_2(Node*);
    void case_4_3(Node*);
    void case_4_4(Node*);
    void case_4_5(Node*);
    void case_4_6(Node*);

public:
    /* constructor and destructor */
    Set();
    ~Set();

    /* publiuc functions */
    bool empty();
    unsigned long size();
    void insert(int i);
    void print_set();
    bool exist(int i);
    void destroy_set();
    void delete_node(int i);
};

/*==============================================================*/
/* private functions */
void Set::rebalance_tree_insert(Node *n) {
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

    rebalance_tree_insert(y);

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

    rebalance_tree_insert(y);
}

Node* Set::find_node(int i){
    Node* cur = root;

    if(root == NULL)
        return cur;


    while (cur != NULL){
        if(cur->data == i)
            return cur;
        else{
            if (i>cur->data)
                cur = cur->higher;
            else
                cur = cur->lower;
        }
    }
    return cur;
}

Node* Set::find_successor(Node* n){
    Node* cur = n->higher;
    while(cur->lower != NULL)
        cur = cur->lower;

    return cur;
}

void Set::delete_subtree(Node * n) {
    if(n != NULL ){
        delete_subtree(n->lower);
        delete_subtree(n->higher);
    }
    delete n;
}

void Set::rebalance_tree_delete(Node* del) {

    // source: https://www.youtube.com/watch?v=CTvfzU_uNKE

    // case 1: red node without children
    if(del->color == 'r' && del->lower == NULL && del->higher == NULL){
        // set parent node pointer to del node NULL
        if(del->data > del->parent->data)
            del->parent->higher = NULL;
        else
            del->parent->lower = NULL;
    }

    // case 2: delete red node with 1 black child or black with 1 red child
    if((del->higher == NULL && del->lower != NULL) || (del->higher != NULL && del->lower == NULL)){
        // case 2.1 node is red one child is null another black
        if(del->color == 'r' && (del->higher->color == 'b' || del->lower->color == 'b')){
            if(del->data > del->parent->data){
                if(del->higher != NULL){
                    del->parent->higher = del->higher;
                    del->higher->parent = del->parent;
                }
                else{
                    del->parent->lower = del->lower;
                    del->lower->parent = del->parent;
                }
            }
        }

        // case 2.2 node is black and 1 red child
        if(del->color == 'b' && (del->higher->color == 'b' || del->lower->color == 'b')){
            if(del->data > del->parent->data){
                if(del->higher != NULL){
                    del->parent->higher = del->higher;
                    del->higher->parent = del->parent;
                    del->higher->color = 'b';
                }
                else{
                    del->parent->lower = del->lower;
                    del->lower->parent = del->parent;
                    del->lower->color = 'b';
                }
            }
        }
    }

    // case 3: node has 2 children
    if(del->higher != NULL && del->lower != NULL){

        // find the successor (the smallest value in the highest subtree)
        Node* successor = find_successor(del);

        // replace the node to be deleted by successor. then delete the successor
        del->data = successor->data;
        del = successor;
        rebalance_tree_delete(del);
    }

    // case 4 double black
    if(del->color == 'b' && del->lower == NULL && del->higher == NULL){
        del->color = 'd'; // double black

        //case 4.1: delete the root
        if(del == root){
            case_4_1(root);
        }

        // not root:
        Node* parent;
        Node* sibling;
        Node* sibling_lower;
        Node* sibling_higher;

        parent = del->parent;
        if(del->data > parent->data)
            sibling = parent->lower;
        else
            sibling = parent->higher;
        sibling_lower = sibling->lower;
        sibling_higher = sibling->higher;

        //case 4.2
        if(parent->color == 'b' && sibling->color == 'r' && sibling_lower->color == 'b' && sibling_higher->color == 'b'){
            case_4_2(parent);
        }

        //case 4.3
        else if(parent->color == 'b' && sibling->color == 'b' && sibling_lower->color == 'b' && sibling_higher->color == 'b'){
            case_4_3(parent);
            rebalance_tree_delete(parent);
        }

        //case 4.4
        else if(parent->color == 'r' && sibling->color == 'b' && sibling_lower->color == 'b' && sibling_higher->color == 'b'){
            case_4_4(parent);
        }

        //case 4.5
        else if(parent->color == 'b' && sibling->color == 'b' && sibling_lower->color == 'r' && sibling_higher->color == 'b'){
            case_4_5(parent);
            rebalance_tree_delete(del);
        }

        //case 4.6
        else if(sibling->color == 'b' && sibling_higher->color == 'r'){
            case_4_6(parent);
        }

    }

    return;
}

void Set::case_4_1(Node* parent) {
    destroy_set();
}

void Set::case_4_2(Node* parent) {
    /*
    Initial:
        parent: black
        sibling is red
        siblings children are black
    After transformation:
        drandparent: black
        parent: red
        uncle: black
        brother: black
            after the trunsformation we still have a double black node
            next actions are required -> case 1,2,3,4,5,6
    */

    Node* sibling_red;
    Node* double_black;

    if(parent->lower->color == 'r') {
        sibling_red = parent->lower;
        double_black = parent->higher;
    }
    else {
        sibling_red = parent->higher;
        double_black = parent->lower;
    }

    Node* sibling_red_lower = sibling_red->lower;
    Node* sibling_red_higher = sibling_red->higher;

    double_black->parent = sibling_red;
    if(double_black->data > sibling_red->data) {
        sibling_red->higher = double_black;
        sibling_red->lower = sibling_red_higher;
        sibling_red_lower->parent = parent;
        parent->lower = sibling_red_lower;
    }
    else {
        sibling_red->lower = double_black;
        sibling_red->higher = sibling_red_lower;
        sibling_red_higher->parent = parent;
        parent->higher = sibling_red_higher;
    }
}

void Set::case_4_3(Node* parent) {

    /*
    Initial:
        parent: black
        sibling is black
        siblings children are black
    After transformation:
        parent: double black !!! next action are required -> case 1,2,3,4,5,6
        sibling is red
        siblings children are black
     */

    if (parent->lower->color == 'd') { // double black
        parent->higher->color = 'r';
        parent->lower->color = 'b';
    }
    else {
        parent->lower->color = 'r';
        parent->higher->color = 'b';
    }

    parent->color = 'd';
}

void Set::case_4_4(Node* parent){
    /*
    Initial:
        parent: red
        sibling is black
        siblings children are black
    After transformation:
        parent: black
        sibling is red
        siblings children are black
    */
    parent->color = 'r';
    if(parent->lower->color != 'd')
        parent->lower->color = 'r';
    else
        parent->higher->color = 'r';
}

void Set::case_4_5(Node* parent){
    /*
    Initial:
        parent: black
        sibling is black
        siblings children are right black and left red
    After transformation:
        parent: black
        sibling is red
        siblings children we take the left and put it under the right child
            rotation is only for the part where no double black
            we make the line of nodes
            colors: black (P), black (S), red (SC-r), black (SC-l)
            next action are required -> case 1,2,3,4,5,6
    */
    Node* sibling;
    Node* sibling_lower;
    Node* sibling_higher;
    Node* double_black;
    if(parent->lower->color == 'd'){
        double_black = parent->lower;
        sibling = parent->higher;
        sibling_higher = sibling->higher;
        sibling_lower = sibling->lower;

        parent->higher = sibling_lower;
        sibling_lower->parent = parent;
        sibling_lower->color = 'b';

        sibling_lower->higher = sibling;
        sibling->parent = sibling_lower;
        sibling->lower = NULL;
        sibling->color = 'r';
    }
    else{
        double_black = parent->higher;
        sibling = parent->lower;
        sibling_higher = sibling->higher;
        sibling_lower = sibling->lower;

        parent->lower = sibling_higher;
        sibling_higher->parent = parent;
        sibling_higher->color = 'b';

        sibling_higher->lower = sibling;
        sibling->parent = sibling_higher;
        sibling->higher = NULL;
        sibling->color = 'r';
    }
}

void Set::case_4_6(Node* parent){
    Node* parent_parent = parent->parent;
    Node* double_black;
    Node* sibling;
    Node* sibling_lower;
    Node* sibling_higher;

    if(parent->lower->color == 'd'){ // double black is on the left side
        double_black = parent->lower;
        sibling = parent->higher;
        sibling_lower = sibling->lower;
        sibling_higher = sibling->higher;

        sibling->parent = parent_parent;
        if(parent_parent->data > sibling->data)
            parent_parent->lower = sibling;
        else
            parent_parent->higher = sibling;

        sibling->lower = parent;
        parent->parent = sibling;

        sibling_higher->color = 'b';

        parent->higher = sibling_lower;
        sibling_lower->parent = parent;

        double_black->color = 'b';
    }
    else{
        double_black = parent->higher;
        sibling = parent->lower;
        sibling_lower = sibling->lower;
        sibling_higher = sibling->higher;

        sibling->parent = parent_parent;
        if(parent_parent->data > sibling->data)
            parent_parent->lower = sibling;
        else
            parent_parent->higher = sibling;

        sibling->higher = parent;
        parent->parent = sibling;

        sibling_lower->color = 'b';

        parent->lower = sibling_higher;
        sibling_higher->parent = parent;

        double_black->color = 'b';
    }


}

/*==============================================================*/
/* public functions */
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
    rebalance_tree_insert(n);
}

void Set::print_set() {
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

bool Set::exist(int i) {
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

void Set::delete_node(int i){
    if(set_size == 0)
        return;

    // step 1: find the node
    Node* del = find_node(i);

    if(del == NULL)
        return;

    // rebalense the tree
    rebalance_tree_delete(del);

    // decrease the size value
    set_size -= 1;

    // set root to NULL if we delete the root
    if (del == root) {
        root = NULL;
        return;
    }

    // delete the node
    delete del;
}

//=====================================================================

int main(){

    std::vector<int> v {1,2,3,5,6,10,7,5,9};

    Set s;

    return 0;
}

