#include <iostream>

void swap(int &a, int &b){
    a = a+b;
    b = a-b;
    a = a-b;
}

// implementation of the algorithm from here
// http://www.tutorialspoint.com/data_structures_algorithms/bubble_sort_algorithm.htm
void bubble_sort(int arr[], int arr_size){

    for (int j=0; j < arr_size-1; j++) {
        for (int i = 0; i < arr_size - 1 - j; i++) {

            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }

        }
    }
}


int main(int argc, char const *argv[])
{
    int my_array[] = {9,8,7,6,5,4,3,2,1,0};
    bubble_sort(my_array);

    return 0;
}

//===========================================
