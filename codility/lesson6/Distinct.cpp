/*
 * solution from codility web page
 * the description of the task can be found here:
 * https://codility.com/programmers/task/distinct/
 *
 * */

#include <iostream>
#include <vector>
#include <set>


int solution(std::vector<int> &A){
    std::set<int> res;
    for(unsigned int i = 0; i < A.size(); i++)
        res.insert(A[i]);
    return res.size();
}

int main(){
    std::vector<int> v {4,2,2,5,1,5,8};
    std::cout << "the result is: " << solution(v) << std::endl;

    return 0;
}
