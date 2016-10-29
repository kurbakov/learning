#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

struct Node{
    std::string key;
    Node * Next;

    // constructor of struct
    Node(std::string data){
        key = data;
        Next = NULL;
    }
};

class hash_table{
private:
    int SIZE;
    std::vector<Node> values;
    int hash_function(std::string);

public:
    hash_table(int size);

    void clear();
    bool is_empty();
    void insert(std::string);
    bool find(std::string);
    void remove(std::string);
};


//==========================================
// private functions
int hash_table::hash_function(std::string key_value) {
    // hash function is from here (p.3) just as an example
    // http://www.cs.cmu.edu/~guna/15-123S11/Lectures/Lecture17.pdf

    int p = 101;

    // reverse the chars vector
    std::reverse(key_value.begin(),key_value.end());
    unsigned long res = key_value[0];

    for(unsigned int i=1; i<key_value.length(); i++){
        int s = int(key_value[i]) - 48;
        res = s+p*res;
    }
    return int(res % SIZE);
}


//==========================================
// public functions
hash_table::hash_table(int size) {
    SIZE = size;
    values.reserve(size);
}

void hash_table::clear() {
    SIZE = 0;
    for(int i = 0; i<values.size(); i++){
        Node* cur = &values[i];
        if(!cur->key.empty()) {
            while (cur != NULL) {
                Node *temp = cur;
                cur = cur->Next;
                delete temp;
            }
        }
    }
    values.clear();
}

bool hash_table::is_empty() {
    return SIZE == 0;
}

void hash_table::insert(std::string key_value) {

    int hash_value = hash_function(key_value);
    Node* cur = &values[hash_value];

    if(cur->key.empty()) {
        cur->key = key_value;
        return;
    }

    if(cur->key == key_value)
        return;

    while(cur->Next != NULL){
        if(cur->key == key_value)
            return;

        cur = cur->Next;
    }

    Node* new_node = new Node(key_value);
    cur->Next = new_node;
    return;
}

bool hash_table::find(std::string key_value) {

    int hash_value = hash_function(key_value);
    Node* cur = &values[hash_value];

    if(cur->key == key_value){
        return true;
    }
    else{
        while(cur->Next != NULL){
            cur = cur->Next;

            if(cur->key == key_value)
                return true;
        }
    }

    return false;
}

void hash_table::remove(std::string key_value) {

    int hash_value = hash_function(key_value);
    Node* cur = &values[hash_value];

    // case 1: in vector without Next element
    if(cur->key == key_value && cur->Next == NULL){
        cur->key.clear();
        return;
    }

    // case 2: in vector with Next element
    if(cur->key == key_value && cur->Next != NULL){
        Node* n_del = cur->Next;
        cur->key = n_del->key;
        cur->Next = n_del->Next;
        delete(n_del);
    }

    // case 3: node in the linked list
    if(!cur->key.empty()){
        while(cur->Next->Next != NULL){
            if(cur->Next->key == key_value){
                Node* n_del = cur->Next;
                cur->Next = n_del->Next;
                delete(n_del);
                return;
            }
            cur = cur->Next;
        }

        // if the last element in linked list a searched
        if(cur->Next->key == key_value){
            Node* n_del = cur->Next;
            cur->Next = NULL;
            delete(n_del);
            return;
        }
    }

    return;
}

//==========================================
int main(){
    hash_table ht(10);
    ht.insert("habr");

    bool res1 = ht.find("habr");
    std::cout<< res1 << std::endl;

    ht.remove("habr");

    bool res2 = ht.find("habr");
    std::cout<< res2 << std::endl;

    ht.clear();
    return 0;
}

