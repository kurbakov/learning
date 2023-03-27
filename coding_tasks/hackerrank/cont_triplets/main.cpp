#include <iostream>
#include <unordered_map>
#include <vector>

int recursion(std::vector<long>& arr, int idx, int v, long mult, int total) {
  if (total == 3) {
    return 1;
  }

  int res = 0;
  int next_v = v * mult;
  for (size_t i = idx; i < arr.size(); ++i) {
    if (arr[i] == next_v)
      res += recursion(arr, i, next_v, mult, total + 1);
  }

  return res;
}

long countTriplets(std::vector<long> arr, long r) {
  int total = 0;
  for (size_t i = 0; i < arr.size(); ++i) {
    total += recursion(arr, i, arr[i], r, 1);
  }

  return total;
}

int main() {
  std::cout << countTriplets({1, 2, 2, 4}, 2) << std::endl;
  return 0;
}
