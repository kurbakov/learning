#include <iostream>
#include <set>
#include <vector>

class MedianFinder {
  std::multiset<int> low;
  std::multiset<int> high;

 public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) {
    // std::cout << "add: " << num << std::endl;

    // add value to sets
    if (low.empty() || high.empty()) {
      low.insert(num);
    } else {
      if (num >= *high.begin()) {
        high.insert(num);
      } else {
        low.insert(num);
      }
    }

    // normalize sets, so the diff in sizes less then 2
    while ((low.size() - high.size()) * (low.size() - high.size()) > 1) {
      if (low.size() > high.size()) {
        auto val = *low.rbegin();

        low.erase(low.find(val));
        high.insert(val);
      } else {
        auto val = *high.begin();
        high.erase(high.find(val));
        low.insert(val);
      }
    }
    // std::cout << "low: " << *low.rbegin() << " high: " << *high.begin() <<
    // std::endl;
  }

  double findMedian() {
    if (low.size() == high.size()) {
      int sum = (*low.rbegin() + *high.begin());
      return sum * 1.0 / 2;
    } else if (low.size() > high.size()) {
      return *low.rbegin();
    } else {
      return *high.begin();
    }
  }
};

class MedianTree {
  std::multiset<int> elems;
  std::multiset<int>::const_iterator median;

 public:
  void insert(int x) {
    elems.insert(x);

    if (elems.size() == 1) {
      median = elems.begin();
    } else {
      if (x >= *median) {
        if (elems.size() % 2 == 1)
          median++;
      } else {
        if (elems.size() % 2 == 0)
          median--;
      }
    }
  }

  void remove(int x) {
    auto it = elems.lower_bound(x);
    if (it == median) {
      if (elems.size() % 2)
        median--;
      else
        median++;
    } else if (x <= *median) {
      if (elems.size() % 2 == 0)
        median++;
    } else {
      if (elems.size() % 2)
        median--;
    }
    elems.erase(it);
  }

  int get_median_doubled() {
    if (elems.size() % 2) {
      return *median * 2;
    }
    auto upper_median = median;
    upper_median++;
    return *upper_median + *median;
  }
};

int activityNotifications(std::vector<int> expenditure, int d) {
  MedianTree tree;
  int total = 0;

  for (int i = 0; i < expenditure.size(); i++) {
    int x = expenditure[i];

    if (i >= d) {
      int median = tree.get_median_doubled();
      if (x >= median)
        total++;
      tree.remove(expenditure[i - d]);
    }

    tree.insert(x);
  }
  return total;
}

int main() {
  std::cout << activityNotifications({1, 2, 3, 4, 4}, 4) << std::endl;
  return 0;
}
