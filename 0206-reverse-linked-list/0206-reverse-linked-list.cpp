/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; // Handle empty or single-node list
        }
        
        stack<ListNode*> rev;
        
        ListNode *curr = head;
        while(curr != NULL) {
            rev.push(curr);
            curr = curr->next;
        }
        
        ListNode* head1 = rev.top();
        ListNode* revHead = rev.top();
        rev.pop();
        
        while(!rev.empty()){
            revHead->next = rev.top();
            revHead = revHead->next;
            rev.pop();
        }
        
        // Terminate the reversed list properly
        revHead->next = nullptr;
        
        return head1;
    }
};