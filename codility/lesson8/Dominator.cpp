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
    if (A.size() == 0) return-1;

    std::map<int,int> m;

    std::map<int,int>::iterator it;
    for(unsigned int i=0; i<A.size(); i++){
        it = m.find(A[i]);
        if(it == m.end())
            m.insert(std::pair<int,int>(A[i],1));
        else
            it->second += 1;
    }

    int dominator = NULL;
    for (std::map<int,int>::iterator it=m.begin(); it!=m.end(); ++it){
        if(it->second > A.size()/2)
            dominator = it->first;
    }

    for(unsigned int i = 0; i<A.size(); i++)
        if (dominator != NULL & A[i] == dominator)
            return i;

    return -1;
}
