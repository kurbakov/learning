
/*
Talking about the complexity I will use BIG-O notation.
Also under the complexity we should understand time complexity and memory usage complexity. 
*/
//=============================================

/*
In the solution 1 we are doing the check weather the vector is empty or not.
In case the vector is empty we return 0.0

During the loop we are not copiening the data,
so the memory usage complexity is also O(1).

For each element in the for loop we call std::sort().
Accordinh to the cpp specification, std::sort() has n*log(n) time complexity.
We are not increasing the memory usage (do not replicate any already existing data).
Also we need to take into the account that n in for loop will be reduces.
So as the result, the final complexity of the std::sort() in for loop is
O(n/2 * log(n/2))

So the overall sum1 function complexity:
time - O((n^2)/2 * log(n/2))
memory - O(1)
*/

double sum1(std::vector& v)
{    
    if (v.empty()) {
        return 0.0;
    }
    for(size_t i = 0; i < v.size() - 1; ++i) {
        std::sort(v.begin()+i, v.end());
        v[i+1] += v[i];
    }
    return v.back();
}

//=============================================
/*
The sum2 function is the copy of the sum1, the only difference, instead of the 
std::sort() std::partial_sort() will be implemented.
for loop stays the same.

std::partial_sort():
time complexity - N*log(M), where 
  N = the distance between first and last  
  M = the distance between first and middle

M is constant and = 2.
In our case we again have the decreasing N
So the average complexity is n/2 * log(M)

M = 2 and log(2) = 1

so the total function complexity is:
time: O((n^2)/2)
memory: O(1)
*/ 

double sum2(std::vector& v)
{    
    if (v.empty()) {
        return 0.0;
    }
    for(size_t i = 0; i < v.size() - 1; ++i) {
        std::partial_sort(v.begin() + i, v.begin() + i + 2, v.end());
        v[i+1] += v[i];
    }
    return v.back();
}


//=============================================
/*
In the function sum3 you changed the approach. So you are not doing any sort.
You copy the vector to the multiset and after that you select first two elements from the set,
compute the sum and remove two elemets, and add the sum to the set.
So we have the memory complexity: O(N) // all elements are copied to set
time complexity: O(n) // we add all elements
*/ 
double sum3(std::vector& v)
{    
    std::multiset set(v.begin(), v.end());
    while (set.size() > 1) {
        std::multiset::const_iterator itA = set.begin();
        std::multiset::const_iterator itB = ++set.begin();
        double c = *itA + *itB;
        set.erase(itA, itB);        
        set.insert(c);
    }
    return !set.empty() ? *set.begin() 
                        : 0.0;
}
