#include "iostream"
#include <vector>
#include <map>
//=====================================================================

int solution(std::vector<int> &A);

//=====================================================================

int main(){

    std::vector<int> a {3,4,3,2,3,-1,3,3};

    std::cout << solution(a) << std::endl;
    return 0;
}

int solution(std::vector<int> &A){
    if (A.size() == 0) return 0;

    std::map<int,int> m;
    std::map<int,int>::iterator it;
    for(unsigned int i=0; i<A.size(); i++){
        it = m.find(A[i]);
        if(it == m.end())
            m.insert(std::pair<int,int>(A[i],1));
        else
            it->second += 1;
    }

    int dominator;
    int total_occur = 0;

    for (std::map<int,int>::iterator it=m.begin(); it!=m.end(); ++it){
        if(it->second > A.size()/2) {
            dominator = it->first;
            total_occur = it->second;
        }
    }

    if(total_occur == 0) return 0;

    int left_counter = 0;
    int right_counrter = total_occur;
    int res  = 0;

    for (unsigned int i = 0; i < A.size(); i++){
        if (A[i] == dominator){
            left_counter += 1;
            right_counrter -= 1;
        }


        if (left_counter > (i+1)/2 && right_counrter > (A.size() - (i+1))/2 ){
            res += 1;
        }
    }

    return res;
}

