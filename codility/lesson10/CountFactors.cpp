#include "iostream"
#include <vector>
#include <math.h>
//=====================================================================

int solution(int);

//=====================================================================



int main(){
    int a = 24;
    std::cout << solution(a) << std::endl;
    return 0;
}


int solution(int A){
    int i = 1;
    int res = 0;
    int incremental;

    if(A%2 == 0)
        incremental = 1;
    else
        incremental = 2;

    int sqrt_a = sqrt(A);
    if(A / sqrt_a != sqrt_a)
        sqrt_a += 1;

    while(i < sqrt_a){
        if(A%i == 0){
            res += 2;
        }

        i += incremental;
    }

    if(i*i == A)
        res += 1;

    return res;
}


