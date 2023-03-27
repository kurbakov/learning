#include <iostream>
#include <vector>

/*
    Implementation of:
    https://leetcode.com/problems/missing-number/

    Runtime 7 ms Beats 99.93%
    Memory 18 MB Beats 69.75%
*/

class Solution {
 public:
  int missingNumber(const std::vector<int>& nums) {
    size_t sum = 0;
    for (const auto& num : nums)
      sum += num;

    // Total (0..n) = n * (n + 1) / 2;
    size_t expected = nums.size() * (nums.size() + 1) / 2;

    return expected - sum;
  }
};

int main(int argc, char* argv[]) {
  std::cout << "hello 0876" << std::endl;
  return 0;
}
