#include "iostream"
#include <vector>
#include <math.h>
//=====================================================================

int solution(std::vector<int> &A);

//=====================================================================

int main(){

    std::vector<int> a {23171,21011,21123,21366,21013,21367};

    std::cout << solution(a) << std::endl;
    return 0;
}


int solution(std::vector<int> &A){
    if(A.size() < 2) return 0;

    int max_end, max_slice;

    max_end = 0;
    max_slice = 0;

    for (unsigned int i =1; i<A.size(); i++) {
        int diff = A[i] - A[i-1];
        max_end = std::max(0, max_end+diff);
        max_slice = std::max(max_end, max_slice);
    }

    return max_slice;
}

