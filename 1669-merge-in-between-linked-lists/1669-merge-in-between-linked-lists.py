# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        parent = None
        current = list1
        
        if current == None:
            return list2
        else:
            for i in range(0 , a):
                parent = current
                current = current.next
            
            parent.next = list2
            
            while parent.next != None:
                parent = parent.next
                
            for i in range(a , b):
                current = current.next
                
            parent.next = current.next
            
            return list1
                