#include "iostream"
#include "vector"

int find_max(std::vector<int> &a){
    int res = a[0];

    for (unsigned int i=1; i<a.size(); i++)
        if(res < a[i])
            res = a[i];

    return res;
}

int solution(std::vector<int> &A) {
    int d = 6;
    int n = (int) A.size();

    std::vector<int> max_score (d,A[0]);

    for(int i = 1; i < n; i++){
        max_score[i%d] = find_max(max_score) + A[i];
    }

    return max_score[(n-1)%d];
}

int main(){

    std::vector<int> a {1,-2,0,9,-1,-2};

    std::cout << solution(a) << std::endl;
    return 0;
}

