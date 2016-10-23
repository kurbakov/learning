#include "iostream"
#include <vector>
#include <algorithm>

// this solution I took from https://www.martinkysel.com/codility-nailingplanks-solution/
// Thanks to BG (see comments) for this solution

bool nails_enough(int j, std::vector<int> &A, std::vector<int> &B, std::vector<int> &C)
{
    std::vector<int> used_nails (C.begin(),C.begin()+j);
    std::sort(used_nails.begin(),used_nails.end());

    // binary search again for fitted nail
    for(int k = 0; k < (int)A.size(); k++) {
        int last = (int) used_nails.size() - 1;
        int mid = 0;
        int bgn = 0;
        bool found = false;

        while (bgn <= last) {
            mid = (last + bgn) / 2;
            if (used_nails[mid] >= A[k] && used_nails[mid] <= B[k]) {
                found = true;
                break;
            }

            if(used_nails[mid] < A[k])
                bgn = mid + 1;

            else if(used_nails[mid] > B[k])
                last = mid - 1;
        }

        if (!found)
            return false;
    }

    return true;
}

int solution(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C) {
    int last = (int)C.size();
    int bgn = 0;
    int mid = 0;
    int result = -1;
    while(bgn <= last) {
        mid = (last + bgn) / 2;
        if(nails_enough(mid, A, B, C)) {
            last=mid-1;
            result = mid;
        }
        else
            bgn = mid + 1;
    }

    return result;
}

//=====================================================================

int main(){

    std::vector<int> a {1,4,5,8};
    std::vector<int> b {4,5,9,10};
    std::vector<int> c {4,6,7,10,2};

    std::cout << solution(a,b,c) << std::endl;

    return 0;
}

