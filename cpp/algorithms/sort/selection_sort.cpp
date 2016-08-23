#include <iostream>

void swap(int &a, int &b){
    a = a+b;
    b = a-b;
    a = a-b;
}

// implementation of the algorithm from here
// http://www.tutorialspoint.com/data_structures_algorithms/selection_sort_algorithm.htm
void selection_sort(int arr[], int arr_size){

    for (int i=0; i<arr_size-1; i++){
        int min = i;
        for (int j=i+1; j<arr_size; j++){

            if(arr[j]<arr[min]){
                min = j;
            }
        }

        if(min != i){
            swap(arr[i], arr[min]);
        }
    }

}


int main(int argc, char const *argv[])
{
    int my_array[] = {9,8,7,6,5,4,3,2,1,0};
    selection_sort(my_array);

    return 0;
}

//===========================================
