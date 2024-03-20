/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode parent = null;
        ListNode current = list1;
        
        if(current == null) {
            return list2;
        }
        else {
            
            for(int i = 0 ; i < a; i++) {
                parent = current;
                current = current.next;
            }
            
            parent.next = list2;
            while(parent.next != null)
            {   parent = parent.next;}
            
            for(int i = a; i < b ; i++) {
                current = current.next;
            }
            
            parent.next = current.next;
            
            return list1;
        }
    }
}