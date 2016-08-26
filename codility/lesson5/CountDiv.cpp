/*
 * solution from codility web page
 * the description of the task can be found here:
 * https://codility.com/programmers/task/count_div/
 *
 * */

#include <iostream>

int solution(int A, int B, int K){
    int lower = A/K;
    int higher = B/K;
    if(A%K == 0) {
        return higher-lower+1;
    }
    else{
        return higher-lower;
    }
}

int main(){

    std::cout << solution(11,345,17);
    return 0;
}
