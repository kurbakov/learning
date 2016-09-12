#include "iostream"
#include <vector>
#include <math.h>
//=====================================================================

int solution(int);

//=====================================================================

int main(){
    int a = 30;
    std::cout << solution(a) << std::endl;
    return 0;
}


int solution(int A){
    int i = 1;
    int res = 2*(A+1);

    while(i*i <= A){

        if(A%i == 0){
            res = std::min(res, ( i + A/i )*2);
        }
        i += 1;
    }

    return res;
}


