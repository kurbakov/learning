#include "iostream"
#include "vector"

int solution(int K, std::vector<int> &A) {
    int count = 0;
    int len = 0;

    for(unsigned int i=0; i<A.size(); i++){
        len += A[i];

        if(len >= K){
            count += 1;
            len = 0;
        }
    }
    return count;
}

int main(){

    std::vector<int> a {1,2,3,41,1,3};
    int k = 4;

    std::cout << solution(k, a) << std::endl;
    return 0;
}

