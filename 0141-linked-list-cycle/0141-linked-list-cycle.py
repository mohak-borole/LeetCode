# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        fast = head # Initialize fast pointer to head
        slow = head # Initialize slow pointer to head
        while fast and fast.next: # Traverse the list until fast pointer reaches end or NULL
            fast = fast.next.next # Move fast pointer two steps ahead
            slow = slow.next # Move slow pointer one step ahead
            if fast == slow: # If fast meets slow, there is a cycle
                return True
        return False # If fast reaches NULL, there is no cycle