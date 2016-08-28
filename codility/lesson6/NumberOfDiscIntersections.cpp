/*
 * solution from codility web page
 * the description of the task can be found here:
 * https://codility.com/programmers/task/number_of_disc_intersections/
 *
 * */


#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int>& A)
{
    int len = A.size();
    if (0 == len)
        return 0;

    std::vector<std::pair<long long, long long> > intervals;
    for (int i = 0; i < len; ++i)
        intervals.push_back(std::make_pair(i - (long long)A[i], i + (long long)A[i]));

    std::sort(intervals.begin(), intervals.end());
    int l, h, m, res=0;
    for (int i = 0; i < len - 1; ++i)
    {
        l = i + 1;
        h = len - 1;
        while (l <= h)
        {
            m = l + (h - l) / 2;
            if (intervals[i].second >= intervals[m].first)
                l = m + 1;
            else
                h = m - 1;
        }
        res += l - 1 - i;
        if (res > 10000000)
            return -1;
    }
    return res;
}

int main(){
    std::vector<int> v {4,2,2,5,1,5,8};
    std::cout << "the result is: " << solution(v) << std::endl;

    return 0;
}
