#include <iostream>
#include <vector>
#include <sstream>
#include "set"


/*
    tasks can be found here: https://habrahabr.ru/company/yandex/blog/301268/
*/


std::vector<std::string> split_str(std::string str, char split_char)
{
    std::vector<std::string> res;
    std::string temp;

    std::locale loc;

    for (int i=0; i<str.length(); i++) {
        if (str[i] == split_char) {
            str[i] = ' ';
        }
        else {
            str[i] = std::tolower(str[i], loc);
        }
    }

    std::stringstream ss(str);

    while (ss >> temp) {
        res.push_back(temp);
    }

    return res;
}


bool task_a(std::string input_words, int n, std::string dict)
{
    std::vector<std::string> vector_inp = split_str(input_words, ',');
    std::vector<std::string> vector_dict = split_str(dict, ',');

    std::set<std::string> set_dict;
    for(int i=0; i<vector_dict.size(); i++) {
        set_dict.insert(vector_dict[i]);
    }

    for(int i=0; i<vector_inp.size(); i++) {
        if(set_dict.find(vector_inp[i]) == set_dict.end())
            return false;
    }

    return true;
}


int main ()
{
    std::string my_input = "i,love,you";
    std::string my_dict = "i,love,you";
    int n = 10;

    bool res = task_a(my_input, n, my_dict);
    if(res) {
        std::cout << "Correct" << std::endl;
    }
    else {
        std::cout << "Misspell" << std::endl;
    }
}
