#include <iostream>
#include <sstream>
#include "vector"
#include "set"
#include <math.h>

std::vector<std::string> string_to_vec(std::string str){
    std::vector<std::string> array;
    std::stringstream ss(str);
    std::string temp;
    while (ss >> temp)
        array.push_back(temp);

    return array;
}

int reverse_pol_notation(std::vector<std::string> vec){

    std::set<std::string> set_operator {"+", "-", "/", "*", "^"};
    std::vector<int> stack;

    for (unsigned int i=0; i < vec.size(); i++) {
        if (set_operator.find( vec[i] ) != set_operator.end() ){
            if(vec[i].compare("+") == 0){
                int val1 = stack[stack.size()-1];
                stack.pop_back();
                int val2 = stack[stack.size()-1];
                stack.pop_back();

                std::cout << val2 << "+" << val1 << std::endl;
                stack.push_back(val2+val1);
            }
            if(vec[i].compare("-") == 0){
                int val1 = stack[stack.size()-1];
                stack.pop_back();
                int val2 = stack[stack.size()-1];
                stack.pop_back();

                std::cout << val2 << "-" << val1 << std::endl;
                stack.push_back(val2-val1);
            }
            if(vec[i].compare("*") == 0){
                int val1 = stack[stack.size()-1];
                stack.pop_back();
                int val2 = stack[stack.size()-1];
                stack.pop_back();

                std::cout << val2 << "*" << val1 << std::endl;
                stack.push_back(val2*val1);
            }
            if(vec[i].compare("/") == 0){
                int val1 = stack[stack.size()-1];
                stack.pop_back();
                int val2 = stack[stack.size()-1];
                stack.pop_back();

                std::cout << val2 << "/" << val1 << std::endl;
                stack.push_back(val2/val1);
            }
            if(vec[i].compare("^") == 0){
                int val1 = stack[stack.size()-1];
                stack.pop_back();
                int val2 = stack[stack.size()-1];
                stack.pop_back();

                std::cout << val2 << "^" << val1 << std::endl;
                stack.push_back(pow(val2,val1));
            }
        }
        else{
            int temp = std::stoi(vec[i]);
            stack.push_back(temp);
        }
    }

    return stack[0];
}


int main() {
    std::string str = "3 4 2 * 1 5 - 2 3 ^ ^ / + ";
    std::vector<std::string> vec = string_to_vec(str);

    int result = reverse_pol_notation(vec);
    std::cout << result << std::endl;

    return 0;
}
