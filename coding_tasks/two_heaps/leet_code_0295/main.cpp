#include <iostream>
#include <queue>

class MedianFinder {
 private:
  std::priority_queue<int, std::vector<int>, std::less<int>> _less;
  std::priority_queue<int, std::vector<int>, std::greater<int>> _greater;

 public:
  MedianFinder() {}

  void addNum(int num) {
    if (_less.empty()) {
      _less.push(num);
      return;
    }

    if (_less.top() < num) {
      _greater.push(num);
    } else {
    }

    if (_less.top() < num && num < _greater.top()) {
    }
  }

  double findMedian() { return 0; }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(int argc, char* argv[]) {
  std::cout << "hello 0295" << std::endl;
  return 0;
}
