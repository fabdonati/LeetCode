/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

#include <iostream>
#include <math.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
      int result1 = 0, result2 = 0;
      int l1dec = 0, l2dec = 0;
      while(l1!=nullptr) {
        result1 += l1->val*pow(10, l1dec);
        l1 = l1->next;
        l1dec++;
      }
      while(l2!=nullptr) {
        result2 += l2->val*pow(10, l2dec);
        l2 = l2->next;
        l2dec++;
      }
      int result = result1 + result2;
      ListNode* head = new ListNode(result%10);
      ListNode* p = new ListNode();
      p = head;
      result /= 10;
      while (result > 0) {
        ListNode* n = new ListNode(result%10);
        p->next = n;
        p = p->next;
        result /= 10;
      }
      return head;
    } 
}