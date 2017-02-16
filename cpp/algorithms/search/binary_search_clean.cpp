#include <iostream>

template <typename T>
int binary_search(T* Data, int Data_Size, T search_element){

    // is array is empty
    if(Data_Size == 0) return -1;

    int lower_index = 0;
    int higher_index = Data_Size;
    int middle;

    while(higher_index>=lower_index>0){

        middle = lower_index + (higher_index-lower_index)/2;

        if(search_element==Data[middle]){
            // data is found on the position MIDDLE
            return middle;
        }
        else if(search_element>Data[middle]){
            lower_index = middle+1;
        }
        else if(search_element<Data[middle]){
            higher_index = middle-1;
        }

    }

    // data is not found
    return -1;
}

// simple struct to test the binary search
struct Node{
    int data;
    void set(int d){ data = d; }
};

bool operator<(Node l, Node r){
    return l.data < r.data;
}

bool operator>(Node l, Node r){
    return l.data > r.data;
}

bool operator==(Node l, Node r){
    return l.data == r.data;
}

int main(){
    const int SIZE = 10;

    Node *data_array = new Node[SIZE];

    // insert from 0 to SIZE-1
    for(int i=0; i<SIZE; i++)
        data_array[i].set(i);

    Node element;

    // lower minimum
    element.set(0);
    std::cout << binary_search(data_array, SIZE, element) << std::endl;

    // higher minimum
    element.set(SIZE-1);
    std::cout << binary_search(data_array, SIZE, element) << std::endl;

    // inside the array
    element.set(SIZE/2);
    std::cout << binary_search(data_array, SIZE, element) << std::endl;

    // out of the array: positive
    element.set(SIZE+10);
    std::cout << binary_search(data_array, SIZE, element) << std::endl;

    // out of the array: negative
    element.set(-10);
    std::cout << binary_search(data_array, SIZE, element) << std::endl;

    return 0;
}
