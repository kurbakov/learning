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
    std::vector<int> peaks;
    std::vector<int> dev;

    for(unsigned int i=1;i<A.size()-1; i++)
        if(A[i]> A[i-1] && A[i]>A[i+1])
            peaks.push_back(i);

    if(peaks.size() == 0)
        return 0;


    for(unsigned int i=peaks.size(); i>0; i--){
        if(A.size()%i==0){
            int block_size = A.size()/i;
            std::vector<bool> found(i, false);
            int found_cnt = 0;
            for(unsigned int k=0; k<peaks.size(); k++) {
                int block_nr = peaks[k]/block_size;
                if(found[block_nr] == false){
                    found[block_nr]=true;
                    found_cnt += 1;
                }
            }

            if(found_cnt == i)
                return i;
        }
    }

    return 0;

}

