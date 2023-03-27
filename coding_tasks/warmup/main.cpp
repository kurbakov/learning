#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

void print_vector(std::vector<int>& v) {
  for (auto& el : v)
    std::cout << el << " ";
  std::cout << std::endl;
}

class Solution {
 public:
  std::vector<int> searchRange(std::vector<int>& nums, int target) {
    int found = -1;
    int l = 0, r = nums.size();

    while (r > l) {
      int m = l + (r - l) / 2;
      if (nums[m] == target) {
        found = m;
        break;
      }

      if (nums[m] > target) {
        r = m;
      } else {
        l = m + 1;
      }
    }

    // target is not in the sorted array
    if (found == -1)
      return {found, found};

    // find the most left and the most right

    r = found;
    l = 0;
    while (r > l) {
      int m = l + (r - l) / 2;
      if (nums[m] == target) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    int begin = r;

    l = found;
    r = nums.size();
    while (r > l) {
      int m = l + (r - l) / 2;
      if (nums[m] == target) {
        l = m;
      } else {
        r = m - 1;
      }

      if (m == l)
        break;
    }
    int end = l;

    return {begin, end};
  }
};

int main() {
  Solution s;
  std::vector<int> v{5, 7, 7, 8, 8, 10};

  auto res = s.searchRange(v, 5);
  print_vector(res);

  res = s.searchRange(v, 10);
  print_vector(res);

  res = s.searchRange(v, 7);
  print_vector(res);

  res = s.searchRange(v, 8);
  print_vector(res);

  return 0;
}
