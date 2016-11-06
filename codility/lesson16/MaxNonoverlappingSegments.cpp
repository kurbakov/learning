#include "iostream"
#include "vector"

int solution(std::vector<int> &A, std::vector<int> &B) {
    if (A.size() < 2)
        return (int) A.size();

    int count = 1;
    int end = B[0];
    int index = 1;

    while (index < (int)A.size()){
        while (index < (int)A.size() && A[index] <= end)
            index += 1;

        if (index == (int)A.size())
            break;

        count += 1;
        end = B[index];

    }

    return count;
}

int main(){

    std::vector<int> a {1,3,7,9,9};
    std::vector<int> b {5,6,8,9,10};

    std::cout << solution(a, b) << std::endl;
    return 0;
}

