#include <iostream>

int run_binary_search(int arr[], int value, int from, int arr_size){

    if ((arr_size - from) >= 2){
        int middle_value = from + (arr_size-from)/2;

        if (arr[middle_value] == value){
            return middle_value;
        }

        else if(arr[middle_value] < value){
            return run_binary_search(arr, value, middle_value, arr_size);
        }

        else if(arr[middle_value] > value){
            return run_binary_search(arr, value, from, middle_value);
        }
    }

    else{
        if(arr[from]==value){
            return from;
        }
        else if(arr[arr_size] == value){
            return arr_size;
        }
        else{
            return -1;
        }
    }

}

int binary_search(int arr[], int size_arr, int value){
    int from = 0;
    int to = size_arr-1;

    return run_binary_search(arr, value, from, to);
}

int main(int argc, char const *argv[])
{
    int array_values[] = {0,1,2,3,4,5,6,7,8,9};
    int array_size = 10;

    int is_array_has;
    is_array_has = binary_search(array_values, array_size, 5);

    std::cout << "the search value position in array: " << is_array_has << std::endl;

    return 0;
}
