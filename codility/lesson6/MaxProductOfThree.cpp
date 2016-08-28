/*
 * solution from codility web page
 * the description of the task can be found here:
 * https://codility.com/programmers/task/max_product_of_three/
 *
 * */

#include <iostream>
#include <vector>
#include "algorithm"


int solution(std::vector<int> &A){
    std::sort(A.begin(), A.end());

    int prod_beg = A[0]*A[1]*A[A.size()-1];
    int prod_end = A[A.size()-3]*A[A.size()-2]*A[A.size()-1];

    return prod_beg>prod_end?prod_beg:prod_end;
}

int main(){
    std::vector<int> v {4,2,2,5,1,5,8};
    std::cout << "the result is: " << solution(v) << std::endl;

    return 0;
}
