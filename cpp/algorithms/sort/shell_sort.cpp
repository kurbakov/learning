#include <iostream>

// implementation of the algorithm from here
// http://www.tutorialspoint.com/data_structures_algorithms/shell_sort_algorithm.htm
std::vector<int> shell_sort(std::vector<int> arr){

    int interval = 1;
    while (interval<arr.size()/3){
        interval = interval*3+1;
    }

    while (interval>0){

        for(int i = interval; i < arr.size(); i++) {

            int min = arr[i];
            int inner = i;

            while (inner > interval -1 && arr[inner - interval] > min) {
                arr[inner] = arr[inner - interval];
                inner = inner - interval;
            }

            arr[inner] = min;

        }
        interval = (interval-1)/3;

    }

    return arr;
}

void print_vector(std::vector<int> a){
    for(int i=0; i<a.size(); i++){
        std::cout << a[i] << " ";
    }
    std::cout<<std::endl;
}

int main(int argc, char const *argv[])
{
    std::vector<int> my_array;
    for (int i=9; i>=0; i--){
        my_array.push_back(i);
    }
    print_vector(my_array);

    std::vector<int> new_array;
    new_array = shell_sort(my_array);

    print_vector(new_array);

    return 0;
}
