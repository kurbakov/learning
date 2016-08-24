/*
 * solution from codility web page
 * the description of the task can be found here:
 * https://codility.com/programmers/task/perm_missing_elem/
 *
 * */

#include <iostream>
#include "vector"

int solution(std::vector<int> &A){
    unsigned long int size = A.size()+1;

    unsigned long int sum = 0;
    for(unsigned long int i = 0; i<A.size(); i++)
        sum += A[i];

    unsigned long int expected_value = size*(size+1)/2;
    return int(expected_value-sum);
}

int main(){

    std::vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(5);

    std::cout << solution(v);

    return 0;
}
