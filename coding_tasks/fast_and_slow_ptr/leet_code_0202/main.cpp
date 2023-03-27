#include <iostream>

/*
    Implementation of the task:
    https://leetcode.com/problems/happy-number/

    Runtime 0 ms Beats 100%
    Memory 5.9 MB Beats 77.8%
*/

class Solution {
 public:
  bool isHappy(int n) {
    if (n < 10) {
      return n == 1 || n == 7;
    }

    int res = 0;
    while (n) {
      int dig = n % 10;
      n /= 10;
      res += dig * dig;
    }

    return isHappy(res);
  }
};

int main(int argc, char* argv[]) {
  std::cout << "hello 0202" << std::endl;
  return 0;
}
