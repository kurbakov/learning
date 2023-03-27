#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int subarraySum(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> map;

    int res = 0;
    int sum = 0;
    map[0] = 1;
    for (size_t i = 0; i < nums.size(); ++i) {
      sum += nums[i];

      if (map.find(sum - k) != map.end())
        res += map[sum - k];

      map[sum]++;
    }

    return res;
  }
};

int main(int argc, char* argv[]) {
  std::vector<int> v{1};
  Solution s;
  std::cout << s.subarraySum(v, 0) << std::endl;

  return 0;
}
