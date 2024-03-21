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
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) {
            return head; // Handle empty or single-node list
        }
        
        Stack<ListNode> rev = new Stack<>();
        
        ListNode curr = head;
        while (curr != null) {
            rev.push(curr);
            curr = curr.next;
        }
        
        ListNode head1 = rev.peek();
        ListNode revHead = rev.peek();
        rev.pop();
        
        while (!rev.empty()) {
            revHead.next = rev.peek();
            revHead = revHead.next;
            rev.pop();
        }
        
        // Terminate the reversed list properly
        revHead.next = null;
        
        return head1;
    }
}