#include "iostream"
#include <vector>
#include <stack>
//=====================================================================

int solution(std::vector<int> &H);

//=====================================================================

int main(){

    std::vector<int> h {8,8,5,7,9,8,7,4,8};

    std::cout << solution(h) << std::endl;
    return 0;
}

int solution(std::vector<int> &H){
    int res = 0;
    std::stack<int> s;
    for(unsigned int i = 0; i<H.size(); i++){
        if(s.size() == 0){
            res += 1;
            s.push(H[i]);
        }
        else{
            if(s.top() > H[i]){
                while(s.size() > 0 && s.top() > H[i]){
                    s.pop();
                }
                i--;
            }
            else if(s.top() < H[i]){
                res += 1;
                s.push(H[i]);
            }
        }
    }

    return res;
}
