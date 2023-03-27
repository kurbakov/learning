#include <iostream>

/*
    Implementation of:
    https://leetcode.com/problems/middle-of-the-linked-list/

    Runtime 0 ms Beats 100%
    Memory 7 MB Beats 98%
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
  ListNode* middleNode(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
      return head;

    auto slow = head;
    auto fast = head->next;

    while (fast != nullptr) {
      slow = slow->next;
      fast = fast->next;
      if (fast != nullptr)
        fast = fast->next;
    }

    return slow;
  }
};

int main(int argc, char* argv[]) {
  std::cout << "hello 0141" << std::endl;
  return 0;
}
