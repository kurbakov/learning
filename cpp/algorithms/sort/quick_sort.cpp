#include <iostream>


// http://www.tutorialspoint.com/data_structures_algorithms/quick_sort_algorithm.htm
// http://www.algolist.net/Algorithms/Sorting/Quicksort
void quick_sort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    /* partition */
    while (i < j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            // swap 2 variables
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quick_sort(arr, left, j);
    if (i < right)
        quick_sort(arr, i, right);
}


void print_array(int arr[], int n){
    for(int i=0; i<n; i++){
        std::cout<< arr[i] << " ";
    }
    std::cout<<std::endl;
}

int main(int argc, char const *argv[])
{

    int my_arr [] = {9,8,7,6,5,4,3,2,1,0};
    quick_sort(my_arr, 0, 10);
    print_array(my_arr, 10);

    return 0;
}

