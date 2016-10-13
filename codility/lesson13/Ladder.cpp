#include "iostream"
#include "vector"

int find_max(std::vector<int> &v){
    int max = v[0];
    for(unsigned int i=1;i<v.size();i++)
        if(v[i]>max)
            max = v[i];
    return max;
}

std::vector<int> solution(std::vector<int> &A, std::vector<int> &B){
    int l = find_max(A);
    int p_max = find_max(B);
    
    std::vector<int> fib(l+2,0);
    fib[1] = 1;
    for(int i=2;i<l+2;i++)
        fib[i] = (fib[i-1]+fib[i-2]) & ((1<<p_max)-1);
    
    std::vector<int> return_arr(A.size(),0);
    
    for(unsigned int idx=0; idx<A.size();idx++)
        return_arr[idx] = fib[A[idx]+1] & ((1<<B[idx])-1);

    return return_arr;
}
