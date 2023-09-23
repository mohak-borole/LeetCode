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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        ListNode* tail = result;
        int carry = 0;
        while(l1 || l2 || carry     )
        {
            int sum = carry;
            sum += (l1 != NULL) ? l1->val:0;
            sum += (l2 != NULL) ? l2->val:0;

            l1 = (l1 != NULL)? l1->next:NULL;
            l2 = (l2 != NULL)? l2->next:NULL;

            carry = sum/10;
            sum = sum%10;

            tail->next = new ListNode(sum);

            tail = tail->next;
        }

        return result->next;
    }
};