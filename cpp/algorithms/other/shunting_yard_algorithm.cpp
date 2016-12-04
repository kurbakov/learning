// https://en.wikipedia.org/wiki/Shunting-yard_algorithm

#include <iostream>
#include <sstream>
#include "vector"
#include "set"

std::vector<std::string> string_to_vec(std::string str){
    std::vector<std::string> array;
    std::stringstream ss(str);
    std::string temp;
    while (ss >> temp)
        array.push_back(temp);

    return array;
}

std::vector<std::string> vec_to_queue(std::vector<std::string> vec){

    std::set<std::string> set_operators {"+", "-", "*", "/", "^" /* etc. */};
    std::vector<std::string> stack_operators;
    std::vector<std::string> queue_values;

    while(!vec.empty()){

        std::string curr_value = vec[0];

        // operators:
        if(set_operators.find(curr_value) != set_operators.end())
        {
            if(curr_value.compare("*") == 0 && stack_operators.back().compare("/")==0){
                queue_values.push_back("/");
                stack_operators[stack_operators.size()-1] = "*";
            }
            else if(curr_value.compare("/") == 0 && stack_operators.back().compare("*")==0){
                queue_values.push_back("*");
                stack_operators[stack_operators.size()-1] = "/";
            }
            else {
                stack_operators.push_back(curr_value);
            }
        }
        // cases for "(" and ")"
        else if(vec.front().compare("(") == 0)
        {
            stack_operators.push_back(curr_value);
        }
        else if(vec.front().compare(")") == 0)
        {
            while(stack_operators.back() != "("){
                std::string str = stack_operators[stack_operators.size()-1];
                queue_values.push_back(str);
                stack_operators.pop_back();
            }
            stack_operators.pop_back();
        }
        // rest of cases
        else
        {
            queue_values.push_back(curr_value);
        }

        vec.erase(vec.begin());
    }

    std::reverse(stack_operators.begin(), stack_operators.end());
    queue_values.insert(queue_values.end(), stack_operators.begin(), stack_operators.end());
    return queue_values;
}


int main() {
    std::string str = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3";
    std::vector<std::string> vec = string_to_vec(str);

    std::vector<std::string> my_v = vec_to_queue(vec);

    for (int i = 0; i < my_v.size(); ++i) {
        std::cout << my_v[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
