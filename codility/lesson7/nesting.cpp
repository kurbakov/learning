#include "iostream"
#include <vector>
#include <stack>
//=====================================================================

int solution(std::string &S);

//=====================================================================

int main(){

    std::string str = "(()(())())";

    std::cout << solution(str) << std::endl;
    return 0;
}

int solution(std::string &S){
    std::stack<char> s;
    for(int i =0; i<S.size(); i++){
        char ch = S[i];
        if(ch == '(')
            s.push(ch);
        else if(ch == ')' && !s.empty())
            s.pop();
        else
            return 0;
    }
    return s.size() == 0?1:0;
}
