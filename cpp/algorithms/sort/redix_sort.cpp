// Source: http://www.geeksforgeeks.org/radix-sort/

#include <iostream>
#include "vector"

void counting_sort(std::vector<int>& v, int exp){
    
    // Find the maximum number to know number of digits
    int max_value = v[0];
    for(unsigned int i=1; i<v.size(); i++)
        if(v[i]> max_value)
            max_value = v[i];

    std::vector<int> output(v.size());
    std::vector<int> count(max_value+1,0);

    // step 3: count elements
    for(unsigned int i=0;i<v.size();i++)
        count[v[i]/exp]++;

    // rebuild index vector to make it incremental
    for(unsigned int i=1;i<count.size();i++)
        count[i] = count[i-1]+count[i];

    // populate target vector
    for(unsigned int i=0; i<v.size(); i++){
        output[count[ (v[i]/exp)%10 ] - 1] = v[i];
        count[ (v[i]/exp)%10 ]--;
    }

    // copy results to v
    for(unsigned int i=0;i<v.size();i++)
        v[i] = output[i];
}


void radix_sort(std::vector<int>& v){

    // Find the maximum number to know number of digits
    int max_value = v[0];
    for(unsigned int i=1; i<v.size(); i++)
        if(v[i]> max_value)
            max_value = v[i];

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; max_value/exp > 0; exp *= 10)
        counting_sort(v, exp);
}


int main() {
    std::vector<int> vec {1,4,1,2,7,5,2};
    radix_sort(vec);

    for(unsigned int i=0; i<vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    return 0;
}
