/*
 * solution from codility web page
 * the description of the task can be found here:
 * https://codility.com/programmers/task/frog_river_one/
 *
 * */

#include <iostream>
#include "vector"
#include "set"

int solution(int X, std::vector<int> &A){
    std::set<int> temp;

    for(int i=0; i<A.size();i++){
        if(A[i] <= X) {
            temp.insert(A[i]);
            if(temp.size() == X)
                return i;
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

    std::cout << solution(5, v);

    return 0;
}
