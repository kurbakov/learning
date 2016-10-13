#include "iostream"
#include "vector"

std::vector<int> fib_from2_to_n(int n){
    std::vector<int> res;
    res.push_back(0);
    res.push_back(1);

    for(int i=2;i<27;i++) {
        if(res[i - 1] + res[i - 2] > n)
            break;
        res.push_back(res[i - 1] + res[i - 2]);
    }

    return res;
}

void print(std::vector<int> &v){
    for(int i =0;i<v.size();i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

int solution(std::vector<int> &A){
    A.push_back(1);

    std::vector<int> fib_set = fib_from2_to_n(A.size());
    std::vector<int> reacheble(A.size(), -1);

    for(unsigned int i = 0; i < fib_set.size(); i++)
        if(A[fib_set[i]-1] == 1)
            reacheble[fib_set[i]-1] = 1;

    for(int idx = 0; idx < A.size(); idx++){
        if(A[idx] == 0 || reacheble[idx] > 0)
            continue;

        int min_idx = -1;
        int min_value = 100000;

        for(unsigned int i = 0; i < fib_set.size(); i++){
            int jump = fib_set[i];
            int previous_idx = idx - jump;

            if(previous_idx < 0)
                break;

            if(reacheble[previous_idx] > 0 && min_value > reacheble[previous_idx]){
                min_value = reacheble[previous_idx];
                min_idx = previous_idx;
            }
        }

        if(min_idx != -1)
            reacheble[idx] = min_value + 1;
    }

    print(A);
    print(fib_set);
    print(reacheble);

    return reacheble.back();

}

int main(){
    std::vector<int> a {0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0};
    std::cout<< solution(a) << std::endl;
    return 0;
}
