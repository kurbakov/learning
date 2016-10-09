#include "iostream"
#include <vector>
#include "map"
#include "set"
//=====================================================================


int find_max(std::vector<int> &v){
    int res = v[0];
    for(unsigned int i=1; i<v.size(); i++)
        if(v[i]>res)
            res = v[i];
    return res;
}

int sum(std::vector<int> &count_a, std::set<int> &divisors_element){
    std::set<int>::iterator divisor;
    int sum = 0;
    for( divisor = divisors_element.begin(); divisor != divisors_element.end(); divisor++ ){
        sum += count_a[*divisor];
    }
    return sum;
}

std::vector<int> solution(std::vector<int> &A){

    int A_max = find_max(A);
    int size_a = int(A.size());

    // step 1: get the unique list of integers
    // and number of occur. in the input
    std::vector<int> count(A_max+1, 0);
    for(int i = 0; i < size_a; i++){
        count[A[i]] +=1;
    }

    // step 2: Compute the divisors for each element in A
    std::set<int> s;
    std::vector<std::set<int> > divisors(A_max+1, s);

    // step 2.1 each integer can be divided by 1 and itself
    for(int i = 0; i < size_a; i++) {
        divisors[A[i]].insert(A[i]);
        divisors[A[i]].insert(1);
    }

    // step 2.2 find the rest of divisors
    int divisor = 2;
    while (divisor*divisor <= A_max){
        int element_candidate = divisor;
        while (element_candidate  <= A_max){
            bool condition1 = !divisors[element_candidate].empty();
            bool condition2 = divisors[element_candidate].find(divisor) != divisors[element_candidate].end();
            if( condition1 && !condition2){
                divisors[element_candidate].insert(divisor);
                divisors[element_candidate].insert(element_candidate/divisor);
            }
            element_candidate += divisor;
        }
        divisor += 1;
    }

    // step 3: In this loop, we compute results
    std::vector<int> result;
    for(int i=0;i<size_a;i++){
        result.push_back( size_a - sum(count, divisors[A[i]]) );
    }

    return result;
}



int main(){

    std::vector<int> a {3,1,2,3,6};
    std::vector<int> res = solution(a);
    for(int i=0;i<res.size();i++)
        std::cout << res[i] << " ";

    return 0;
}

