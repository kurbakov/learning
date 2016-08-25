/*
 * solution from codility web page
 * the description of the task can be found here:
 * https://codility.com/programmers/task/missing_integer/
 *
 * */

#include <iostream>
#include "vector"

int solution(std::vector<int> &A){

    std::vector<int> temp (A.size()+1, 0);

    for (unsigned int i=0; i<A.size(); i++){
        if (A[i]>=1 && A[i]<=A.size()+1){
            temp[A[i]-1] += 1;
        }
    }

    for (unsigned int i=0; i<A.size()+1; i++){
        if (temp[i] == 0) {
            return i+1;
        }
    }

    return -1;

}

int main(){

    std::vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(4);
    v.push_back(1);
    v.push_back(2);

    std::cout << solution(v);

    return 0;
}
