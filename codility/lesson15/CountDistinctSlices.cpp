#include "iostream"
#include "vector"
#include "algorithm"
/*
  gives only 90% can not pass 1 test
  will investigate later
*/


int solution(int M, std::vector<int> &A){

    std::vector<int> accessed (M+1, -1);

    int result = 0;
    int back = 0;
    int front = 0;

    do{
        if (accessed[A[front]] == -1)
            accessed[A[front]] = front;
        else {
            int newBack = accessed[A[front]] + 1;
            result += (newBack - back) * (front - back + front - newBack + 1) / 2;
            if (result >= 1000000000)   return 1000000000;

            for (int index = back; index< newBack; index++)
                accessed[A[index]] = -1;

            accessed[A[front]] = front;
            back = newBack;

        }
        front += 1;
    }while(front < A.size());

    front -= 1;
    result += (front - back + 1) * (front - back + 2) / 2;

    return std::min(result, 1000000000);
}


int main(){
    int m = 6;
    std::vector<int> a {3, 4, 5, 5, 2};
    std::cout << solution(m,a) << std::endl;
    return 0;
}
