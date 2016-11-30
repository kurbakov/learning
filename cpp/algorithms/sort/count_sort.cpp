// Source: http://www.geeksforgeeks.org/counting-sort/

#include <iostream>
#include "vector"

std::vector<int> counting_sort(std::vector<int>& v){
    std::vector<int> res(v.size());

    // step 1: find max element
    int max_element = v[0];
    for(unsigned int i=1;i<v.size();i++)
        if(v[i]>max_element)
            max_element=v[i];

    // step 2: create vector to count with 0 values
    std::vector<int> index(max_element+1,0);

    // step 3: count elements
    for(unsigned int i=0;i<v.size();i++)
        index[v[i]]++;

    // rebuild index vector to make it incremental
    for(unsigned int i=1;i<index.size();i++)
        index[i] = index[i-1]+index[i];

    // populate target vector
    for(unsigned int i=0; i<v.size(); i++){
        index[v[i]] = index[v[i]]-1;
        res[index[v[i]]] = v[i];
    }

    return res;
}


int main() {
    std::vector<int> vec {1,4,1,2,7,5,2};
    std::vector<int> vec_sort = counting_sort(vec);

    for(unsigned int i=0;i<vec_sort.size();i++)
        std::cout << vec_sort[i] << " ";
    std::cout << std::endl;

    return 0;
}
