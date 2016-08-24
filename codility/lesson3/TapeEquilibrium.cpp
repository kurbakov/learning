/*
 * solution from codility web page
 * the description of the task can be found here:
 * https://codility.com/programmers/task/tape_equilibrium/
 *
 * */

#include <iostream>
#include <vector>

int solution(std::vector<int> &A){

    if(A.size() == 2)
        return abs(A[0]-A[1]);

    int left_sum = A[0];
    int sum_all = 0;
    for (unsigned int i=0; i<A.size(); i++)
        sum_all += A[i];

    int min_value = abs(2*A[0] - sum_all);

    for (unsigned int i=1; i<A.size()-1; i++){
        left_sum = left_sum + A[i];
        min_value = abs(2*left_sum - sum_all)<min_value ? abs(2*left_sum - sum_all) : min_value;
    }

    return min_value;
}

int main(){
    std::vector<int> a;
    a.push_back(3);
    a.push_back(1);
    a.push_back(2);
    a.push_back(4);
    a.push_back(3);

    std::cout << solution(a);

    return 0;
}
