/*
 * solution from codility web page
 * the description of the task can be found here:
 * https://codility.com/programmers/task/cyclic_rotation/
 *
 * */

#include <iostream>
#include <vector>

std::vector<int> solution(std::vector<int> &A, int K){
    if(A.size() == 0)
        return A;

    K = K % A.size();

    std::vector<int> v1(A.begin(), A.begin()+A.size()-K);
    std::vector<int> v2(A.begin()+A.size()-K, A.end());

    std::vector<int> v;
    v.reserve( v1.size() + v2.size() );
    v.insert( v.end(), v2.begin(), v2.end() );
    v.insert( v.end(), v1.begin(), v1.end() );

    return v;
}

void print_vector(std::vector<int> vec){
    for (int i=0; i<vec.size(); i++){
        std::cout << vec[i] << " ";
    }
}

int main(){
    std::vector<int> a;
    a.push_back(3);
    a.push_back(8);
    a.push_back(9);
    a.push_back(7);
    a.push_back(6);

    std::vector<int> vec = solution(a,3);
    print_vector(vec);

    return 0;
}
