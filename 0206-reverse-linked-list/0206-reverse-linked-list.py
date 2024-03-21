# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head  # Handle empty or single-node list
        
        rev = []
        
        curr = head
        while curr is not None:
            rev.append(curr)
            curr = curr.next
        
        head1 = rev[-1]
        revHead = rev[-1]
        rev.pop()
        
        while rev:
            revHead.next = rev[-1]
            revHead = revHead.next
            rev.pop()
        
        # Terminate the reversed list properly
        revHead.next = None
        
        return head1