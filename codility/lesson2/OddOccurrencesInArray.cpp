/*
 * solution from codility web page
 * the description of the task can be found here:
 * https://codility.com/programmers/task/odd_occurrences_in_array/
 *
 * */

#include <iostream>
#include <vector>

int solution(std::vector<int> &A) {
    int result = 0;
    for (unsigned int i = 0; i < A.size(); i++)
    {
        result ^= A[i];
    }
    return result;
}

int main(){
    std::vector<int> a;
    a.push_back(9);
    a.push_back(3);
    a.push_back(9);
    a.push_back(7);
    a.push_back(7);

    std::cout << solution(a);

    return 0;
}
