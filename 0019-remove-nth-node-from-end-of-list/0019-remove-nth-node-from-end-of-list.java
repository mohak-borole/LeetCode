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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int length = 0;
        ListNode curr = head;
        
        // Find the length of the linked list
        while (curr != null) {
            length++;
            curr = curr.next;
        }
        
        int traverseTill = length - n - 1;
        curr = head;
        
        // Traverse to the node before the one to be removed
        for (int i = 0; i < traverseTill; i++) {
            curr = curr.next;
        }
        
        // Remove the nth node from the end
        if (traverseTill == -1) {
            return head.next;
        } else {
            curr.next = curr.next.next;
            return head;
        }
    }
}