#include "iostream"
#include <vector>
//=====================================================================

std::vector<int> sieve(int N){
    std::vector<int> primes (N+1, -1);
    int c = 2;
    while(c*c < N+1){
        int ii = 2*c;
        while(ii<N+1){
            primes[ii]=c;
            ii+=c;
        }
        c+=1;
    }
    return primes;
}


std::vector<int> solution(int N, std::vector<int> &P, std::vector<int> &Q){

    std::vector<int> primes = sieve(N);
    std::vector<int> prefix(N+1,0);

    for(int x = 1; x<N+1; x++){
        prefix[x] = prefix[x-1];
        int first_factor = primes[x];
        int second_factor = x/primes[x];

        if(primes[x] != -1 && primes[first_factor] == -1 && primes[second_factor] == -1 ){
            prefix[x] += 1;
        }
    }

    std::vector<int> solution;
    for(unsigned int r = 0; r<Q.size(); r++){
        solution.push_back(prefix[Q[r]] - prefix[P[r]-1]);
    }
    return solution;
}



int main(){
    int n = 26;
    std::vector<int> p {1, 4, 16};
    std::vector<int> q {26, 10, 20};
    std::cout << solution(n,p,q)[0] << std::endl;
    return 0;
}
