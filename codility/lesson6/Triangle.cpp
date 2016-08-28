/*
 * solution from codility web page
 * the description of the task can be found here:
 * https://codility.com/programmers/task/triangle/
 *
 * */

#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int> &A){
    if (A.size()<3)
        return 0;

    std::sort(A.begin(), A.end());

    for(unsigned int i=0; i<A.size()-2; i++){
        if (A[i] >= 0 && A[i] > A[i+2] - A[i+1])
            return 1;
    }

    return 0;
}

int main(){
    std::vector<int> v {4,2,2,5,1,5,8};
    std::cout << "the result is: " << solution(v) << std::endl;

    return 0;
}
