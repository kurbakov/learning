#include "iostream"
#include "vector"
#include "algorithm"


int solution(std::vector<int> &A){

    A.erase( std::unique( A.begin(), A.end() ), A.end() );

    if(A[0] >= 0 || A[A.size()-1] <= 0){
        return (int)A.size();
    }

    int break_point;

    for(unsigned int i=1; i<A.size(); i++)
        if (A[i - 1] < 0 && A[i] >= 0)
            break_point = i;

    std::vector<int> negative (A.begin(), A.begin()+break_point);
    std::vector<int> positive (A.begin()+break_point, A.end());

    std::reverse(negative.begin(), negative.end());
    for(unsigned int j =0;j<negative.size();j++)
        negative[j] *= -1;

    int res = 0;
    while(!positive.empty() && !negative.empty()){
        if(negative.front() > positive.front())
            positive.erase(positive.begin());
        else if(negative.front() < positive.front())
            negative.erase(negative.begin());
        else{
            positive.erase(positive.begin());
            negative.erase(negative.begin());
        }
        res += 1;
    }

    return res + (int)positive.size() + (int)negative.size();
}


int main(){
    std::vector<int> a {-5, -3, -1, 0, 3, 6};
    std::cout << solution(a) << std::endl;
    return 0;
}

