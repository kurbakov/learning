/*
 * solution from codility web page
 * the description of the task can be found here:
 * https://codility.com/programmers/task/perm_check/
 *
 * */

#include <iostream>
#include "vector"

int solution(std::vector<int> &A){

    int res = 1;

    int max_size = 100010;
    int counter[max_size];

    for (unsigned int i=0; i<A.size(); i++){
        if(A[i]>A.size())
            return 0;

        counter[A[i]-1] += 1;
    }

    for (unsigned int i=0; i<A.size(); i++){
        if(counter[i] == 0)
            res = 0;
    }

    return res;
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
