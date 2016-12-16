#include <iostream>
#include <vector>

// p. 18 (PDF p. 39): INSERTION-SORT(A0
template <typename T>
void insert_sort(std::vector<T> &v){
    if(v.size()<2) {return;}

    for(int j=1; j<v.size(); j++){
        T key = v[j];
        int i = j-1;
        while(j>0 && v[i]>key){
            v[i+1] = v[i];
            i = i-1;
        }
        v[i+1] = key;
    }
}

template <typename T>
void print_vector(std::vector<T> &v){
    for(unsigned int i=0;i<v.size(); i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> a {5,2,4,6,1,3};
    insert_sort(a);
    print_vector(a);

    std::vector<char> b {'a','x','g','t','i','q'};
    insert_sort(b);
    print_vector(b);

    return 0;
}

