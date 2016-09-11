#include "iostream"
#include <vector>
#include <math.h>
//=====================================================================

int solution(std::vector<int> &A);

//=====================================================================

int main(){

    std::vector<int> a {3,2,6,-1,4,5,-1,2};

    std::cout << solution(a) << std::endl;
    return 0;
}

int solution(std::vector<int> &A){

    int N = A.size();
    std::vector<int> K1(N,0);
    std::vector<int> K2(N,0);


    for(int i = 1; i < N-1; i++){
        K1[i] = std::max(K1[i-1] + A[i], 0);
    }
    for(int i = N-2; i > 0; i--){
        K2[i] = std::max(K2[i+1]+A[i], 0);
    }

    int max = 0;

    for(int i = 1; i < N-1; i++){
        max = std::max(max, K1[i-1]+K2[i+1]);
    }

    return max;
}
