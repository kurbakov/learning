/*
 * solution from codility web page
 * the description of the task can be found here:
 * https://codility.com/programmers/task/min_avg_two_slice/
 *
 * */
 
// solution is really shitty.
// from statistical perspective, we need to chack only
// average of 2 and average of 3
// more info about math: https://www.martinkysel.com/codility-minavgtwoslice-solution/


#include <iostream>
#include <vector>


int solution(std::vector<int> &A) {

    double min,ave_2,ave_3;
    int res = 0;
    min = (A[0]+A[1])/static_cast<double>(2);

    for(int i=0; i<A.size()-1; i++){
        ave_2 = (A[i]+A[i+1])/static_cast<double>(2);
        if(ave_2<min){
            min = ave_2;
            res = i;
        }
    }

    for(int i=0; i<A.size()-2; i++){
        ave_3 = (A[i]+A[i+1]+A[i+2])/static_cast<double>(3);
        if(ave_3<min){
            min = ave_3;
            res = i;
        }
    }
    return res;
}

int main(){
    std::vector<int> v {4,2,2,5,1,5,8};
    std::cout << "the result is: " << solution(v) << std::endl;

    return 0;
}
