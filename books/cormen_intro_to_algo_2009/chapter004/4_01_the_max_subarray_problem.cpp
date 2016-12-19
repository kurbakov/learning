#include <iostream>
#include <vector>
#include "tuple"

#define INF 1000

// p. 72-73 (in PDF p. 92-93)

std::tuple<int, int, int> FIND_MAX_CROSSING_SUBARRAY(std::vector<int> &A, int low, int mid, int high){
    int left_sum = -INF;
    int right_sum = -INF;
    int sum = 0;

    int max_left = -1, max_right = -1;

    for(int i=mid; i>low; i--){
        sum = sum+A[i];
        if(sum>left_sum){
            left_sum = sum;
            max_left = i;
        }
    }

    sum = 0;
    for(int j=mid+1; j<high; j++){
        sum = sum + A[j];
        if(sum>right_sum){
            right_sum = sum;
            max_right = j;
        }
    }
    return std::make_tuple(max_left, max_right, left_sum+right_sum);
}


std::tuple<int, int, int> FIND_MAXIMUM_SUBARRAY(std::vector<int> &A, int low, int high){
    if(low == high){
        return std::make_tuple(low,high,A[low]);
    }
    else{
        int mid = (low+high)/2;
        std::tuple<int,int,int> left = FIND_MAXIMUM_SUBARRAY(A,low,mid);
        std::tuple<int,int,int> right = FIND_MAXIMUM_SUBARRAY(A,mid+1,high);
        std::tuple<int,int,int> cross = FIND_MAX_CROSSING_SUBARRAY(A,low,mid,high);

        if(std::get<2>(left) >= std::get<2>(right) && std::get<2>(left) >= std::get<2>(cross)){
            return left;
        }
        else if(std::get<2>(right) >= std::get<2>(left) && std::get<2>(right) >= std::get<2>(cross)){
            return right;
        }
        else{
            return cross;
        }
    }
}

int main()
{
    std::vector<int> prices {100,113,110,85,105,102,86,63,81,101,94,106,101,79,94,90,97};
    std::vector<int> diff(prices.size()-1);

    for(unsigned int i=0; i<prices.size()-1; i++)
        diff[i] = prices[i+1] - prices[i];

    auto res = FIND_MAXIMUM_SUBARRAY(diff,0,int(diff.size()));
    std::cout << std::get<0>(res) << std::endl;

    return 0;
}
