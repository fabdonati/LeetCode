# Share
# Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

# Example:

# Input:
# [
#   1->4->5,
#   1->3->4,
#   2->6
# ]
# Output: 1->1->2->3->4->4->5->6

class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next
class Solution:
  def mergeKLists(self, lists: List[ListNode]) -> ListNode:
    self.nodes = []
    head = point = ListNode(0)
    for l in lists:
      while l:
        self.nodes.append(l.val)
        l = l.next
    for x in sorted(self.nodes):
      point.next = ListNode(x)
      point = point.next
    return head.next
    
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
      root = n = ListNode(0)
      while l1 and l2:
        if l1.val < l2.val:
          n.next = l1
          l1 = l1.next
        else:
          n.next = l2
          l2 = l2.next
        n = n.next
      n.next = l1 or l2
    return root.next 

    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
      amount = len(lists)
      interval = 1
      while interval < amount:
        for i in range(0, amount - interval, interval*2):
          lists[i] = self.mergeTwoLists(lists[i], lists[i+interval])
        interval *= 2
      return lists[0] if amount > 0 else lists



        