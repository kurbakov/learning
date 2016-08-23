#include <iostream>

void swap(int &a, int &b){
    a = a+b;
    b = a-b;
    a = a-b;
}

// implementation of the algorithm from here
// http://www.tutorialspoint.com/data_structures_algorithms/insertion_sort_algorithm.htm
void insertion_sort(int arr[], int arr_size){
    for (int i=1; i<arr_size; i++){

        int j = i;
        while (j > 0 || arr[j-1] > arr[j]){

            swap(arr[j-1], arr[j]);
            j--;

        }
    }
}


int main(int argc, char const *argv[])
{
    int my_array[] = {9,8,7,6,5,4,3,2,1,0};
    insertion_sort(my_array);

    return 0;
}

//===========================================
