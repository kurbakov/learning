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
    Node* root;
    unsigned long set_size;
    void rebalance_tree_insert(Node*);
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
    rebalance_tree_insert(n);
}

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
            /*
             source: https://www.youtube.com/watch?v=CTvfzU_uNKE

            delete operation is more complex
            there can be different cases for deletion

            case 1: node red without childrens:
            just delete the node without any other actions

            case 2: delete red or black node with 1 child
            case 2.1: node red with 1 black children:
            just delete the node without any other actions

            case 2.2: node is black with 1 red child:
            delete black and change the color of red to black

            case 3: node is red or black with 2 not-null children-nodes
            find the successor (the smallest value in the highest subtree)
            and replace the node to be deleted by successor. then delete the successor

            case 4:  delete black without children: double black cases (6 cases):

            1. double black is root
            just keep the root black and nothing else


            2. rotation is needed
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
                

            3.
            Initial:
            parent: black
            sibling is black
            siblings children are black
            After transformation:
            parent: double balck !!! next action are required -> case 1,2,3,4,5,6
            sibling is red
            siblings children are black


            4.
            Initial:
            parent:	red
            sibling is black
            siblings children are black
            After transformation:
            parent: black
            sibling is red
            siblings children are black


            5. rotation is needed
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



            6. rotation is needed
            Initial:
            parent: does not metter
            sibling is black
            siblings children are left - does not metter, right is red
            After transformation:
            parent:
            sibling is
            siblings children

            * */

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
