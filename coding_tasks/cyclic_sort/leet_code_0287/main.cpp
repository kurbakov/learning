#include <iostream>
#include <vector>

/*
Implementation
https://leetcode.com/problems/find-the-duplicate-number/description/

Runtime 124 ms Beats 67.75%
Memory 61.3 MB Beats 68.36%
*/

class Solution {
  int visit(std::vector<int>& v, int idx) {
    if (v[idx - 1] == 0)
      return idx;

    int new_idx = v[idx - 1];
    v[idx - 1] = 0;
    return visit(v, new_idx);
  }

 public:
  int findDuplicate(std::vector<int>& nums) {
    int start = nums[nums.size() - 1];

    return visit(nums, start);
  }
};

int main(int argc, char* argv[]) {
  std::vector<int> nums{1, 3, 4, 2, 2};
  Solution s;
  std::cout << s.findDuplicate(nums) << std::endl;
  return 0;
}
