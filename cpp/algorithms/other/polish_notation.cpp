// https://en.wikipedia.org/wiki/Polish_notation

#include "iostream"
#include "vector"
#include "sstream"


int solve(std::string oper, int x, int y){

    if( oper.compare("+") == 0)
        return x+y;
    if( oper.compare("-") == 0)
        return x-y;
    if( oper.compare("*") == 0)
        return x*y;
    if( oper.compare("/") == 0)
        return x/y;

}

void print_vector(std::vector<std::string> arr){
    for(int i=0; i<arr.size(); i++){
        std::cout << arr[i]<< " ";
    }
    std::cout<<std::endl;
}

int main(){

    /* initial string */
    std::string input = "- * / 15 - 7 + 1 1 3 + 2 + 1 1";

    /* transform string to vector of strings */
    std::vector<std::string> array;
    std::stringstream ss(input);

    std::string temp;
    while (ss >> temp)
        array.push_back(temp);


    while(array.size()>=3) {

        for (int i = array.size()-3; i >= 0; i--) {
            if (array[i].compare("+") == 0 || array[i].compare("-") == 0 || array[i].compare("*") == 0 || array[i].compare("/") == 0) {

                int value = solve(array[i], std::stoi(array[i + 1]), std::stoi(array[i + 2]));
                std::string str = std::to_string(value);
                array[i] = str;
                array.erase(array.begin()+i+2);
                array.erase(array.begin()+i+1);

                break;
            }
        }

    }

    print_vector(array);
    return 0;
}
