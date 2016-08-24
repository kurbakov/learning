/*
 * solution from codility web page
 * the description of the tasl can be found here:
 * https://codility.com/programmers/task/binary_gap/
 *
 * during the solution I took convert function from here:
 * http://www.cplusplus.com/forum/general/65862/
 * */

#include <iostream>
#include <vector>

std::vector<int> convert(int val)
{
    std::vector<int> res;

    unsigned int mask = 1 << (sizeof(int) * 8-1);
    const int size = sizeof(val) * 8;

    for(int i = 0; i < size; i++)
    {
        if( (val & mask) == 0 )
            res.push_back(0) ;
        else
            res.push_back(1) ;

        mask  >>= 1;
    }

    return res;
}

int solution (int N){
    std::vector<int> bit_values;
    bit_values = convert(N);

    int res = 0;
    int counter = 0;
    bool flag = false;

    for (unsigned int i=0; i<bit_values.size(); i++){

        if(bit_values[i] == 1 && flag == true) {
            if(res < counter)
                res = counter;

            counter = 0;
        }
        else if(bit_values[i] == 1 && flag == false) {
            flag = true;
            counter = 0;
        }
        else{
            counter++;
        }
    }
    return res;
}

int main(){
    std::cout << solution(15);
    return 0;
}
