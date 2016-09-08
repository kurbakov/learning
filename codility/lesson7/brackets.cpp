#include "iostream"
#include <vector>
#include <stack>
//=====================================================================

int solution(std::string &S);

//=====================================================================

int main(){

    std::string str = "{[()()]}";

    std::cout << solution(str) << std::endl;
    return 0;
}

int solution(std::string &S){

    if(S.length() % 2 == 1) return 0;

    std::stack<char> s;

    for(unsigned int i =0; i<S.size(); i++){
        char ch = S[i];

        switch (ch){
            /* Insert in the stack! */

            case '(':
                s.push(ch);
                break;
            case '{':
                s.push(ch);
                break;
            case '[':
                s.push(ch);
                break;

             /* check nesting */

            case '}':
                if(!s.empty() && s.top() == '{')
                    s.pop();
                else
                    return 0;
                break;

            case ')':
                if(!s.empty() && s.top() == '(')
                    s.pop();
                else
                    return 0;
                break;

            case ']':
                if(!s.empty() && s.top() == '[')
                    s.pop();
                else
                    return 0;
                break;

            default:
                return 0;

        }
    }

    return s.empty()?1:0;
}
