#include "iostream"
#include <vector>
#include <map>
#include <math.h>

//https://en.wikipedia.org/wiki/Maximum_subarray_problem
//=====================================================================

int solution(std::vector<int> &A);

//=====================================================================

int main(){

    std::vector<int> a {3,4,3,2,3,-1,3,3};

    std::cout << solution(a) << std::endl;
    return 0;
}

int solution(std::vector<int> &A){
    int max_ending = A[0];
    int max_slice = A[0];

    for(unsigned int i = 1; i<A.size(); i++) {
        max_ending = std::max(A[i], max_ending + A[i]);
        max_slice = std::max(max_slice, max_ending);
    }

    return max_slice;
}

