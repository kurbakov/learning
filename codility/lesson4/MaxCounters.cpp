/*
 * solution from codility web page
 * the description of the task can be found here:
 * https://codility.com/programmers/task/max_counters/
 *
 * */

#include <iostream>
#include "vector"

int max(int a, int b){
    return a>b? a:b;
}

void print_vector(std::vector<int> &v){
  for (int i=0;i<v.size();i++)
    std::cout << v[i] << " ";
  std::cout << std::endl;
}

std::vector<int> solution(int N, std::vector<int> &A){
    std::vector<int> res;
    res.assign(N,0);

    int max_value = 0;
    int increase_all_value = 0;

    for (unsigned int i=0; i<A.size(); i++){

        if (A[i] == N+1){
            increase_all_value = max_value;
        }
        else{

            //increase
            res[A[i]-1] = max(res[A[i]-1], increase_all_value);
            res[A[i]-1] += 1;

            //update max
            max_value = max(max_value, res[A[i]-1]);
        }
    }

    for(int i=0; i<N; i++){
        res[i] = max(res[i], increase_all_value);
    }

    return res;
}


int main(){

    std::vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(4);
    v.push_back(1);
    v.push_back(2);
    v.push_back(11);

    print_vector(solution(10,v));

    return 0;
}
