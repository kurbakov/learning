#include <iostream>

class Solution {
 public:
  bool repeatedSubstringPattern(std::string& s) {
    for (int i = 0; i < s.length() - 1; ++i) {
      auto str = s.substr(i, 2);
      auto first = s.find(str, i + 1);

      if (first != std::string::npos)
        return true;
    }

    return false;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  std::string str{"aba"};
  std::cout << s.repeatedSubstringPattern(str) << std::endl;
  return 0;
}
