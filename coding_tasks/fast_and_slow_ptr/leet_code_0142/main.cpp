#include <iostream>

/*
    Implementation of:
    https://leetcode.com/problems/linked-list-cycle-ii/

    Runtime 4 ms Beats 96.9%
    Memory 7.6 MB Beats 68.19%
*/

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* detectCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
      return nullptr;

    auto first = head;
    auto second = head;
    while (second != nullptr && second->next != nullptr) {
      first = first->next;
      second = second->next->next;

      if (first == second) {
        break;
      }
    }

    if (!(first == second)) {
      return nullptr;
    }

    first = head;
    while (first != second) {
      first = first->next;
      second = second->next;
    }

    return first;
  }
};

int main(int argc, char* argv[]) {
  std::cout << "hello 0142" << std::endl;
  return 0;
}
