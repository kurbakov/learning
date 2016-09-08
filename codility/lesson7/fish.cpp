#include "iostream"
#include <vector>
#include <stack>
//=====================================================================

int solution(std::vector<int> &A, std::vector<int> &B);

//=====================================================================

int main(){

    std::vector<int> a {4,3,2,1,5};
    std::vector<int> b {0,1,0,0,0};

    std::cout << solution(a,b) << std::endl;
    return 0;
}

int solution(std::vector<int> &A, std::vector<int> &B){
    std::stack<int> fish_stack;
    int saved_fishes = 0;

    for(unsigned int i=0; i<A.size(); i++){

        if(B[i] == 1) {
            fish_stack.push(A[i]);
        }

        if(B[i] == 0 && !fish_stack.empty()){
            while(!fish_stack.empty() && A[i]>fish_stack.top()){
                fish_stack.pop();
            }
        }

        if(B[i] == 0 && fish_stack.empty()) {
            saved_fishes += 1;
        }
    }

    return saved_fishes+int(fish_stack.size());
}
