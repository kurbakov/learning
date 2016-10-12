#include "iostream"

int gcd1(int a, int b){
    if(a==b)
        return a;
    else if(a>b)
        return gcd1(a-b,b);
    else
        return gcd1(a,b-a);
}


int gcd2(int a, int b){
    if(a%b == 0)
        return b;
    else
        return gcd2(b, a%b);
}

int solution(int N, int M){
    return N/gcd2(M,N);
}

int main(){

    int a = 10;
    int b = 4;
    std::cout << solution(a,b) << std::endl;
    return 0;
}
