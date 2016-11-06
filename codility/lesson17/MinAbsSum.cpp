// https://codility.com/media/train/solution-min-abs-sum.pdf

#include "iostream"
#include "vector"
#include "algorithm"

int find_max(std::vector<int> &a){
    int res = a[0];

    for (unsigned int i=1; i<a.size(); i++)
        if(res < a[i])
            res = a[i];

    return res;
}


int sum(std::vector<int> &a){
    int res = 0;

    for (int i = 0; i < a.size(); ++i) {
        res += a[i];
    }

    return res;
}


int solution(std::vector<int> &A){
    int N = (int)A.size();
    int M = 0;

    for (int i = 0; i < N; ++i) {
        A[i] = abs(A[i]);
        M = std::max(A[i], M);
    }

    int S = sum(A);
    std::vector<int> count (M+1, 0);

    for (int j = 0; j < N; ++j) {
        count[A[j]] += 1;
    }

    std::vector<int> dp (S+1, -1);
    dp[0] = 0;

    for (int a = 1; a < M+1; ++a) {
        if(count[a] > 0){
            for (int j = 0; j < S; ++j) {
                if(dp[j] >= 0)
                    dp[j] = count[a];
                else if(j>= a && dp[j-a] > 0)
                    dp[j] = dp[j-a] - 1;
            }
        }
    }

    int result = S;
    for (int i = 0; i < S/2+1; ++i) {
        if(dp[i] >= 0)
            result = std::min(result, S-2*i);
    }

    return result;
}

int main(){

    std::vector<int> a {1,5,2,-2};

    std::cout << solution(a) << std::endl;
    return 0;
}

