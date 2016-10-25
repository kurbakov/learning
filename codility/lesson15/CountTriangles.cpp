#include "iostream"
#include "vector"
#include "algorithm"


int solution(std::vector<int> &A){

    std::sort(A.begin(), A.end());

    int n = (int)A.size();
    int result = 0;

    for(int i = 0; i < n-2; i++){
        int k = i + 2;
        for(int j = i + 1; j < n-1; j++){
            while(k < n && A[i] + A[j] > A[k])
                k += 1;
            result += k - j - 1;
        }
    }

    return result;
}


int main(){
    std::vector<int> a {10,2,5,1,8,12};
    std::cout << solution(a) << std::endl;
    return 0;
}
