#include <iostream>
#include <vector>

/*
    Implementation of the Leet Code task:
    https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

    Runtime 12 ms Beats 81.74%
    Memory 7 MB Beats 92.81%
*/

class Solution {
 public:
  int lengthOfLongestSubstring(std::string s) {
    if (s.size() < 2)
      return s.size();

    int global_max = 0;
    int local_max = 0;

    std::vector<bool> unique_chars(256, false);

    auto first = s.begin();
    auto second = s.begin();

    while (second != s.end()) {
      while (second != s.end() && unique_chars[*second] == false) {
        unique_chars[*second] = true;
        second++;
        local_max++;
      }

      global_max = std::max(global_max, local_max);

      while (*first != *second) {
        unique_chars[*first] = false;
        first++;
        local_max--;
      }

      if (*first == *second) {
        unique_chars[*first] = false;
        first++;
        local_max--;
      }
    }

    return std::max(global_max, local_max);
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  std::cout << s.lengthOfLongestSubstring("aabaab!bb") << std::endl;
  return 0;
}
