#include "iostream"
#include "vector"

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


int remove_common_prime_divisors(int x, int y){
    while (x != 1){
        int gcd_value = gcd2(x,y);
        if(gcd_value == 1)
            break;
        x /= gcd_value;
    }
    return x;
}

bool has_some_prime_divisors(int x, int y){
    int gcd_value = gcd2(x,y);
    x = remove_common_prime_divisors(x, gcd_value);
    if(x != 1)
        return false;

    y = remove_common_prime_divisors(y, gcd_value);
    return y == 1;
}

int solution(std::vector<int> &A, std::vector<int> &B){
    int count = 0;
    for(unsigned int i=0; i<A.size(); i++){
        if(has_some_prime_divisors(A[i], B[i]))
            count += 1;
    }
    return count;
}


int main(){
    std::vector<int> a {15,10,3};
    std::vector<int> b {75,20,5};
    std::cout<< solution(a,b) << std::endl;
    return 0;
}
