#include "iostream"
#include <vector>
#include <math.h>
//=====================================================================

int solution(std::vector<int> &A);

//=====================================================================


int main(){
    std::vector<int> a {1,5,3,4,3,4,1,2,3,4,6,2};
    std::cout << solution(a) << std::endl;
    return 0;
}

int solution(std::vector<int> &A){
    int A_len = A.size();
    std::vector<int> next_peak(A.size(), -1);
    int peak_count = 0;
    int first_peak = -1;

    for(int i = A_len-2; i>0; i--){
        if(A[i]> A[i+1] && A[i]>A[i-1]){
            next_peak[i] = i;
            peak_count += 1;
            first_peak = i;
        }
        else{
            next_peak[i] = next_peak[i+1];
        }
    }
    if(peak_count<2)
        return peak_count;

    int max_flags = 1;
    int max_min_distance = int(sqrt(A_len));

    for(int min_distance=max_min_distance+1; min_distance>1; min_distance--){
        int flag_used = 1;
        int flag_have = min_distance-1;
        int pos = first_peak;

        while(flag_have>0){
            if(pos+min_distance >= A_len-1){break;}

            pos = next_peak[pos+min_distance];
            if(pos == -1){ break;}
            flag_used+=1;
            flag_have-=1;
        }
        max_flags = std::max(max_flags, flag_used);
    }
    return max_flags;

}
