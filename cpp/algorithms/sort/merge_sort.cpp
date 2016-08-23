#include <iostream>
#include <vector>

// implementation of the algorithm from here
// http://www.tutorialspoint.com/data_structures_algorithms/merge_sort_algorithm.htm
std::vector<int> merge(std::vector<int> a, std::vector<int> b){
    std::vector<int> res;

    while(a.size()>=1 && b.size()>=1){
        if(a[0]>b[0]){
            res.push_back(b[0]);
            b.erase(b.begin());
        }
        else{
            res.push_back(a[0]);
            a.erase(a.begin());
        }
    }

    while(a.size()>=1){
        res.push_back(a[0]);
        a.erase(a.begin());
    }

    while(b.size()>=1){
        res.push_back(b[0]);
        b.erase(b.begin());
    }

    return res;
}

std::vector<int> merge_sort(std::vector<int> arr){
    if(arr.size() == 1){
        return arr;
    }

    std::vector<int> arr1(arr.begin(), arr.begin()+arr.size()/2);
    std::vector<int> arr2(arr.begin()+arr.size()/2, arr.end());

    arr1 = merge_sort(arr1);
    arr2 = merge_sort(arr2);

    return merge(arr1, arr2);
}

void print_vector(std::vector<int> a){
    for(int i=0; i<a.size(); i++){
        std::cout << a[i] << " ";
    }
    std::cout<<std::endl;
}
//==================================================================================

int main(int argc, char const *argv[])
{
    std::vector<int> my_array;
    for (int i=9; i>=0; i--){
        my_array.push_back(i);
    }
    print_vector(my_array);

    std::vector<int> new_array;
    new_array = merge_sort(my_array);

    print_vector(new_array);

    return 0;
}

//===========================================
