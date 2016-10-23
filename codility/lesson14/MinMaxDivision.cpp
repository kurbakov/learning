#include "iostream"
#include <vector>
//=====================================================================

// https://www.martinkysel.com/codility-minmaxdivision-solution/

bool block_size_is_valid(std::vector<int> A, int max_block_cnt, int max_block_size){
    int block_sum = 0;
    int block_cnt = 0;

    for(unsigned int i=0;i<A.size(); i++){
        if(block_sum + A[i] > max_block_size){
            block_sum = A[i];
            block_cnt += 1;
        } else{
            block_sum += A[i];
        }

        if(block_cnt >= max_block_cnt)
            return false;
    }
    return true;
}

int find_max(std::vector<int> A){
    int max_element = A[0];
    for(unsigned int i=1;i<A.size(); i++)
        if(A[i]>max_element)
            max_element = A[i];

    return max_element;
}

int vector_sum(std::vector<int> A){
    int sum = A[0];
    for(unsigned int i=1;i<A.size();i++)
        sum += A[i];

    return sum;
}


int binary_search(std::vector<int> A, int max_block_cnt){
    int lower_bound = find_max(A);
    int upper_bound = vector_sum(A);

    if(max_block_cnt == 1)
        return upper_bound;

    if(max_block_cnt >= A.size())
        return lower_bound;

    while (lower_bound <= upper_bound){

        int candidate_mid = (lower_bound+upper_bound)/2;

        if(block_size_is_valid(A, max_block_cnt, candidate_mid)) {
            upper_bound = candidate_mid - 1;
        }
        else {
            lower_bound = candidate_mid + 1;
        }

    }

    return lower_bound;
}


int solution(int K, int M, std::vector<int> &A){
    return binary_search(A, K);
}

//=====================================================================

int main(){

    std::vector<int> a {2,1,5,1,2,2,2};
    int k = 3;
    int m = 5;

    std::cout << solution(k,m,a) << std::endl;

    return 0;
}

