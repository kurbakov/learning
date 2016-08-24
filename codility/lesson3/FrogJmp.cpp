/*
 * solution from codility web page
 * the description of the task can be found here:
 * https://codility.com/programmers/task/frog_jmp/
 *
 * */

#include <iostream>

int solution(int X, int Y, int D){

    int distance = Y-X;
    if(distance % D == 0) {
        return distance / D;
    }
    else{
        return distance/D + 1;
    }
}

int main(){

    std::cout << solution(10,85,30);

    return 0;
}
