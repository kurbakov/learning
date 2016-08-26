/*
 * solution from codility web page
 * the description of the task can be found here:
 * https://codility.com/programmers/task/passing_cars/
 *
 * */

#include <iostream>
#include <vector>

int solution(std::vector<int> &A){

    int res = 0;
    int cars = 0;

    for (unsigned int i = 0; i<A.size(); i++){
        if(A[i]==0){
            cars += 1;
        }
        else{
            res += cars;
        }

        if(res > 1000000000)
            return -1;
    }

    return res;
}

int main(){

    std::vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);

    std::cout << solution(v);

    return 0;
}
