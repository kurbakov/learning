#include "iostream"
#include "vector"
#include "algorithm"

int solution(std::vector<int> &A) {
    std::sort(A.begin(), A.end());

    int N = int(A.size());

    if(A[0] >= 0)
        return 2*A[0];

    if(A.back() <= 0)
        return -2*A.back();

    int i = 0, j = N - 1;
    int m = A.back()*2;

    while (i <= j) {
        int tmp = A[i] + A[j];
        m = std::min(m, abs(tmp));

        if (tmp <= 0) i++;
        else j--;
    }

    return m;
}

int main(){

    std::vector<int> test1 {1,4,-3};
    std::vector<int> test2 {-8,4,5,-10,3};

    std::cout << solution(test1) << std::endl;
    std::cout << solution(test2) << std::endl;
    return 0;
}

